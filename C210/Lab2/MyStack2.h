#include <cstring>
#include <sstream>

// Класс MyStack2
template <typename T>
class MyStack2 {
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

private:
    template<typename T>
    class List {
    private:
        bool is_deleted = false;
        class Node {
        public:
            T data;
            Node* next;
            Node(const T& data) : next(nullptr), data(data) {}
            Node() : next(nullptr), data(nullptr) {}
        };
        Node head;

    public:
        List() {
            head = Node();
        }
        List(List&& other) : head(other.head) {
            other.head = Node();
        }
        List& operator=(List&& other) {
            if (this != &other) {
                clear();
                head = other.head;
                other.head = Node();
            }
            return *this;
        }
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
        void AddToTail(const T& data) {
            Node* newNode = new Node(data);
            if (head.next == nullptr) {
                head.next = newNode;
            }
            else {
                Node* current = head.next;
                while (current->next != nullptr)
                    current = current->next;
                current->next = newNode;
            }
        }

        T GetLast() {
            Node* current = head.next;
            while (current->next != nullptr)
                current = current->next;
            return current->data;
        }

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

        List(const List& other) {
            clear();
            Node* current = other.head;
            while (current != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const List& list) {
            Node* current = list.head.next;
            while (current != nullptr) {
                os << current->data << ' ';
                current = current->next;
            }
            os << std::endl;
            return os;
        }

        friend std::istream& operator>>(std::istream& is, List& list) {
            std::string str;
            while (std::getline(is, str)) {
                T c = T(str);
                list.AddToTail(c);
            }
            return is;
        }

        void clear() {
            Node* current = head.next;
            while (current != nullptr) {
                Node* tmp = current;
                current = current->next;
                delete tmp;
            }

            head.next = nullptr;
        }

        bool empty() const {
            return head.next == nullptr;
        }

        ~List() {
            if (!is_deleted) {
                clear();
                is_deleted = true;
            }
        }
    };

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