#pragma once
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    // ���������� ��������� +=
    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    // ���������� ��������� +=
    Point& operator+=(int value) {
        this->x += value;
        this->y += value;
        return *this;
    }

    // ���������� ��������� -= (� ���� ���������� �������)
    friend Point operator-=(Point& pt1, const Point& pt2) {
        pt1.x -= pt2.x;
        pt1.y -= pt2.y;
        return pt1;
    }

    // ���������� ��������� -= (� ���� ���������� �������)
    friend Point operator-=(Point& pt, int value) {
        pt.x -= value;
        pt.y -= value;
        return pt;
    }

    // �������������� ����� ��� ������ ��������� �����
    void printCoordinates() const {
        std::cout << "X: " << x << ", Y: " << y << std::endl;
    }
};