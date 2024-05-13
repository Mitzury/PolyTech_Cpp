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

// Функция для печати элементов контейнера
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // итерация по контейнеру
        std::cout << elem << " "; // вывод элемента
    }
    std::cout << std::endl; // переход на новую строку
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

// Функция для "инвертирования" значений в контейнере
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

// Функция для сортировки контейнера по модулю элементов
template<typename Container>
void absSort(Container& container) {
	std::sort(container.begin(), container.end(), [](const auto& a, const auto& b) {
		return std::abs(a) < std::abs(b); // сравнение по абсолютному значению
		});
}
