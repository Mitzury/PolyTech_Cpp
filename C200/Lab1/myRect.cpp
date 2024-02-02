#include "myRect.h"
#include <iostream>


Rect::Rect(int left, int right, int top, int bottom)
    : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
    Normalize();
}

Rect::Rect()
    : m_left(0), m_right(0), m_top(0), m_bottom(0) {
}

Rect::Rect(const Rect& other)
    : m_left(other.m_left),
    m_right(other.m_right),
    m_top(other.m_top),
    m_bottom(other.m_bottom) {
}


void Rect::InflateRect(int xIncrement, int yIncrement) {
    m_left -= xIncrement;
    m_right += xIncrement;
    m_top -= yIncrement;
    m_bottom += yIncrement;
    Normalize();
}
void Rect::InflateRect(int dl, int dr, int dt, int db) {
    m_left -= dl; 
    m_right += dr;
    m_top -= dt;
    m_bottom += db;
    Normalize();
}

void Rect::Normalize() {
    if (m_left > m_right) std::swap(m_left, m_right);
    if (m_top > m_bottom) std::swap(m_top, m_bottom);
}
void Rect::PrintRect() const {
    std::cout << "Rect: " << m_left << ", " << m_right << ", " << m_top << ", " << m_bottom << std::endl;
}
// Задание 3
void Rect::SetAll(int left, int right, int top, int bottom) {
    m_left = left;
    m_right = right;
    m_top = top;
    m_bottom = bottom;
    Normalize();
}
void Rect::GetAll(int& left, int& right, int& top, int& bottom) const {
    left = m_left;
    right = m_right;
    top = m_top;
    bottom = m_bottom;
}
// Задание 4
int Rect::GetLeft() const {
    return m_left;
}

int Rect::GetRight() const {
    return m_right;
}

int Rect::GetTop() const {
    return m_top;
}

int Rect::GetBottom() const {
    return m_bottom;
}
// BoundingRectMethod для класса Rect. 
// Этот метод принимает другой объект Rect в качестве параметра и возвращает новый объект Rect, 
// представляющий ограничивающий прямоугольник, охватывающий оба исходных прямоугольника.
Rect Rect::BoundingRectMethod(const Rect& rect) const {
    int left = std::min(m_left, rect.GetLeft());
    int right = std::max(m_right, rect.GetRight());
    int top = std::min(m_top, rect.GetTop());
    int bottom = std::max(m_bottom, rect.GetBottom());
    return Rect(left, right, top, bottom);
}
// Задание 4б. Передача объектов по ссылке.
Rect Rect::BoundingRect3(const Rect& rect1, const Rect& rect2)
{
        // Здесь объекты передаются по ссылке, и конструкторы копирования не вызываются
        int minX = std::min(rect1.m_left, rect2.m_left);
        int minY = std::min(rect1.m_right, rect2.m_right);
        int maxX = std::max(rect1.m_left + rect1.m_top, rect2.m_left + rect2.m_top);
        int maxY = std::max(rect1.m_right + rect1.m_bottom, rect2.m_right + rect2.m_bottom);
        return Rect(minX, minY, maxX - minX, maxY - minY);

}

// Глобальная функция BoundingRect
Rect BoundingRect(Rect rect1, Rect rect2) {
    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop()); 
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}
// Задание 4а. Передача объектов по ссылке.
Rect BoundingRect2(const Rect& rect1, const Rect& rect2) {

    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop());
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}
