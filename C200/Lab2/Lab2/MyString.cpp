#include <string>
#include "myString.h"
#include <iostream>
using namespace std;


// ����������� (MyString::MyString(const char* str)): �������� ������������ ������ ��� �������� ������ str � �������� �� � ��� ������.
MyString::MyString(const char* str) {
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
    std::cout << "Constructor called" << std::endl;
}
