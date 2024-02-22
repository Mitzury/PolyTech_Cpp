#pragma once
class Point {
private:
    int x; // Координата x точки
    int y; // Координата y точки

public:
    // Конструктор класса Point, инициализирующий координаты точки
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; } // Метод для получения координаты x
    int getY() const { return y; } // Метод для получения координаты y
};