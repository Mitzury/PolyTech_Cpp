#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


// ��������� ������� ��� ������ �������� (������������ � for_each)
template<typename T>
void printElement(const T& value) {
	cout << value << " ";
}

// ��������� ������� ��� ��������� ����� (������������ � for_each)
template<typename T>
void changePoint(T& value, int newX, int newY) {
	value.x = newX;
	value.y = newY;
}

// ������� �������������� ������ � ������ �������
string toLowerCase(const string& str) {
	string lowerCaseStr;
	transform(str.begin(), str.end(), back_inserter(lowerCaseStr), [](unsigned char c) -> unsigned char { return tolower(c); });
	return lowerCaseStr;
}


// ���������� ��������� ������ ��� ����
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
	return os << "{" << p.first << ": " << p.second << "}";
}

// ������ ������� ��� ������ ��������� ����������
template <typename Container>
void printContainer(const Container& container) {
	for (const auto& element : container) {
		cout << element << " ";
	}
	cout << endl;
}

// ������� ��� ��������� ���� ��������������� �� ����������� ������ �� ������ ���������
bool compareRects(const Rect& r1, const Rect& r2) {
	return r1.distanceFromOrigin() < r2.distanceFromOrigin();
}
