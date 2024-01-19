#pragma once

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

    Rect();  // Конструктор без параметров
    Rect(const Rect& other); // Конструктор копирования
    Rect(int left, int right, int top, int bottom);  // Конструктор с параметрами
    void InflateRect(int xIncrement, int yIncrement);  // Метод увеличения размеров прямоугольника
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);  // Перегруженный метод для увеличения размеров прямоугольника
  //  void InflateRect(int increment);  // Перегруженный метод с одним аргументом
   // void InflateRect();
    void Normalize();  // Метод для проверки и коррекции "ненормализованного" прямоугольника
    void PrintRect() const;  // Метод для вывода прямоугольника в консоль
    void SetAll(int left, int right, int top, int bottom);  // Метод для установки значений private-переменных
    void GetAll(int& left, int& right, int& top, int& bottom) const;  // Метод для получения значений private-переменных

    int GetLeft() const;
    int GetRight() const;
    int GetTop() const;
    int GetBottom() const;
    
    Rect BoundingRectMethod(const Rect& rect) const;
};


Rect BoundingRect(const Rect& rect1, const Rect& rect2);
Rect BoundingRect2(const Rect& rect1, const Rect& rect2);
