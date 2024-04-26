#include <cstring>
#include <sstream>

// Класс MyStack2
template <typename T>
class MyStack2 {
public:

    MyStack2() {
        head = Node();
    }

    MyStack2(MyStack2&& other) : head(std::move(other.head)) {
        other.head = Node();
    }

    MyStack2& operator=(MyStack2&& other) {
        if (this != &other) {
            clear();

            head = std::move(other.head);
            other.head = Node();
        }
        return *this;
    }

    MyStack2(const MyStack2<T>& other) {
        clear();
        head = Node();
        Node* current = other.head.next;
        while (current != nullptr) {
            AddToTail(current->data);
            current = current->next;
        }
    }

    ~MyStack2() {
        if (!is_deleted) {
            clear();
            is_deleted = true;
        }
    }

    // Метод для добавления в стэк
    void push(const T& value) {
        AddToTail(value);
    }

    // Метод для получения объекта из стэка
    T pop() {
        if (empty()) {
            throw std::underflow_error("Exception: Stack is empty");
        }
        T result = GetLast();
        RemoveLast();
        return result;
    }

    // Метод для определения наполненности стэка
    bool empty() const {
        return head.next == nullptr;
    }

    MyStack2<T>& operator=(const MyStack2<T>& other) {
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

    void clear() {
        Node* current = head.next;
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }

        head.next = nullptr;
    }

    // Перегрузка оператора << для вывода значений в поток
    friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& stack) {
        if (stack.empty())
        {
            os << "MyStack2 is empty\n";
            return os;
        }

        Node* current = stack.head.next;
        while (current != nullptr) {
            os << current->data << ' ';
            current = current->next;
        }
        os << std::endl;
        return os;
    }

    // Перегрузка оператора >> для ввода значений из потока
    friend std::istream& operator>>(std::istream& is, MyStack2<T>& stack) {
        std::string str;
        while (std::getline(is, str)) {
            T c = T(str);
            stack.AddToTail(c);
        }
        return is;
    }
};