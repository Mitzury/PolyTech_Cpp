#pragma once


#include <iostream>

class Circle {
private:
    int x;
    int y;
    int radius;

public:
    Circle(int x, int y, int radius);

    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    bool operator==(const Circle& other) const;
    friend std::istream& operator>>(std::istream& is, Circle& circle);
    int getRadius() const;
};
