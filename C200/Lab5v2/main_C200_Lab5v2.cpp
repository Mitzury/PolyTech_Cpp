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
    List() : head(Circle()), tail(Circle()) {
        this->head.next = &this->tail;
        this->tail.prev = &this->head;
    }

    void AddToTail(const Circle& data) {
        Node* newNode = new Node{ data };

        newNode->prev = tail.prev;
        newNode->next = &tail;
        tail.prev->next = newNode;
        tail.prev = newNode;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        Node* curr = list.head.next;
        os << list.head.prev << std::endl;
        os << &list.head << std::endl;
        os << list.head.next << std::endl;
        while (curr != &list.tail) {
            os << curr->prev << " " << curr->data.Center.X << ", " << curr->data.Center.Y << ", " << curr->data.Radius << " " << curr->next << std::endl;
            curr = curr->next;
        }
        os << &list.tail << std::endl;
        os << list.tail.prev << std::endl;
        os << list.tail.next << std::endl;

        return os;
    }
};



int main() {
    List ls1;
    ls1.AddToTail(Circle(2, 2, 2));
    ls1.AddToTail(Circle(3, 3, 3));
    std::cout << ls1;
}
