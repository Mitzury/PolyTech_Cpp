#pragma once

#include <string>

class MyString {
private:
	std::string str;
public:
	MyString(const std::string& s) : str(s) {}
	const std::string& get() const { return str; }
	void set(const std::string& s) { str = s; }
};