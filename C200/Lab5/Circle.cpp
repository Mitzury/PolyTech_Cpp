#include "Circle.h"


Circle::Circle(int xCenter, int yCenter, int radius) : center(xCenter, yCenter) {
    this->r = radius;
}
double Circle::getSquare() {
    return 3.14159 * (r * 2);
}
bool operator==(const Circle& c1, const Circle& c2) {
    return c1.center == c2.center && c1.r == c2.r;
}
std::ostream& operator<<(std::ostream& os, const Circle& c) {
    os << "Circle (" << c.center << "," << c.r << ")";
    return os;
}
