#pragma once
#include "MyString.h"

class MyData {
public:
    // ������������ ��� ����
    enum Sex { UNDEF, MALE, FEMALE };
private:
    Sex sex; // ��� ����������
    size_t age; // ������� ����������
    MyString job; // ��������� ����������
    float salary; // �������� ����������
public:
    // �����������, ���������������� ������ ������ MyData
    MyData(Sex s, size_t a, const char* j, float sal);

    // ������������� �������� ������ ��� ������ MyData
    friend std::ostream& operator<<(std::ostream& os, const MyData& data);
};
