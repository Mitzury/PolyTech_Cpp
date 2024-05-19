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
// Задание 6: Функция для сортировки контейнера по модулю элементов
//Модуль числа — это расстояние от нуля до данного числа.Например,
//То есть расстояние от точки −5 до нуля равно 5.
//template<typename T>
//class AbsForSort
//{
//public:
//	bool operator()(const T& elem1, const T& elem2) const
//	{
//		return std::abs(elem1) < std::abs(elem2);
//	}
//};
template<typename Container>
void absSort(Container& cont) {
	auto it = std::begin(cont);
	auto itEnd = std::end(cont);

	std::sort(it, itEnd, [](auto elem1, auto elem2) -> bool
		{
			return std::abs(elem1) < std::abs(elem2);
		});
}
// Задание 7: Суммирование элементов разнотипных контейнеров
template<typename T1, typename T2>
auto sumContainers(const T1& l1, const T2& l2) {
	// Определяем размер нового контейнера - 
	// он равен максимальному размеру из двух переданных контейнеров
	auto max_size = std::max(std::size(l1), std::size(l2));
	// Создаем новый контейнер, который будет хранить суммы элементов
	// Вектор выбран как универсальный контейнер подходящий для большинства ситуаций
	std::vector<decltype(*std::begin(l1) + *std::begin(l2))> res(max_size);
	// Копируем элементы из первого контейнера в новый
	std::copy(std::cbegin(l1), std::cend(l1), res.begin());
	// Складываем элементы из второго контейнера с элементами нового контейнера
   // Используем функцию transform, которая применяет заданную операцию к каждому элементу диапазона
	std::transform(std::cbegin(l2), std::cend(l2), res.begin(), res.begin(), [](auto a, auto b) {return b + a; });

	return res;

}

// Задание 8: Разделение элементов на чётные и нечётные
// Шаблонная функция для разделения элементов контейнера на две группы

template<typename T, typename T2, typename T3, typename P>
void Separate(const T& l1, T2& l2, T3& l3, P pred) {
	for (const auto& elem : l1)
	{
		if (pred(elem))
			l2.insert(end(l2), elem);
		else
			l3.insert(end(l3), elem);
	};
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
// Перечисление цвета
enum class Color : char { Red, Green, Blue };
// Перечисление для дней недели
enum class day : char { monday, tuesday, wednesday, thursday, friday, saturday, sunday };

template<typename T> std::map<std::string, T> my_map;

template<> std::map<std::string, Color> my_map<Color> {
	{"red", Color::Red },
	{ "green", Color::Green },
	{ "blue", Color::Blue }
};

template<typename T>
T stringToEnum(const std::string& str)
{
	return my_map<T>.at(str);
}

template<typename T>
std::string enumToString(const T& t)
{
	for (const auto& [f, s] : my_map<T>)
	{
		if (s == t)
			return f;
	}
	throw std::out_of_range("no element");
}