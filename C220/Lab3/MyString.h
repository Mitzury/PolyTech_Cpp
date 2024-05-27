#pragma once
class MyString {
	char* m_pStr;
public:
	MyString();						// Конструктор по умолчанию, создает объект без строки
	MyString(const char*);			// Конструктор, создающий объект с заданной строкой
	MyString(const MyString&);		// Конструктор копирования, создает копию объекта существующего объекта
	MyString(MyString&& in);		// Конструктор перемещения, создает новый объект, заимствуя ресурсы у существующего
	~MyString();
	const char* GetString() const;
	void SetNewString(const char*);
	void AddStr(const char*);
	MyString& operator=(const MyString& in);
	MyString& operator=(MyString&& in) noexcept;
	friend std::ostream& operator<<(std::ostream& os, const MyString& s);

};