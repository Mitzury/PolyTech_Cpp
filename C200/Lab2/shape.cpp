#include "shape.h"

// Функция преобразования перечисления Color в строку
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

// Реализация методов базового класса Shape

// Конструктор Shape, устанавливающий цвет
Shape::Shape(Color c) : color(c) {}

// Геттер для цвета
Color Shape::getColor() const {
    return color;
}

// Невиртуальная функция, сообщающая о местоположении объекта Shape
void Shape::WhereAmI() const { 
    std::cout << "Now I am in class Shape" << std::endl;
}

// Виртуальная функция, сообщающая о местоположении объекта Shape (может быть переопределена)
void Shape::WhereAmIVirtual() const {
    std::cout << "Now I am in class Shape (virtual)" << std::endl;
}

// Виртуальный деструктор Shape
Shape::~Shape() {
    std::cout << "Now I am in Shape's destructor!" << std::endl;

}

// Виртуальная функция для вывода информации о фигуре (может быть переопределена в производных классах)
void Shape::printInfo() const {
    std::cout << "Color: " << colorToString(color) << std::endl;
}

// Реализация методов производного класса Rect

// Конструктор Rect, устанавливающий цвет с использованием конструктора базового класса Shape
Rect::Rect(Color c) : Shape(c) {}

// Невиртуальная функция, сообщающая о местоположении объекта Rect
void Rect::WhereAmI() const {
    std::cout << "Now I am in class Rect" << std::endl;

}

void Rect::WhereAmIVirtual() const {
    std::cout << "Now I am in class Rect (virtual)" << std::endl;
}

void Rect::printInfo() const {
    std::cout << "Rectangle of color: " << colorToString(color) << std::endl;
}

//void Rect::Inflate(int factor) {
//    std::cout << "Rect is inflating by a factor of " << factor << std::endl;
//}

Rect::~Rect() {
    std::cout << "Now I am in Rect's destructor!" << std::endl;

}

Circle::Circle(Color c) : Shape(c) {
    std::cout << "Constructing Circle" << std::endl;
}

// Реализация методов производного класса Circle

// Конструктор Circle, устанавливающий цвет с использованием конструктора базового класса Shape
Circle::Circle() : Shape(RED) {}

Circle::Circle(const Rect& rect) : Shape(rect.getColor()) {}

void Circle::WhereAmI() const {
    std::cout << "Now I am in class Circle" << std::endl;

}

// Переопределенная виртуальная функция базового класса Shape
void Circle::WhereAmIVirtual() const {
    std::cout << "Now I am in class Circle (virtual)" << std::endl;
}

// Переопределенная виртуальная функция для вывода информации о круге
void Circle::printInfo() const {
    std::cout << "Circle of color: " << colorToString(color) << std::endl;
}

// Реализация чисто виртуальной функции Inflate для круга
//void Circle::Inflate(int factor) {
//    std::cout << "Circle is inflating by a factor of " << factor << std::endl;
//}

Circle::~Circle() {
    std::cout << "Now I am in Circle's destructor!" << std::endl;
}