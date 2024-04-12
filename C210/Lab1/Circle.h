#include <iostream>
#include <sstream>
#include "Point.h"

class Circle : public Shape {
private:
	Point Center;
	int x, y, radius;

public:
	// конструктор
	Circle(int x, int y, int r, Color c) : Center(x, y), radius(r), Shape(c) {}

	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	int GetRadius() {
		return radius;
	}

	// вычисление площади
	double calculateArea() const override {
		return 3.14159 * radius * radius;
	}

	// возвращает поле с цветом
	Color getColor() const override {
		return m_color;
	}

	// возвращает строковое представление объекта
	std::string toString() const override {
		std::ostringstream oss;
		oss << "\t" << "Circle(" << Center << "," << radius << ") " << colorMap(m_color) << " area: " << calculateArea() << std::endl;
		return oss.str();
	}

	// перегрузка метода вывода объекта в поток
	friend std::ostream& operator<<(std::ostream& os, const Circle& circle) {
		os << circle.toString();
		return os;
	}

	// метод, создающий копию объекта
	Shape* Clone() const override {
		return new Circle(*this); // —оздание копии объекта круга 
	}

	// метод, провер€ющий равенство объектов
	bool Equals(Shape* shape) const override {
		Circle* c = dynamic_cast<Circle*>(shape);
		if (c == nullptr)
			return false;
		return c->GetX() == x
			&& c->GetY() == y
			&& c->GetRadius() == radius
			&& c->getColor() == m_color;
	}

	// оператор не€вного каста к родительскому классу
	operator Shape* () const { return (Shape*)this; }
};