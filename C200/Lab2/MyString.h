#pragma once
class MyString {

    char* m_str;

public:
    //MyString(const char* str); 
    MyString(const char* str = "");
    MyString(const MyString& other);
    ~MyString();
    const char* GetString() const;
    void SetNewString(const char* newStr);
    /*  MyString& operator=(const MyString& other);*/

};
