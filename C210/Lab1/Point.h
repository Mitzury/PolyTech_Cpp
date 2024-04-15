#pragma once
#include <iostream>

class Point {
private:
    int X;
    int Y;
public:
    Point(int xCoord, int yCoord);

    int getX() const;
    int getY() const;

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

