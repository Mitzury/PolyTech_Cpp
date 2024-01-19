#include "myRect.h"
#include <iostream>


Rect::Rect(int left, int right, int top, int bottom)
    : m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
    Normalize();
}
void Rect::InflateRect(int xIncrement, int yIncrement) {
    m_left -= xIncrement;
    m_right += xIncrement;
    m_top -= yIncrement;
    m_bottom += yIncrement;
    Normalize();
}
void Rect::InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2) {
    m_left -= xIncrement;
    m_right += xIncrement2;
    m_top -= yIncrement;
    m_bottom += yIncrement2;
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


Rect BoundingRect(const Rect& rect1, const Rect& rect2) {
    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop());
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}

Rect BoundingRect2(const Rect& rect1, const Rect& rect2) {
    int left = std::min(rect1.GetLeft(), rect2.GetLeft());
    int right = std::max(rect1.GetRight(), rect2.GetRight());
    int top = std::min(rect1.GetTop(), rect2.GetTop());
    int bottom = std::max(rect1.GetBottom(), rect2.GetBottom());

    return Rect(left, right, top, bottom);
}