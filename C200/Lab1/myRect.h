#pragma once

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

public:
    Rect();  // ����������� ��� ����������
    Rect(int left, int right, int top, int bottom);  // ����������� � �����������
    void InflateRect(int xIncrement, int yIncrement);  // ����� ���������� �������� ��������������
    void InflateRect(int xIncrement, int yIncrement, int xIncrement2, int yIncrement2);  // ������������� ����� ��� ���������� �������� ��������������
    void Normalize();  // ����� ��� �������� � ��������� "������������������" ��������������
    void PrintRect() const;  // ����� ��� ������ �������������� � �������
    void SetAll(int left, int right, int top, int bottom);  // ����� ��� ��������� �������� private-����������
    void GetAll(int& left, int& right, int& top, int& bottom) const;  // ����� ��� ��������� �������� private-����������
};