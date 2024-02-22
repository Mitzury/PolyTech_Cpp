#include "Point.h"
#include <iostream>

class Circle {
private:
    Point center; // Центр окружности (точка)
    int radius; // Радиус окружности

public:
    // Конструктор класса Circle, инициализирующий центр окружности и радиус
    Circle(const Point& center, int radius);

    // Перегрузка оператора вывода для вывода информации об окружности в поток
    friend std::ostream& operator<<(std::ostream& os, const Circle& circle);
    // Перегрузка оператора сравнения для сравнения окружностей
    bool operator==(const Circle& other) const;
    // Перегрузка оператора ввода для ввода информации об окружности из потока
    friend std::istream& operator>>(std::istream& is, Circle& circle);
    // Метод для получения радиуса окружности
    int getRadius() const;
};