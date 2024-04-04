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
        Node(const Shape* value, Node* n) {
            Node* tmp = n->next;
            prev = n;
            next = tmp;
            n->next = this;
            tmp->prev = this;
            data = value->clone();
        }

        ~Node() {
            delete data;
        }
        friend std::ostream& operator<<(std::ostream& ost, Node& n) {
            ost << n.data;
            return ost;
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

    void AddToHead(Circle& value) {
        new Node(&value, &head);
        m_size++;
    }

    void AddToTail(const Shape& value) {
        new Node(&value, tail.prev);
        m_size++;
    }

    friend std::ostream& operator<<(std::ostream& ost, const List& l) {
        Node* current = l.head.next;
        while (current->next != nullptr) {
            ost << current->data << std::endl;
            current = current->next;
        }
        return ost;

    }

};
const char* sep = "------------------------------------\n";

int main() {

    List ls1;

    ls1.AddToTail(Circle(2, 2, 2, Shape::RED));
    ls1.AddToTail(Rect(2, 2, 2, 2, Shape::RED));




    std::cout << "Out List 1" << std::endl << ls1 << sep;


    return 0;
};