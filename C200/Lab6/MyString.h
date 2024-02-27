#include <iostream>
#include "Counter.h"
class MyString {
private:
    char* m_str;
    Counter* m_counter;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    const char* GetString() const;
    void SetNewString(const char* newStr);
    MyString& operator=(const MyString& other);

    void AddUser();
    friend std::ostream& operator<<(std::ostream& os, const MyString& myString);
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    MyString& operator++();
    MyString operator--(int);
    static void print();

    static void changeCase();
    static void printAlph();
};
