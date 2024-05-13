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


// Задание 8: Разделение элементов на чётные и нечётные
template <typename Container, typename Od, typename Do>
void partitionEvenOdd(const Container& values, Od& evens, Do& odds) {
	// Используем алгоритм std::partition_copy для разделения элементов на четные и нечетные.
	// Он принимает итераторы, задающие диапазон элементов, функциональный объект-предикат и 
	// контейнеры для сохранения результатов.
	// Четные элементы будут записываться в evens, нечетные - в odds.
	std::partition_copy(values.begin(), values.end(), std::back_inserter(evens), std::back_inserter(odds), [](int x) {
		return x % 2 == 0;
		});
}


//// Задание 9: Подсчёт букв в верхнем регистре
//int countUppercase(const std::string& str) {
//	return std::count_if(str.begin(), str.end(), [](unsigned char c) {
//		return std::isupper(c);
//		});
//}
// Задание 9: Подсчёт букв в верхнем регистре
int countUppercase(const std::string& str) {
	int upperCount = 0;
	std::for_each(str.begin(), str.end(), [&upperCount](unsigned char c) {
		if (std::isupper(c)) {
			upperCount++;
		}
		});
	return upperCount;
}


// Задание 10: Конвертация enum в строку и обратно
enum class Color { Red, Green, Blue };

std::string enumToString(Color color) {
	switch (color) {
	case Color::Red: return "Красный";
	case Color::Green: return "Зелёный";
	case Color::Blue: return "Синий";
	default: return "Неизвестный";
	}
}

Color stringToEnum(const std::string& str) {
	// Создаем статическую инициализированную map, которая связывает строковые значения с 
	// соответствующими значениями перечисления color.
	static const std::unordered_map<std::string, Color> map = {
		{"Красный", Color::Red},
		{"Зелёный", Color::Green},
		{"Синий", Color::Blue}
	};
	auto it = map.find(str);
	if (it != map.end()) {
		return it->second;
	}
	throw std::invalid_argument("Неверная строка цвета");
}