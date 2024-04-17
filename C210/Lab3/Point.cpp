#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

Point::Point(int x_val, int y_val) : x(x_val), y(y_val) {}

std::ostream& operator<<(std::ostream& os, const Point& Point) {
    os << "(" << Point.x << ", " << Point.y << ")";
    return os;
}

bool Point::operator<(const Point& other) const {
    return x < other.x;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}