#pragma once

#include <iostream>
#include <cctype> 

class MyString {
private:
    char* m_str;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    const char* GetString() const;
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& myString);
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    MyString& operator++();

    MyString operator--(int);
};