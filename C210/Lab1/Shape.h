#include <string>
#include <map>

class Shape {
public:
	// enum с цветами фигур
	enum Color {
		WHITE,
		RED,
		GREEN
	};
	// map дл€ сопоставлени€ объекта enum и строки
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
	// конструктор
	Shape(Color color) : m_color(color) {}
	// метод вычислени€ площади (абстрактный)
	virtual double calculateArea() const = 0;
	// метод, возвращающий поле с цветом (абстрактный)
	virtual Color getColor() const = 0;
	// метод, возвращающий строковое представление объекта (абстрактный)
	virtual std::string toString() const = 0;
	// метод, создающий копию объекта (асбтрактный)
	virtual Shape* Clone() const = 0;
	// метод, провер€ющий равенство объектов (асбтрактный)
	virtual bool Equals(Shape* shape) const = 0;
protected:
	// поле с цветом, передаетс€ и доступно только наследникам
	Color m_color;
};