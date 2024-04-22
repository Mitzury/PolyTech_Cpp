#include <cstring>
#include <sstream>

// Класс MyStack2

template <typename T>
class MyStack2 {
private:
    template<typename T>
    class List {
    private:
        bool is_deleted = false;
        // Вложенный класс node для представления элемента списка
        class Node {
        public:
            T data;
            // указатель на следующий элемент
            Node* next;
            // конструктор с параметром
            Node(const T& data) : next(nullptr), data(data) {}
            // конструктор без параметров
            Node() : next(nullptr), data(nullptr) {}
        };
        // головной узел списка
        Node head;
    public:
        // Конструктор по умолчанию
        List() {
            head = Node();
        }
        // Конструктор перемещения
        List(List&& other) : head(other.head) {
            other.head = Node();
        }
        // Оператор перемещения
        List& operator=(List&& other) {
            if (this != &other) {
                clear();
                head = other.head;
                other.head = Node();
            }
            return *this;
        }
        // Оператор копирования
        List& operator=(const List& other) {
            if (this != &other) {
                clear();
                Node* current = other.head.next;
                while (current != nullptr) {
                    AddToTail(current->data);
                    current = current->next;
                }
            }
            return *this;
        }
        // Метод для добавления элемента в конец списка
        void AddToTail(const T& data) {
            Node* newNode = new Node(data);
            if (head.next == nullptr) {
                head.next = newNode;
            } else {
                Node* current = head.next;
                while (current->next != nullptr)
                    current = current->next;
                current->next = newNode;
            }
        }
        // Метод для получения последнего элемента списка
        T GetLast() {
            Node* current = head.next;
            while (current->next != nullptr)
                current = current->next;
            return current->data;
        }
        // Метод для удаления последнего элемента списка
        void RemoveLast() {
            if (head.next != nullptr)
            {
                Node* current = head.next;
                while (current->next->next != nullptr)
                    current = current->next;
                Node* tmp = current->next;
                current->next = nullptr;
                delete tmp;
            }
        }
        // Конструктор копирования
        List(const List& other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
        // Перегрузка оператора вывода в поток для списка
        friend std::ostream& operator<<(std::ostream& os, const List& list) {
            Node* current = list.head.next;
            while (current != nullptr) {
                os << current->data << ' ';
                current = current->next;
            }
            os << std::endl;
            return os;
        }
        // Перегрузка оператора ввода из потока для списка
        friend std::istream& operator>>(std::istream& is, List& list) {
            std::string str;
            while (std::getline(is, str)) {
                T c = T(str);
                list.AddToTail(c);
            }
            return is;
        }
        // Метод для очистки списка
        void clear() {
            Node* current = head.next;
            while (current != nullptr) {
                Node* tmp = current;
                current = current->next;
                delete tmp;
            }
            head.next = nullptr;
        }
        // Метод для проверки, пуст ли список
        bool empty() const {
            return head.next == nullptr;
        }
        // Деструктор
        ~List() {
            if (!is_deleted) {
                clear();
                is_deleted = true;
            }
        }
    };

public:
    MyStack2() {
        m_data = List<T>();
    }
    MyStack2(MyStack2&& other) {
        m_data = std::move(other.m_data);
    }
    MyStack2& operator=(MyStack2&& other) {
        m_data = std::move(other.m_data);
        return *this;
    }
    MyStack2(const MyStack2& other) {
        m_data = other.m_data;
    }
    ~MyStack2() {
        m_data.~List();
    }
    // Метод для добавления в стэк
    void push(const T& value) {
        m_data.AddToTail(value);
    }
    // Метод для получения объекта из стэка
    T pop() {
        if (m_data.empty()) {
            throw std::underflow_error("Exception: Stack is empty");
        }
        T result = m_data.GetLast();
        m_data.RemoveLast();
        return result;
    }
    // Метод для определения наполненности стэка
    bool empty() const {
        return m_data.empty();
    }
    MyStack2<T>& operator=(const MyStack2<T>& other) {
        if (this != &other) {
            m_data.clear();
            m_data = other.m_data;
        }
        return *this;
    }

    List<T> m_data;

    // Перегрузка оператора << для вывода значений в поток
    friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack) {
        if (stack.empty())
        {
            os << "MyStack2 is empty\n";
            return os;
        }
        os << stack.m_data;
        return os;
    }

    // Перегрузка оператора >> для ввода значений из потока
    friend std::istream& operator>>(std::istream& is, MyStack2<T>& stack) {
        T value;
        while (is >> value) {
            stack.push(value);
        }
        return is;
    }
};