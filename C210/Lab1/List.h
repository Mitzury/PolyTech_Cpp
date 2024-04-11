#include <fstream>
#include <vector>
#include <string>



// enum � ������ ����������
enum SortType { AREA, COLOR /* .... */ };

class List {
private:
    // �����, ������������ �� ������ ������ enum Color
    Shape::Color parseStringToEnum(const std::string& str) {
        if (str == "RED") {
            return Shape::RED;
        }
        else if (str == "GREEN") {
            return Shape::GREEN;
        }

        // ���� ������ �� ������������� �� ������ �� �������� enum,
        // ���������� �������� �� ���������
        return Shape::WHITE;
    }

    // ����� �������������� ������ � int
    int string_to_int(const std::string& s)
    {
        std::istringstream i(s);
        int x;
        if (!(i >> x))
            return 0;
        return x;
    };
    // ����� ���� ��� ������
    class Node {
    public:
        Shape* data;
        Node* next;
        Node* prev;

        // �����������
        Node(Shape* shape) : data(shape), next(nullptr), prev(nullptr) {}
        Node() : data(nullptr), next(nullptr), prev(nullptr) {}
    };

    Node head;
    Node tail;

public:
    // �����������
    List() : head(Node()), tail(Node()) {
        head.next = &tail;
        tail.prev = &head;
    }

    // ����� ���������� �������� � ����� ������
    void AddToTail(Shape* shape) {
        Shape* newShape = shape->Clone();
        Node* newNode = new Node(newShape);
        if (head.next->data == nullptr) {
            head.next = newNode;
            tail.prev = newNode;
            newNode->prev = &head;
            newNode->next = &tail;
        }
        else {
            newNode->next = &tail;
            newNode->prev = tail.prev;
            tail.prev->next = newNode;
            tail.prev = newNode;
        }
    }

    // ����� ���������� �������� � ������ ������
    void AddToHead(Shape* shape) {
        Shape* newShape = shape->Clone();
        Node* newNode = new Node(newShape);
        if (head.next->data == nullptr) {
            head.next = newNode;
            tail.prev = newNode;
            newNode->next = &tail;
            newNode->prev = &head;
        }
        else {
            newNode->next = head.next;
            newNode->prev = &head;
            head.next->prev = newNode;
            head.next = newNode;
        }
    }

    // ����� �������� �������, ������������ � ���������
    void Remove(Shape* shape) {
        Node* current = head.next;
        while (current->data != nullptr) {
            if (shape->Equals(current->data)) {
                if (current == head.next) {
                    head.next = current->next;
                    current->next->prev = &head;
                }
                else if (current == tail.prev) {
                    tail.prev = current->prev;
                    current->prev->next = &tail;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                current = nullptr;
                break;
            }
            current = current->next;
        }
    }

    // ����� �������� ���� ��������, ����������� � ���������
    void RemoveAll(Shape* shape) {
        Node* current = head.next;
        while (current->data != nullptr) {
            Node* temp = current;
            current = current->next;
            if (shape->Equals(temp->data)) {
                if (temp == head.next) {
                    head.next = temp->next;
                    temp->next->prev = &head;
                }
                else if (temp == tail.prev) {
                    tail.prev = temp->prev;
                    temp->prev->next = &tail;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                temp = nullptr;
            }
        }
    }

    // ����� ���������� ������, ��������� � ���� �������� �� �������� ������ ����� �������������
    void SortList(SortType sortType) {
        if (head.next->data == nullptr || head.next == tail.prev)
            return;

        Node* current;
        bool swapped;

        do {
            swapped = false;
            current = head.next;

            while (current->next->data != nullptr) {
                if (sortType == AREA) {
                    if (current->data->calculateArea() > current->next->data->calculateArea()) {
                        Shape* tempData = current->data;
                        current->data = current->next->data;
                        current->next->data = tempData;
                        swapped = true;
                    }
                }
                else if (sortType == SortType::COLOR) {
                    if (current->data->getColor() > current->next->data->getColor()) {
                        Shape* tempData = current->data;
                        current->data = current->next->data;
                        current->next->data = tempData;
                        swapped = true;
                    }
                }
                current = current->next;
            }

        } while (swapped);
    }

    // ���������� ��������� ������ ����������� ������
    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.head.next;
        if (current->data == nullptr)
            os << "List is Empty\n";
        while (current->data != nullptr) {
            os << current->data->toString();
            current = current->next;
        }
        return os;
    }

    // ����������� �����������
    List(List&& other) : head(other.head), tail(other.tail) {

        other.head = Node();
        other.tail = Node();
        other.head.next = &(other.tail);
        other.tail.prev = &(other.head);
    }

    // ����������� ����������� 
    List(const List& other) {
        if (this != &other) {
            Node* current = head.next;

            if (head.next != nullptr)
            {
                while (current->data != nullptr) {
                    Node* temp = current;
                    current = current->next;
                    temp = nullptr;
                }
            }

            head.next = &tail;
            tail.prev = &head;

            current = other.head.next;
            // �������� ������ �� ������� ������
            while (current->data != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
    }


    // �������� ������������ ����������� 
    List& operator=(const List& other) {
        if (this != &other) {
            // ������� ������� ������
            Node* current = head.next;

            if (head.next != nullptr) {
                while (current->data != nullptr) {
                    Node* temp = current;
                    current = current->next;
                    temp = nullptr;
                }
            }

            head.next = &tail;
            tail.prev = &head;

            // �������� ������ �� ������� ������
            current = other.head.next;
            while (current->data != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // �������� ������������ ����������� 
    List& operator=(List&& other) {
        if (this != &other) {
            // ������� ������� ������
            Node* current = head.next;
            while (current->data != nullptr) {
                Node* temp = current;
                current = current->next;
                temp = nullptr;
            }
            // ���������� ������ �� ������� ������
            head = other.head;
            tail = other.tail;
            other.head = Node();
            other.tail = Node();
            other.head.next = &(other.tail);
            other.tail.prev = &(other.head);
        }
        return *this;
    }

    // ���������� ��������� ������ �� ��������� ������
    friend List operator>>(std::ifstream& ifs, List& list) {
        std::string line;
        while (std::getline(ifs, line)) {
            char separator = ' ';
            int j = 0;
            std::string s;
            std::string tokens[13];
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != separator) {
                    s += line[i];
                }
                else {
                    tokens[j] = s;
                    j++;
                    s.clear();
                }
            }
            tokens[j] = s;
            s.clear();
            if (tokens[0] == "Circle:")
            {
                list.AddToTail(Circle(
                    list.string_to_int(tokens[2]),
                    list.string_to_int(tokens[4]),
                    list.string_to_int(tokens[6]),
                    list.parseStringToEnum(tokens[8])));
            }
            if (tokens[0] == "Rectangle:") {
                Rect rect = Rect(
                    list.string_to_int(tokens[2]),
                    list.string_to_int(tokens[4]),
                    list.string_to_int(tokens[6]),
                    list.string_to_int(tokens[8]),
                    list.parseStringToEnum(tokens[10]));

                list.AddToTail(rect);
            }
        }
        return list;
    }

    // �������������
    ~List() {
        Node* current = &head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            temp = nullptr;
        }
    }
};