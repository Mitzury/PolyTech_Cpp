#pragma once
#include "Point.h"

class Circle {
public:
    Point center;
    int radius;

    // ����������� ������ Circle
    Circle(int centerX, int centerY, int circleRadius);

    friend std::ostream& operator<<(std::ostream& os, const Circle& c);
};
