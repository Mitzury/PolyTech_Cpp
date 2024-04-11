#include "Shape.h"
#include <iostream>
#include <sstream>

class Rect : public Shape {
private:
    int x1, y1, x2, y2;

public:
    // �����������
    Rect(
        int x1,
        int y1,
        int x2,
        int y2,
        Color color)
        : x1(x1),
        y1(y1),
        x2(x2),
        y2(y2),
        Shape(color) {}

    int GetX1() {
        return x1;
    }
    int GetX2() {
        return x2;
    }
    int GetY1() {
        return y1;
    }
    int GetY2() {
        return y2;
    }
    // ���������� ���� � ������
    Color getColor() const override {
        return m_color;
    }

    // ���������� �������
    double calculateArea() const override {
        return abs(x1 - x2) * abs(y1 - y2);
    }

    // ���������� ��������� ������������� �������
    std::string toString() const override {
        std::ostringstream oss;
        oss << "Rectangle: x1= " << x1 << " ,y1= " << y1 << " ,x2= " << x2 << " ,y2= " << y2 << " ,color= " << colorMap(m_color) << " ,area: " << calculateArea() << std::endl;
        return oss.str();
    }

    // ���������� ������ ������ ������� � �����
    friend std::ostream& operator<<(std::ostream& os, const Rect& rect) {
        os << rect.toString();
        return os;
    }

    // �����, ��������� ����� �������
    Shape* Clone() const override {
        return new Rect(*this); // �������� ����� ������� ����� 
    }

    // �����, ����������� ��������� ��������
    bool Equals(Shape* shape) const override {
        Rect* r = dynamic_cast<Rect*>(shape);
        if (r == nullptr)
            return false;
        return r->GetX1() == x1
            && r->GetX2() == x2
            && r->GetY1() == y1
            && r->GetY2() == y2
            && r->getColor() == m_color;
    }

    // �������� �������� ����� � ������������� ������
    operator Shape* () const { return (Shape*)this; }
};
