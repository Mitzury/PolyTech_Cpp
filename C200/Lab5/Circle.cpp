#include "Circle.h"

// Определение конструктора класса Circle, инициализирующего центр и радиус круга
Circle::Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

// Вывод информации о круге в формате "Circle(x, y, radius)"
std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Circle(" << circle.x << ", " << circle.y << ", " << circle.radius << ")";
    return os;
}

// Проверка на равенство координат центров и радиусов двух кругов
bool Circle::operator==(const Circle& other) const {
    return x == other.x && y == other.y && radius == other.radius;
}

std::istream& operator>>(std::istream& is, Circle& circle) {
    is >> circle.x >> circle.y >> circle.radius;
    return is;
}

int Circle::getRadius() const {
    return radius;
}