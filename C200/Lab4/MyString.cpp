#include "MyString.h"
#include <cstring>

// �����������, ����������� C-style ������
MyString::MyString(const char* s) {
    // �������� ������ ��� ����� ������ � �������� ���������� �� ���������� ������
    m_str = new char[strlen(s) + 1]; // �������� ���������� ������ ��� �������� ������ � ������� ���������� '\0'
    strcpy(m_str, s); // �������� ���������� ������ s � ���������� ������
}

// ����������� �����������
MyString::MyString(const MyString& other) {
    // �������� ������ ��� ����� ������ � �������� ���������� �� ������ other
    m_str = new char[strlen(other.m_str) + 1];
    strcpy(m_str, other.m_str);
}

// ����������
MyString::~MyString() {
    delete[] m_str; // ����������� ���������� ������ ��� �������� �������
}

// �������� ������������
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // ���������, ��� ������� �� ���������
        delete[] m_str; // ����������� ������ ������
        m_str = new char[strlen(other.m_str) + 1]; // �������� ����� ������
        strcpy(m_str, other.m_str); // �������� ���������� �� ������ ������
    }
    return *this; // ���������� ������ �� ������� ������
}

// �������� ��������� � C-style �������
bool MyString::operator==(const char* s) const {
    return strcmp(m_str, s) == 0; // ���������� ���������� ������ � ���������� C-style �������
}

// �������� "������" ��� �����
bool MyString::operator>(const MyString& other) const {
    return strcmp(m_str, other.m_str) > 0; // ���������� ���������� ������� ������ � ���������� �������
}

// �������� "������" ��� �����
bool MyString::operator<(const MyString& other) const {
    return strcmp(m_str, other.m_str) < 0; // ���������� ���������� ������� ������ � ���������� �������
}

// �������� ��������� �����
bool MyString::operator==(const MyString& other) const {
    return strcmp(m_str, other.m_str) == 0; // ���������� ���������� ������� ������ � ���������� �������
}

// ������������� �������� ������
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.m_str; // ������� ���������� ������ � ����� ������
    return os; // ���������� ������ �� ����� ������
}