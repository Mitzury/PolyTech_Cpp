#pragma once
#include "MyString.h" 
#include "MyData.h"

class Pair {
private:
    MyString key; // ���� ���� (������� ����������)
    MyData data; // ������ � ����������

public:
    // ����������� �� ���������
    Pair();
    // ����������� � �����������, ���������������� ���� � ������
    Pair(const MyString& k, const MyData& d);
    // ����� ��� ��������� �����
    const MyString& getKey() const;
    // ����� ��� ��������� ������
    MyData& getData();
    // ������������� �������� ������ ��� ������ Pair
    friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};
