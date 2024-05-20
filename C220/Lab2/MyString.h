#pragma once

class MyString {

    //  char* m_str;

public:
    char* m_str;
    //MyString(const char* str); 
    MyString(const char* str = "");
    MyString(const MyString& other);
    ~MyString();
    const char* GetString() const;
    void SetNewString(const char* newStr);
    MyString& operator+(const MyString& other) const; // неправильно
    MyString& operator=(const MyString& other);
    //
    //friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
    //    os << myStr.m_str;
    //    return os;
    //}
};
