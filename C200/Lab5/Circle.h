#pragma once
#include "Point.h"
using namespace std;
class Circle {
private:
    Point center;
    int r;
public:
    Circle(int xCenter, int yCenter, int radius);

    double getSquare();

    // переопределение оператора ==, сравнивает круги по площади и координатам центра
    friend bool operator==(const Circle& c1, const Circle& c2);
    // перегрузка оператора вывода объекта в консоль
    friend std::ostream& operator << (std::ostream& os, const Circle& c);
};