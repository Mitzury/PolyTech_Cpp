#pragma once
#include <fstream>
#include <vector>
#include <string>

// ����� ���� ��� ������
class Node {
public:
    Shape* data;
    Node* next;
    Node* prev;

    // �����������
    Node(Shape* shape) : data(shape), next(nullptr), prev(nullptr) {}
};

// enum � ������ ����������
enum SortType { AREA, COLOR /* .... */ };

class List {
private:
    Node* head;
    Node* tail;
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

public:
    // �����������
    List() : head(nullptr), tail(nullptr) {}

    // ����� ���������� �������� � ����� ������
    void AddToTail(Shape* shape) {
        Shape* newShape = shape->Clone();
        Node* newNode = new Node(newShape);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // ����� ���������� �������� � ������ ������
    void AddToHead(Shape* shape) {
        Shape* newShape = shape->Clone();
        Node* newNode = new Node(newShape);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // ����� �������� �������, ������������ � ���������
    void Remove(Shape* shape) {
        Node* current = head;
        while (current != nullptr) {
            if (shape->Equals(current->data)) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                break;
            }
            current = current->next;
        }
    }

    // ����� �������� ���� ��������, ����������� � ���������
    void RemoveAll(Shape* shape) {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            if (shape->Equals(temp->data)) {
                if (temp == head) {
                    head = temp->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else if (temp == tail) {
                    tail = temp->prev;
                    if (tail != nullptr)
                        tail->next = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
        }
    }

    // ����� ���������� ������, ��������� � ���� �������� �� �������� ������ ����� �������������
    void SortList(SortType sortType) {
        if (head == nullptr || head == tail)
            return;

        Node* current;
        Node* temp = nullptr;
        bool swapped;

        do {
            swapped = false;
            current = head;

            while (current->next != temp) {
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
            temp = current;

        } while (swapped);
    }

    // ���������� ��������� ������ ����������� ������
    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        Node* current = list.head;
        if (current == nullptr)
            os << "List is Empty\n";
        while (current != nullptr) {
            try
            {
                os << current->data->toString();
                current = current->next;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }

        }
        return os;
    }

    // ����������� �����������
    List(List&& other) : head(other.head), tail(other.tail) {

        other.head = nullptr;
        other.tail = nullptr;
    }

    // ����������� ����������� 
    List(const List& other) {
        if (this != &other) {
            Node* current = head;
            head = nullptr;
            tail = nullptr;

            // �������� ������ �� ������� ������
            current = other.head;
            while (current != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
    }

    // �������� ������������ ����������� 
    List& operator=(const List& other) {
        if (this != &other) {
            // ������� ������� ������
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            // �������� ������ �� ������� ������
            current = other.head;
            while (current != nullptr) {
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
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            // ���������� ������ �� ������� ������
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }

    // ���������� ��������� ������ �� ��������� ������
    friend List operator>>(std::ifstream& ifs, List& list) {
        std::string line;
        List result;
        while (std::getline(ifs, line)) {
            char separator = ' ';
            std::string s;
            std::vector<std::string> tokens;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != separator) {
                    s += line[i];
                }
                else {
                    tokens.push_back(s);
                    s.clear();
                }
            }
            tokens.push_back(s);
            s.clear();
            if (tokens[0] == "Circle:")
            {
                result.AddToTail(Circle(
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

                result.AddToTail(rect);
            }
            tokens.clear();
        }
        list = std::move(result);
        return list;
    }

    // �������������
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};