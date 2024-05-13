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
