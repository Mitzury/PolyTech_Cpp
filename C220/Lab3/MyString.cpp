#pragma once
#include <string>
#include "myString.h"

#include <cstdarg>
#include <ostream>

// Конструктор по умолчанию
MyString::MyString() {
    m_pStr = new char[1];   // Выделяем память для одного символа
    m_pStr[0] = '\0';       // Устанавливаем нулевой символ
};

// Конструктор с параметром
MyString::MyString(const char* str) {
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);

};
// конструктор перемещения класса mystring
MyString::MyString(MyString&& in) {
    m_pStr = in.m_pStr;
    in.m_pStr = 0;
};


MyString::MyString(const MyString& scopy) {
    if (scopy.m_pStr && strlen(scopy.m_pStr)) {
        m_pStr = new char[strlen(scopy.m_pStr) + 1];
        strcpy(m_pStr, scopy.m_pStr);
    }
    else {
        m_pStr = new char[1];
        m_pStr[0] = '\0';
    };
};

MyString::~MyString() {
    delete[] m_pStr;
};

const char* MyString::GetString() const {
    if (this == nullptr)
        return "empty string";
    return m_pStr;
};

void MyString::SetNewString(const char* newstr) {
    if (newstr && strlen(newstr)) {
        if (strlen(newstr) <= strlen(m_pStr)) {
            strcpy(m_pStr, newstr);
        }
        else {
            delete[] m_pStr;
            m_pStr = new char[strlen(newstr) + 1];
            strcpy(m_pStr, newstr);
        }

    }
    else {
        delete[] m_pStr;
        m_pStr = 0;
    }

}
void MyString::AddStr(const char* newstr)
{
    if (strlen(newstr))

    {
        char* tmp = new char[strlen(newstr) + strlen(m_pStr) + 1];
        char* pp = m_pStr;
        int ii = 0;
        while (*pp) { tmp[ii] = m_pStr[ii]; ii++; pp++; };
        int jj = 0;
        pp = const_cast <char*>(newstr);
        while (*pp) { tmp[ii] = newstr[jj]; ii++; jj++; pp++; };
        tmp[ii] = 0;
        delete[] m_pStr;
        m_pStr = tmp;
    }
}
std::ostream& operator<<(std::ostream& os, const MyString& s)
{
    os << s.GetString();
    return os;
}

MyString& MyString::operator=(const MyString& in) {
    delete[] m_pStr;
    m_pStr = new char[strlen(in.m_pStr) + 1];
    std::strcpy(m_pStr, in.m_pStr);
    return *this;
}
MyString& MyString::operator=(MyString&& in) noexcept {
    auto tmp = m_pStr;
    m_pStr = in.m_pStr;
    in.m_pStr = tmp;
    return *this;
}