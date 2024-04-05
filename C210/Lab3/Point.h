#pragma once

class Point {
public:
	double x, y;
	Point() : x(0), y(0) {} // ����������� �� ���������
	Point(double x_val, double y_val) : x(x_val), y(y_val) {} // ����������� � �����������
	Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

	// ���������� ��������� << ��� ������ ��������� ���� Point
	friend std::ostream& operator<<(std::ostream& os, const Point& point) {
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};
