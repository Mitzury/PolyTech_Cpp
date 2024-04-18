#include <cstring>
#include <sstream>
#pragma once

template<typename T>
class List {
private:

    bool is_deleted = false;
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& data) : next(nullptr), data(data) {}
    };
    Node* head;
    Node* tail;

public:
  
    List() : head(nullptr) {}
    List(List&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
    }

    List& operator=(List&& other) {
        if (this != &other) {

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }


    List& operator=(const List& other) {
        if (this != &other) {
          
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;

            current = other.head;
            while (current != nullptr) {
                AddToTail(current->data);
                current = current->next;
            }
        }
        return *this;
    }


    void AddToTail(const T& data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    T GetLast() {
        return tail->data;
    }

    void RemoveLast() {
        Node* tmp = head;
        while (tmp->next != tail)
            tmp = tmp->next;
        tail = tmp;
        tmp = tail->next;
        tail->next = nullptr;

        delete tmp;
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
        Node* current = list.head;
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
        Node* current = head;
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }
        tail = nullptr;
        head = nullptr;
    }

    bool empty() const {
        return head == nullptr;
    }
    ~List() {
        if (!is_deleted) {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            is_deleted = true;
        }
    }
};