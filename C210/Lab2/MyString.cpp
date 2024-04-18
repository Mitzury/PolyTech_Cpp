#include <string>
#include <cstring>
#include <cctype>
#include "myString.h"

using namespace std;

// Определение конструктора
MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::MyString(const char* ptr)
{
	size_t size = strlen(ptr);
	m_pStr = new char[size + 1];
	strcpy_s(m_pStr, size + 1, ptr);
}

// move конструктор копирования
MyString::MyString(MyString&& str) {
	m_pStr = str.m_pStr;
	str.m_pStr = nullptr;
}

// деструктор
MyString::~MyString() {
	if (m_pStr != nullptr)
		delete[] m_pStr;
}

const char* MyString::GetString() const {
	return m_pStr;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this != &str) {
		// если это две разные строки
		if (this->m_pStr != nullptr && str.m_pStr != nullptr) {
			if (strlen(str.m_pStr) > strlen(m_pStr)) {
				delete[] m_pStr;
				m_pStr = new char[strlen(str.m_pStr) + 1];
			}
			strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
			m_pStr[strlen(str.m_pStr)] = '\0';
		}
		else if (this->m_pStr == nullptr && str.m_pStr != nullptr) {
			m_pStr = new char[strlen(str.m_pStr) + 1];
			strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
			m_pStr[strlen(str.m_pStr)] = '\0';
		}
		else if (this->m_pStr != nullptr && str.m_pStr == nullptr)  {
			delete[] m_pStr;
			m_pStr = nullptr;
		}
	}
	return *this;
	delete[] m_pStr;
}

MyString::MyString(const MyString& str) {
	if (str.m_pStr != nullptr) {
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
		m_pStr[strlen(str.m_pStr)] = '\0';
	}
	else
		m_pStr = nullptr;
}

void MyString::SetNewString(const char* ptr) {
	if (strcmp(this->m_pStr, ptr) != 0) {
		if (strlen(ptr) > strlen(m_pStr)) {
			delete[] m_pStr;
			m_pStr = new char[strlen(ptr) + 1];
		}
		strcpy_s(m_pStr, strlen(ptr) + 1, ptr);
		m_pStr[strlen(ptr)] = '\0';
	}
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	os << "contents:   \"" << str.m_pStr << "\"\n"; 
	return os;
}

MyString MyString::operator=(MyString&& str) {
	if (this != &str)
	{
		delete[] m_pStr;
		m_pStr = str.m_pStr;
		str.m_pStr = nullptr;
	}

	return *this;
}

MyString MyString::operator=(const char* p_char) {  
	if (strcmp(this->m_pStr, p_char) != 0) //  строки не одинаковы
	{
		if (strlen(p_char) > strlen(m_pStr)) // длина строки объекта меньше
		{
			delete[] m_pStr;
			m_pStr = new char[strlen(p_char) + 1];
		}
		strcpy_s(m_pStr, strlen(p_char) + 1, p_char);
		m_pStr[strlen(p_char)] = '\0';
	}
	return *this;
}

MyString operator+(const MyString& str1, const MyString& str2) {
	if (str1.m_pStr != nullptr && str2.m_pStr != nullptr) {
		char* str = new char[strlen(str1.GetString()) + strlen(str2.GetString()) + 1];
		strcpy_s(str, strlen(str1.GetString()), str1.GetString());
		strcpy_s(str + strlen(str1.GetString()), strlen(str2.GetString()) + 1, str2.GetString());
		MyString tmp(str);
		delete[]str;
		return tmp;
	}
	else if (str1.m_pStr == nullptr)
		return str2;
	else
		return str1;
}

MyString& MyString::operator+=(const MyString& str) {
	if (str.m_pStr != nullptr && m_pStr != nullptr) {
		// засунули все в промежуточный буфер
		char* buffer = new char[strlen(m_pStr) + strlen(str.GetString()) + 1];
		strcpy_s(buffer, strlen(m_pStr), m_pStr);
		strcpy_s(buffer + strlen(m_pStr), strlen(str.GetString()) + 1, str.GetString());
		delete[] m_pStr;
		m_pStr = buffer;
	}
	else if (str.m_pStr != nullptr) {
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy_s(m_pStr, strlen(str.m_pStr) + 1, str.m_pStr);
	}
	return *this;
}

MyString& MyString::operator++() {
	if (m_pStr != nullptr)
	{
		for (int i = 0; i < strlen(m_pStr); ++i)
			*(m_pStr + i) = std::toupper(*(m_pStr + i));
	}
	return *this;
}
MyString& MyString::operator--()  {
	if (m_pStr != nullptr)
	{
		for (int i = 0; i < strlen(m_pStr); ++i)
			*(m_pStr + i) = std::tolower(*(m_pStr + i));
	}
	return *this;
}
MyString MyString::operator++(int) {
	MyString return_str{ *this };

	if (m_pStr != nullptr)
	{
		for (int i = 0; i < strlen(m_pStr); ++i)
			*(m_pStr + i) = std::toupper(*(m_pStr + i));
	}

	return return_str;
}
MyString MyString::operator--(int) {
	MyString return_str{ *this };

	if (m_pStr != nullptr)
	{
		for (int i = 0; i < strlen(m_pStr); ++i)
			*(m_pStr + i) = std::tolower(*(m_pStr + i));
	}

	return return_str;
}

void MyString::Swap(MyString& str2)
{
	char* helper = this->m_pStr;

	this->m_pStr = str2.m_pStr;
	str2.m_pStr = helper;
}