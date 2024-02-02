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

Color Shape::getColor() const {
    return color;
}

void Shape::WhereAmI() const {
    std::cout << "Now I am in class Shape" << std::endl;
}

void Shape::WhereAmIVirtual() const {
    std::cout << "Now I am in class Shape (virtual)" << std::endl;
}

Shape::~Shape() {
    std::cout << "Now I am in Shape's destructor!" << std::endl;

}

void Shape::printInfo() const {
    std::cout << "Color: " << colorToString(color) << std::endl;
}

Rect::Rect(Color c) : Shape(c) {}

void Rect::WhereAmI() const {
    std::cout << "Now I am in class Rect" << std::endl;

}

void Rect::WhereAmIVirtual() const {
    std::cout << "Now I am in class Rect (virtual)" << std::endl;
}

void Rect::printInfo() const {
    std::cout << "Rectangle of color: " << colorToString(color) << std::endl;
}

void Rect::Inflate(int factor) {
    std::cout << "Rect is inflating by a factor of " << factor << std::endl;
}

Rect::~Rect() {
    std::cout << "Now I am in Rect's destructor!" << std::endl;

}

Circle::Circle(Color c) : Shape(c) {
    std::cout << "Constructing Circle" << std::endl;
}

Circle::Circle() : Shape(RED) {}

Circle::Circle(const Rect& rect) : Shape(rect.getColor()) {}

void Circle::WhereAmI() const {
    std::cout << "Now I am in class Circle" << std::endl;

}

void Circle::WhereAmIVirtual() const {
    std::cout << "Now I am in class Circle (virtual)" << std::endl;
}

void Circle::printInfo() const {
    std::cout << "Circle of color: " << colorToString(color) << std::endl;
}

void Circle::Inflate(int factor) {
    std::cout << "Circle is inflating by a factor of " << factor << std::endl;
}

Circle::~Circle() {
    std::cout << "Now I am in Circle's destructor!" << std::endl;
}