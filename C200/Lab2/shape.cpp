#include "shape.h"

const char* colorToString(Color c) {
    switch (c) {
    case RED:
        return "RED";
    case GREEN:
        return "GREEN";
    case BLUE:
        return "BLUE";
    default:
        return "UNKNOWN";
    }
}

Shape::Shape(Color c) : color(c) {}

Shape::~Shape() {
    std::cout << "Now I am in Shape's destructor!" << std::endl;
}

Color Shape::getColor() const {
    return color;
}

void Shape::printInfo() const {
    std::cout << "Color: " << colorToString(color) << std::endl;
}

void Shape::Inflate(int factor) {
    std::cout << "Inflating in Shape by factor: " << factor << std::endl;
}

void Shape::WhereAmI() const {
    std::cout << "Now I am in class Shape" << std::endl;
}

void Shape::WhereAmIVirtual() const {
    std::cout << "Now I am in class Shape (virtual)" << std::endl;
}


Rect::Rect(Color c, int width, int height, int x, int y) : Shape(c), width(width), height(height), x(x), y(y) {}

Rect::~Rect() {
    std::cout << "Now I am in Rect's destructor!" << std::endl;
}

int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

int Rect::getX() const {
    return x;
}

int Rect::getY() const {
    return y;
}

void Rect::printInfo() const {
    std::cout << "Rectangle of color: " << colorToString(color) << std::endl;
    std::cout << "Width: " << width << ", Height: " << height << ", Position: (" << x << ", " << y << ")" << std::endl;
}

void Rect::Inflate(int factor) {
    std::cout << "Rect is inflating by a factor of " << factor << std::endl;
}

//void Rect::drawShape() const {
//    std::cout << "Drawing a rectangle" << std::endl;
//}

void Rect::WhereAmI() const {
    std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::WhereAmIVirtual() const {
    std::cout << "Now I am in class Rect (virtual)" << std::endl;
}


Circle::Circle(Color c, int centerX, int centerY, int radius) : Shape(c), centerX(centerX), centerY(centerY), radius(radius) {}

Circle::~Circle() {
    std::cout << "Now I am in Circle's destructor!" << std::endl;
}

void Circle::printInfo() const {
    std::cout << "Circle of color: " << colorToString(color) << std::endl;
    std::cout << "Center: (" << centerX << ", " << centerY << "), Radius: " << radius << std::endl;
}

void Circle::Inflate(int factor) {
    std::cout << "Circle is inflating by a factor of " << factor << std::endl;
}

//void Circle::drawShape() const {
//    std::cout << "Drawing a circle" << std::endl;
//}

void Circle::WhereAmI() const {
    std::cout << "Now I am in class Circle" << std::endl;
}

void Circle::WhereAmIVirtual() const {
    std::cout << "Now I am in class Circle (virtual)" << std::endl;
}