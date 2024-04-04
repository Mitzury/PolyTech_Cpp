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
    friend std::ostream& operator << (std::ostream& os, const Point& p) {
        os << p.X << "," << p.Y;
        return os;
    }
    friend bool operator==(const Point& p1, const Point& p2) {
        return p1.X == p2.X && p1.Y == p2.Y;
    }
};
class Shape {
public:
    enum Color { WHITE, RED, GREEN };

    virtual Shape* clone() const { return nullptr; }

};

class Circle : public Shape {
public:
    Point Center;
    int Radius;
    Color color;
public:
    Circle() : Center(0, 0), Radius(0) {}
    Circle(int xCoord, int yCoord, int radius, Color) : Center(xCoord, yCoord) {
        this->Radius = radius;
    }

    Shape* clone() const override {
        return new Circle(*this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) {
        os << "Circle (" << c.Center << "," << c.Radius << ")";
        return os;
    }
    friend bool operator==(const Circle& c1, const Circle& c2) {
        return c1.Center == c2.Center && c1.Radius == c2.Radius;
    }
};
class Rect : public Shape {
public:
    int X;
    int Y;
    int Width;
    int Height;
    Color color;

    Rect(int xCoord = 0, int yCoord = 0, int width = 0, int height = 0, Color col = WHITE)
        : X(xCoord), Y(yCoord), Width(width), Height(height), color(col) {}

    Shape* clone() const override {
        return new Rect(*this);
    }

};
class List {
private:
    class Node {
    public:
        Shape* data;
        Node* prev;
        Node* next;
        Node() : next(nullptr), prev(nullptr) {}
        Node(Shape* data) : data(data), next(nullptr), prev(nullptr) {}

        ~Node() {
            delete data;
        }

    };
    Node head;
    Node tail;
    size_t m_size;
public:
    List() : head(), tail(), m_size(0) {
        this->head.next = &this->tail;
        this->tail.prev = &this->head;
    }

    void AddToTail(Shape* data) {
        Node* newNode = new Node{ data };
        newNode->prev = tail.prev;
        newNode->next = &tail;
        tail.prev->next = newNode;
        tail.prev = newNode;
        m_size++;
    }
    void AddToHead(Shape* data) {
        Node* newNode = new Node{ data };
        newNode->next = head.next;
        newNode->prev = &head;
        head.next->prev = newNode;
        head.next = newNode;
        m_size++;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        Node* curr = list.head.next;
        os << "List size: " << list.m_size;
        while (curr != &list.tail) {
            os << std::endl << "\t" << curr->data;
            curr = curr->next;
        }
        os << std::endl;
        return os;
    }
};
const char* sep = "------------------------------------\n";

int main() {

    List ls1;
    ls1.AddToTail(new Circle(2, 2, 2, Shape::RED));
    ls1.AddToTail(new Rect(2, 2, 2,2, Shape::RED));




    std::cout << "Out List 1" << std::endl << ls1 << sep;


    return 0;
};