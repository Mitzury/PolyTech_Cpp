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
    // переопределение оператора ==, сравнивает точки по координатам
    friend bool operator==(const Point& p1, const Point& p2) {
        return p1.X == p2.X && p1.Y == p2.Y;
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
    friend bool operator==(const Circle& c1, const Circle& c2) {
        // Если центры и радиусы окружностей совпадают, функция возвращает "true", иначе - "false".
        return c1.Center == c2.Center && c1.Radius == c2.Radius;
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
    void InsertBefore(const Circle& newData, const Circle& data) {
        Node* newNode = new Node(newData);
        Node* curr = head.next;
        while (curr != nullptr) {
            if (curr->data == data) {
                newNode->prev = curr->prev;
                newNode->next = curr;
                if (curr->prev != nullptr) {
                    curr->prev->next = newNode;
                }
                curr->prev = newNode;
                return;
            }
            curr = curr->next;
        } AddToHead(newData);
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list)
    {
        Node* curr = list.head.next;
        while (curr != &list.tail) {
            os << curr->prev << " " << curr->data << " " << curr->next << std::endl;
            curr = curr->next;
        }
        return os;
    }
};

int main() {
    List ls1;
    ls1.AddToTail(Circle(2, 2, 2));
    ls1.AddToTail(Circle(3, 3, 3));
    ls1.AddToTail(Circle(9, 9, 9));
    ls1.AddToHead(Circle(90, 90, 90));
    ls1.InsertBefore(Circle(2, 2, 8), (Circle(9, 9, 9)));
    std::cout << ls1;

    return 0;
};