#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>
#include <cmath>
#include <functional>
#include <type_traits>

// ������� ��� ������ ��������� ����������
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // �������� �� ����������
        std::cout << elem << " "; // ����� ��������
    }
    std::cout << std::endl; // ������� �� ����� ������
}


std::string operator-(const std::string& str)
{
	std::string s(str);
	for (auto& ch : s)
	{
		std::isupper(ch) ? std::tolower(ch) : std::toupper(ch);
	}
	return str;
}
// ������� ��� "��������������" �������� � ����������
template<typename Cont>
void NegateAll(Cont& cont)
{
	auto it = std::begin(cont);
	auto it_end = std::end(cont);

	{
		for (; it != it_end; ++it)
		{
			(*it) = -(*it);
		}
	}
}

// ������� ��� ���������� ���������� �� ������ ���������
template<typename Container>
void absSort(Container& container) {
	std::sort(container.begin(), container.end(), [](const auto& a, const auto& b) {
		return std::abs(a) < std::abs(b); // ��������� �� ����������� ��������
		});
}


// ������� 8: ���������� ��������� �� ������ � ��������
template <typename Container, typename Od, typename Do>
void partitionEvenOdd(const Container& values, Od& evens, Do& odds) {
	// ���������� �������� std::partition_copy ��� ���������� ��������� �� ������ � ��������.
	// �� ��������� ���������, �������� �������� ���������, �������������� ������-�������� � 
	// ���������� ��� ���������� �����������.
	// ������ �������� ����� ������������ � evens, �������� - � odds.
	std::partition_copy(values.begin(), values.end(), std::back_inserter(evens), std::back_inserter(odds), [](int x) {
		return x % 2 == 0;
		});
}


//// ������� 9: ������� ���� � ������� ��������
//int countUppercase(const std::string& str) {
//	return std::count_if(str.begin(), str.end(), [](unsigned char c) {
//		return std::isupper(c);
//		});
//}
// ������� 9: ������� ���� � ������� ��������
int countUppercase(const std::string& str) {
	int upperCount = 0;
	std::for_each(str.begin(), str.end(), [&upperCount](unsigned char c) {
		if (std::isupper(c)) {
			upperCount++;
		}
		});
	return upperCount;
}


// ������� 10: ����������� enum � ������ � �������
enum class Color { Red, Green, Blue };

std::string enumToString(Color color) {
	switch (color) {
	case Color::Red: return "�������";
	case Color::Green: return "������";
	case Color::Blue: return "�����";
	default: return "�����������";
	}
}

Color stringToEnum(const std::string& str) {
	// ������� ����������� ������������������ map, ������� ��������� ��������� �������� � 
	// ���������������� ���������� ������������ color.
	static const std::unordered_map<std::string, Color> map = {
		{"�������", Color::Red},
		{"������", Color::Green},
		{"�����", Color::Blue}
	};
	auto it = map.find(str);
	if (it != map.end()) {
		return it->second;
	}
	throw std::invalid_argument("�������� ������ �����");
}