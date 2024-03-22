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
    // перегрузка оператора вывода объекта в консоль
    friend std::ostream& operator << (std::ostream& os, const Point& p) {
        os << p.X << "," << p.Y;
        return os;
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

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) {
        os << "Circle (" << c.Center << "," << c.Radius << ")";
        return os;
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
    void AddToHead(const Circle& data) {
        Node* newNode = new Node{ data };
        newNode->next = head.next;
        newNode->prev = &head;
        head.next->prev = newNode;
        head.next = newNode;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        Node* curr = list.head.next;
        os << list.head.prev << std::endl;
        os << &list.head << std::endl;
        os << list.head.next << std::endl;
        while (curr != &list.tail) {
            os << curr->prev << " " << curr->data << " " << curr->next << std::endl;
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
    ls1.AddToTail(Circle(9, 9, 9));
    ls1.AddToHead(Circle(90, 90, 90));
    std::cout << ls1;

    return 0;
};