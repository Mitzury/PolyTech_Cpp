#include <iostream>

class Point {
public:
    int X;
    int Y;
public:
    Point(int xCoord = 0, int yCoord = 0)
    {
        X = xCoord;
        Y = yCoord;
    }
};

class Circle {
public:
    Point Center;
    int Radius;
public:
    Circle() : Center(0, 0), Radius(0) {}
    Circle(int xCoord, int yCoord, int radius) : Center(xCoord, yCoord) {
        this->Radius = radius;
    }

};

class List {
private:
    class Node {
    public:
        Circle data;
        Node* prev;
        Node* next;
        Node() : next(nullptr), prev(nullptr) {}
        Node(const Circle& data) : data(data), next(nullptr), prev(nullptr) {}
    };
    Node head;
    Node tail;

public:
    // constructor
    List() {
        head.next = &tail;
        tail.prev = &head;
    }

    void insert_at_tail(const Circle& newData) {
        if (head.next == &tail) {
            Node* newNode = new Node(newData);
            newNode->next = &tail;
            tail.prev = newNode;
            head.next = newNode;
            newNode->prev = &head;
        }
        else {
            Node* newNode = new Node(newData);
            tail.prev->next = newNode;
            newNode->prev = tail.prev;
            newNode->next = &tail;
            tail.prev = newNode;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const List& list) {
        for (Node* node = list.head.next; node != &list.tail; node = node->next) {
            out << "&Head prev: " << list.head.prev << "\n";
            out << "&Head: " << &list.head << "\n";
            out << "&Head->next: " << list.head.next << "\n";
            out << "&Node: " << node << "\n";
            out << "&Node->prev: " << node->prev << "\n";
            out << "&Node->next: " << node->next << "\n";
            out << "&Tail: " << &list.tail << "\n";
            out << "&Tail->prev: " << list.tail.prev << "\n";
            out << "&Tail next: " << list.tail.next << "\n";
            out << "{Center: " << node->data.Center.X << "," << node->data.Center.Y << "," << node->data.Radius << "}\n\n";
        }
        return out;
    }

};

int main() {
    List ls1;
    ls1.insert_at_tail(Circle(2, 2, 2));
    ls1.insert_at_tail(Circle(3, 3, 3));
    std::cout << ls1;
}
