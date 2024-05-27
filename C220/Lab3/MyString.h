#pragma once
class MyString {
	char* m_pStr;
public:
	MyString();						// ����������� �� ���������, ������� ������ ��� ������
	MyString(const char*);			// �����������, ��������� ������ � �������� �������
	MyString(const MyString&);		// ����������� �����������, ������� ����� ������� ������������� �������
	MyString(MyString&& in);		// ����������� �����������, ������� ����� ������, ��������� ������� � �������������
	~MyString();
	const char* GetString() const;
	void SetNewString(const char*);
	void AddStr(const char*);
	MyString& operator=(const MyString& in);
	MyString& operator=(MyString&& in) noexcept;
	friend std::ostream& operator<<(std::ostream& os, const MyString& s);

};