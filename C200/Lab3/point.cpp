#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

// Перегрузка оператора +=
Point& Point::operator+=(const Point& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

// Перегрузка оператора +=
Point& Point::operator+=(int value) {
    this->x += value;
    this->y += value;
    return *this;
}

Point Point::operator+(const Point& other) const { 
    Point result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    return result;
}

Point Point::operator+(int scalar) const {
    Point result;
    result.x = this->x + scalar;
    result.y = this->y + scalar;
    return result;
}

Point Point::operator-(int scalar) const {
    Point result;
    result.x = this->x - scalar;
    result.y = this->y - scalar;
    return result;
}

Point Point::operator+() const {
    return *this;
}

Point Point::operator-() const {
    Point result;
    result.x = -this->x;
    result.y = -this->y;
    return result;
}

// Перегрузка оператора -= (в виде глобальной функции)
Point operator-=(Point& pt1, const Point& pt2) {
    pt1.x -= pt2.x;
    pt1.y -= pt2.y;
    return pt1;
}
// Перегрузка оператора -= (в виде глобальной функции)
Point operator-=(Point& pt, int value) {
    pt.x -= value;
    pt.y -= value;
    return pt;
}

Point operator-(const Point& left, const Point& right) {
    Point result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    return result;
}

Point operator-(int scalar, const Point& point) {
    Point result;
    result.x = scalar - point.x;
    result.y = scalar - point.y;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

// Дополнительный метод для вывода координат точки
void Point::printCoordinates() const {
    std::cout << "X: " << x << ", Y: " << y << std::endl;
}