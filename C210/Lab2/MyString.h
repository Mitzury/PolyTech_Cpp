#pragma once

#include <iostream>

class MyString
{
    char* m_pStr;	//������-���� ������
public:
    MyString(); // ����������� �� ���������
    MyString(const char* ptr); // �����������
    MyString(const MyString& str); // ����������� �����������
    MyString(MyString&& str); // move ����������� �����������
    ~MyString();
    const char* GetString() const;
    MyString& operator=(const MyString& str); // �������� ������������
    void SetNewString(const char* ptr);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    MyString operator=(MyString&& str);
    MyString operator=(const char* p_char);
    friend MyString operator+(const MyString& str1, const MyString& str2);
    MyString& operator+=(const MyString& str);
    MyString& operator++(); 
    MyString& operator--(); 
    MyString operator++(int); 
    MyString operator--(int); 

    //friend void Swap(MyString& str1, MyString& str2);  //!!!
    void Swap(MyString& str2);
};

