#include "Shape.h"
#include <iostream>
#include <sstream>
#include "Point.h"

class Rect : public Shape {
private:
    Point upLeft;
    Point downRight;

public:

    // конструктор
    Rect(int x1,int y1,int x2,int y2, Color color): upLeft(x1,y1), downRight(x2, y2), Shape(color) {}


    // возвращает поле с цветом
    Color getColor() const override {
        return m_color;
    }
    // ћетод дл€ получени€ ширины пр€моугольника
    double getWidth() const {
        return abs(downRight.getX() - upLeft.getX());
    }
    double getHeight() const {
        return abs(downRight.getY() - upLeft.getY());
    }

    // вычисление площади
    double calculateArea() const override {
        // вычисл€ем ширину и высоту пр€моугольника
        double width = getWidth();
        double height = getHeight();

        // площадь = ширина * высота
        return width * height;
    }

    // возвращает строковое представление объекта
    std::string toString() const override {
        std::ostringstream oss;
        oss << "\tRectangle(" << upLeft << "," << downRight << ") " << colorMap(m_color) << " area: " << calculateArea() << std::endl;
        return oss.str();
    }

    // перегрузка метода вывода объекта в поток
    friend std::ostream& operator<<(std::ostream& os, const Rect& rect) {
        os << rect.toString();
        return os;
    }

    // метод, создающий копию объекта
    Shape* Clone() const override {
        return new Rect(*this); // —оздание копии объекта круга 
    }

    // метод, провер€ющий равенство объектов
    bool Equals(Shape* shape) const override {
        Rect* r = dynamic_cast<Rect*>(shape);
        if (r == nullptr)
            return false;
        return 
             r->upLeft.getX() == upLeft.getX()
            && r->downRight.getX() == downRight.getX()
            && r->upLeft.getY() == upLeft.getY()
            && r->downRight.getY() == downRight.getY()
            && r->getColor() == getColor();
    }

    // оператор не€вного каста к родительскому классу
    operator Shape* () const { return (Shape*)this; }
};
