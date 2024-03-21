#include "List.h"

//�������� ������������ �����������
// ������������ ��� �����������(move) ����������� ������ ������� ������ � ������.
List& List::operator=(List&& other) {
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

List::List(const List& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        AddToTail(current->data);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
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
    } return *this;
}

void List::AddToTail(const Circle& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void List::AddToHead(const Circle& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void List::Remove(const Circle& data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
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

// ������� ��� �������� ���� �����, ���� ������� ��������� � �������� ���������
void List::RemoveAll(const Circle& data) {
// ���� ������ ������, �� ������� �� �������
    if (head == nullptr) {
        return;
    }
// ������������� ������� ���� �� ������ ������
    Node* current = head;
    while (current != nullptr) {
// ������� ��������� ��������� �� ������� ����
        Node* temp = current;
        current = current->next;
// ���������, ��������� �� �������� ���� ���� � �������� ���������
        if (temp->data == data) {
// ���������, �������� �� ������� ���� ������� ������
            if (temp == head) {
// ����������������� ������ ������ � ��������� ���������
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
// ��������������� ������ ����� � ����� ��������
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }
}

void List::SortList() {
    // Bubble sort
    if (head == nullptr || head == tail)
        return;
    Node* current;
    Node* temp = nullptr;
    bool swapped;
    do {
        swapped = false;
        current = head;
        while (current->next != temp) {
            if (current->data.getSquare() > current->next->data.getSquare()) {
                Circle tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = true;
            }
            current = current->next;
        } temp = current;
    } while (swapped);
}

List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    Node* current = list.head;
    while (current != nullptr) {
        os << current->data << endl;
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, List& list) {
    std::string str;
    int x, y, radius;
    while (std::getline(is, str)) {
        sscanf(str.c_str(), "Circle (%d,%d,%d)", &x, &y, &radius);
        Circle c = Circle(x, y, radius);
        list.AddToTail(c);
    }
    return is;
}
