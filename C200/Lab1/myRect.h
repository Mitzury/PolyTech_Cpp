#pragma once

class Rect {
public:
    int m_left;
    int m_right;
    int m_top;
    int m_bottom;

    Rect();  // ����������� ��� ����������
    Rect(const Rect& other); // ����������� �����������
    Rect(int left, int right, int top, int bottom);  // ����������� � �����������
    void InflateRect(int xIncrement = 1, int yIncrement = 1);  // ����� ���������� �������� ��������������
    void InflateRect(int dl, int dr, int dt, int db);  // ������������� ����� ��� ���������� �������� ��������������
  //  void InflateRect(int increment);  // ������������� ����� � ����� ����������
   // void InflateRect();
    void Normalize();  // ����� ��� �������� � ��������� "������������������" ��������������
    void PrintRect() const;  // ����� ��� ������ �������������� � �������
    void SetAll(int left, int right, int top, int bottom);  // ����� ��� ��������� �������� private-����������
    void GetAll(int& left, int& right, int& top, int& bottom) const;  // ����� ��� ��������� �������� private-����������

    int GetLeft() const;
    int GetRight() const;
    int GetTop() const;
    int GetBottom() const;
    
    Rect BoundingRectMethod(const Rect& rect) const;
};


Rect BoundingRect(Rect rect1, Rect rect2);
Rect BoundingRect2(const Rect& rect1, const Rect& rect2);

