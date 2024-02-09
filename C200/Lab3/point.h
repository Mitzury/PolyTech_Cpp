#pragma once
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {} //������� 2
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

    //������� 2
    Point operator+(const Point& other) const {
        Point result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }
    friend Point operator-(const Point& left, const Point& right) {
        Point result;
        result.x = left.x - right.x;
        result.y = left.y - right.y;
        return result;
    }
    Point operator+(int scalar) const {
        Point result;
        result.x = this->x + scalar;
        result.y = this->y + scalar;
        return result;
    }
    friend Point operator-(int scalar, const Point& point) {
        Point result;
        result.x = scalar - point.x;
        result.y = scalar - point.y;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        //os << "(" << point.x << ", " << point.y << ")";
        //������� 4
        os << "x = " << point.x << ", y = " << point.y;
        return os;
    }

    //������� 3
    // ���������� �������� ��������� +
    Point operator+() const {
        // ���������� ������� ������, �.�. �������� + �� ������ ��������
        return *this;
    }

    // ���������� �������� ��������� -
    Point operator-() const {
        Point result;
        result.x = -this->x;
        result.y = -this->y;
        return result;
    }
};