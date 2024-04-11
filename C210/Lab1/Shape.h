#include <string>
#include <map>

class Shape {
public:
	// enum � ������� �����
	enum Color {
		WHITE,
		RED,
		GREEN
	};
	// map ��� ������������� ������� enum � ������
	std::string colorMap(Color color) const {
		switch (color) {
		case RED:
			return "RED";
			break;
		case GREEN:
			return "GREEN";
			break;
		default:
			return "WHITE";
		}
	}
	// �����������
	Shape(Color color) : m_color(color) {}
	// ����� ���������� ������� (�����������)
	virtual double calculateArea() const = 0;
	// �����, ������������ ���� � ������ (�����������)
	virtual Color getColor() const = 0;
	// �����, ������������ ��������� ������������� ������� (�����������)
	virtual std::string toString() const = 0;
	// �����, ��������� ����� ������� (�����������)
	virtual Shape* Clone() const = 0;
	// �����, ����������� ��������� �������� (�����������)
	virtual bool Equals(Shape* shape) const = 0;
protected:
	// ���� � ������, ���������� � �������� ������ �����������
	Color m_color;
};