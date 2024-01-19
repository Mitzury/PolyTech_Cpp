#pragma once

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    Rect();  // Конструктор без параметров
    Rect(int left, int right, int top, int bottom);  // Конструктор с параметрами
    void InflateRect(int xIncrement, int yIncrement);  // Метод увеличения размеров прямоугольника
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);  // Перегруженный метод для увеличения размеров прямоугольника
    void Normalize();  // Метод для проверки и коррекции "ненормализованного" прямоугольника
    void PrintRect() const;  // Метод для вывода прямоугольника в консоль
    void SetAll(int left, int right, int top, int bottom);  // Метод для установки значений private-переменных
    void GetAll(int& left, int& right, int& top, int& bottom) const;  // Метод для получения значений private-переменных
};