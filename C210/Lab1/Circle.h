#include <iostream>
#include <sstream>

class Circle : public Shape {
private:
	int x, y, radius;

public:
	// �����������
	Circle(int x, int y, int r, Color c) : radius(r), x(x), y(y), Shape(c) {}

	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	int GetRadius() {
		return radius;
	}

	// ���������� �������
	double calculateArea() const override {
		return 3.14159 * radius * radius;
	}

	// ���������� ���� � ������
	Color getColor() const override {
		return m_color;
	}

	// ���������� ��������� ������������� �������
	std::string toString() const override {
		std::ostringstream oss;
		oss << "Circle: x= " << x << " ,y= " << y << " ,radius= " << radius << " ,color= " << colorMap(m_color) << " ,area: " << calculateArea() << std::endl;
		return oss.str();
	}

	// ���������� ������ ������ ������� � �����
	friend std::ostream& operator<<(std::ostream& os, const Circle& circle) {
		os << circle.toString();
		return os;
	}

	// �����, ��������� ����� �������
	Shape* Clone() const override {
		return new Circle(*this); // �������� ����� ������� ����� 
	}

	// �����, ����������� ��������� ��������
	bool Equals(Shape* shape) const override {
		Circle* c = dynamic_cast<Circle*>(shape);
		if (c == nullptr)
			return false;
		return c->GetX() == x
			&& c->GetY() == y
			&& c->GetRadius() == radius
			&& c->getColor() == m_color;
	}

	// �������� �������� ����� � ������������� ������
	operator Shape* () const { return (Shape*)this; }
};