#pragma once
#include "Point.h"

// Класс Rect представляет прямоугольник с центром в точке и заданными шириной и высотой
class Rect {
public:
	Point center; // Центр прямоугольника
	double width, height; // Ширина и высота прямоугольника

	// Конструктор для инициализации центра и размеров прямоугольника
	Rect(Point c, double w, double h) : center(c), width(w), height(h) {}

	// Функция для расчета расстояния от центра прямоугольника до начала координат
	double distanceFromOrigin() const {
		return sqrt(pow(center.x, 2) + pow(center.y, 2));
	}

	// Перегруженный оператор вывода для отображения информации о прямоугольнике на русском языке
	friend std::ostream& operator<<(std::ostream& os, const Rect& r) {
		return os << "Прямоугольник с центром в точке " << r.center
			<< ", ширина " << r.width << ", высота " << r.height;
	}

};