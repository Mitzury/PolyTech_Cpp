#pragma once
#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    // констурктор, принимающий значения координат x и y
    Point(int xCoord = 0, int yCoord = 0)
    {
        x = xCoord;
        y = yCoord;
    }

    // перегрузка оператора вывода объекта в консоль
    friend std::ostream& operator << (std::ostream& os, const Point& p) {
        os << p.x << "," << p.y;
        return os;
    }
    // переопределение оператора ==, сравнивает точки по координатам
    friend bool operator==(const Point& p1, const Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

};
