#include "MyString.h"
#include <cstring>

// �����������, ����������� C-style ������
MyString::MyString(const char* s) {
    // �������� ������ ��� ����� ������ � �������� ���������� �� ���������� ������
    str = new char[strlen(s) + 1]; // �������� ���������� ������ ��� �������� ������ � ������� ���������� '\0'
    strcpy(str, s); // �������� ���������� ������ s � ���������� ������
}

// ����������� �����������
MyString::MyString(const MyString& other) {
    // �������� ������ ��� ����� ������ � �������� ���������� �� ������ other
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

// ����������
MyString::~MyString() {
    delete[] str; // ����������� ���������� ������ ��� �������� �������
}

// �������� ������������
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // ���������, ��� ������� �� ���������
        delete[] str; // ����������� ������ ������
        str = new char[strlen(other.str) + 1]; // �������� ����� ������
        strcpy(str, other.str); // �������� ���������� �� ������ ������
    }
    return *this; // ���������� ������ �� ������� ������
}

// �������� ��������� � C-style �������
bool MyString::operator==(const char* s) const {
    return strcmp(str, s) == 0; // ���������� ���������� ������ � ���������� C-style �������
}

// �������� "������" ��� �����
bool MyString::operator>(const MyString& other) const {
    return strcmp(str, other.str) > 0; // ���������� ���������� ������� ������ � ���������� �������
}

// �������� "������" ��� �����
bool MyString::operator<(const MyString& other) const {
    return strcmp(str, other.str) < 0; // ���������� ���������� ������� ������ � ���������� �������
}

// �������� ��������� �����
bool MyString::operator==(const MyString& other) const {
    return strcmp(str, other.str) == 0; // ���������� ���������� ������� ������ � ���������� �������
}

// ������������� �������� ������
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.str; // ������� ���������� ������ � ����� ������
    return os; // ���������� ������ �� ����� ������
}