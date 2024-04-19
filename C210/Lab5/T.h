#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


// Шаблонная функция для вывода элемента (используется в for_each)
template<typename T>
void printElement(const T& value) {
	cout << value << " ";
}

// Шаблонная функция для изменения точек (используется в for_each)
template<typename T>
void changePoint(T& value, int newX, int newY) {
	value.x = newX;
	value.y = newY;
}

// Функция преобразования строки в нижний регистр
string toLowerCase(const string& str) {
	string lowerCaseStr;
	transform(str.begin(), str.end(), back_inserter(lowerCaseStr), [](unsigned char c) -> unsigned char { return tolower(c); });
	return lowerCaseStr;
}


// Перегрузка оператора вывода для пары
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	return os << "{" << p.first << ": " << p.second << "}";
}

// Шаблон функции для вывода элементов контейнера
template <typename Container>
void printContainer(const Container& container) {
	for (const auto& element : container) {
		cout << element << " ";
	}
	cout << endl;
}

// Функция для сравнения двух прямоугольников по удаленности центра от начала координат
bool compareRects(const Rect& r1, const Rect& r2) {
	return r1.distanceFromOrigin() < r2.distanceFromOrigin();
}
