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
    size_t m_size;
public:
    List() : head(Circle()), tail(Circle()), m_size(0) {
        this->head.next = &this->tail;
        this->tail.prev = &this->head;
    }

    void AddToTail(const Circle& data) {
        Node* newNode = new Node{ data };
        newNode->prev = tail.prev;
        newNode->next = &tail;
        tail.prev->next = newNode;
        tail.prev = newNode;
        m_size++;
    }
    void AddToHead(const Circle& data) {
        Node* newNode = new Node{ data };
        newNode->next = head.next;
        newNode->prev = &head;
        head.next->prev = newNode;
        head.next = newNode;
        m_size++;
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
        os << "List size: ";
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
    ls1.AddToTail(Circle(2, 2, 2));
    ls1.AddToTail(Circle(3, 3, 3));
    ls1.AddToTail(Circle(9, 9, 9));
    ls1.AddToHead(Circle(90, 90, 90));


    std::cout << "Out List 1" << std::endl << ls1 << sep;
    ls1.InsertBefore(Circle(2, 2, 8), (Circle(9, 9, 9)));
    std::cout << "Out List 1 after add 2.2.8 before 9.9.9 (have's)" << std::endl << ls1 << sep;
    ls1.InsertBefore(Circle(8, 8, 8), (Circle(8, 8, 8)));
    std::cout << "Out List 1 after add 8.8.8 before 8.8.8 (haven't)" << std::endl << ls1 << sep;

    return 0;
};