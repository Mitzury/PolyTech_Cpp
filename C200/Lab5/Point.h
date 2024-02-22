#pragma once
class Point {
private:
    int x; // ���������� x �����
    int y; // ���������� y �����

public:
    // ����������� ������ Point, ���������������� ���������� �����
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; } // ����� ��� ��������� ���������� x
    int getY() const { return y; } // ����� ��� ��������� ���������� y
};