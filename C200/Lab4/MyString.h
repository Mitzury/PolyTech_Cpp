#pragma once
#include <iostream>

class MyString {
private:
    char* m_str; // ��������� �� ������ �������� 

public:
    MyString(const char* s = ""); // �����������, ����������� C-style ������ (�� ��������� ������ ������)
    MyString(const MyString& other); // ����������� �����������
    ~MyString(); // ����������
    MyString& operator=(const MyString& other); // �������� ������������
    bool operator==(const char* s) const; // �������� ��������� � C-style �������
    bool operator>(const MyString& other) const; // �������� "������" ��� �����
    bool operator<(const MyString& other) const; // �������� "������" ��� �����
    bool operator==(const MyString& other) const; // �������� ��������� �����
    friend std::ostream& operator<<(std::ostream& os, const MyString& str); // ������������� �������� ������
};