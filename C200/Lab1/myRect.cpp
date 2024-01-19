#include "myRect.h"
#include <iostream>

Rect::Rect()
    : m_left(0), m_right(0), m_top(0), m_bottom(0) {
}
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