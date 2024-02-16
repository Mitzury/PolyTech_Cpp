#include "Point.h"
#include <iostream>

class Circle {
private:
    Point center;
    int radius;

public:
    Circle(const Point& center, int radius);

    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    bool operator==(const Circle& other) const;
    friend std::istream& operator>>(std::istream& is, Circle& circle);
    int getRadius() const;
};