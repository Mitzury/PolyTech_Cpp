#pragma once
#include "Point.h"

// ����� Rect ������������ ������������� � ������� � ����� � ��������� ������� � �������
class Rect {
public:
	Point center; // ����� ��������������
	double width, height; // ������ � ������ ��������������

	// ����������� ��� ������������� ������ � �������� ��������������
	Rect(Point c, double w, double h) : center(c), width(w), height(h) {}

	// ������� ��� ������� ���������� �� ������ �������������� �� ������ ���������
	double distanceFromOrigin() const {
		return sqrt(pow(center.x, 2) + pow(center.y, 2));
	}

	// ������������� �������� ������ ��� ����������� ���������� � �������������� �� ������� �����
	friend std::ostream& operator<<(std::ostream& os, const Rect& r) {
		return os << "������������� � ������� � ����� " << r.center
			<< ", ������ " << r.width << ", ������ " << r.height;
	}

};