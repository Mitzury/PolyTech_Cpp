#include "Shape.h"
#include <iostream>
#include <sstream>
#include "Point.h"

class Rect : public Shape {
private:
    Point upLeft;
    Point downRight;

public:

    // �����������
    Rect(int x1,int y1,int x2,int y2, Color color): upLeft(x1,y1), downRight(x2, y2), Shape(color) {}


    // ���������� ���� � ������
    Color getColor() const override {
        return m_color;
    }

    int GetX1() {
        return upLeft.getX();
    }
    int GetX2() {
        return downRight.getX();
    }
    int GetY1() {
        return upLeft.getY();
    }
    int GetY2() {
        return downRight.getY();
    }

    // ����� ��� ��������� ������ ��������������
    double getWidth() const {
        return abs(downRight.getX() - upLeft.getX());
    }
    double getHeight() const {
        return abs(downRight.getY() - upLeft.getY());
    }

    // ���������� �������
    double calculateArea() const override {
        // ��������� ������ � ������ ��������������
        double width = getWidth();
        double height = getHeight();
        // ������� = ������ * ������
        return width * height;
    }

    // ���������� ��������� ������������� �������
    std::string toString() const override {
        std::ostringstream oss;
        oss << "\tRectangle(" << upLeft << "," << downRight << ") " << colorMap(m_color) << " area: " << calculateArea() << std::endl;
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
        return r->GetX1() == upLeft.getX()
            && r->GetX2() == downRight.getX()
            && r->GetY1() == upLeft.getY()
            && r->GetY2() == downRight.getY()
            && Shape::Equals(shape); // c->getColor() == m_color;
    }

    // �������� �������� ����� � ������������� ������
    operator Shape* () const { return (Shape*)this; }
};
