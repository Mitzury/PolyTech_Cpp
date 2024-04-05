#pragma once

class Point {
public:
	double x, y;
	Point() : x(0), y(0) {} // Конструктор по умолчанию
	Point(double x_val, double y_val) : x(x_val), y(y_val) {} // Конструктор с параметрами
	Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

	// Перегрузка оператора << для вывода элементов типа Point
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};
