#pragma once
#include <algorithm>

// Шаблонная функция для вывода информации о векторе
template <typename T>
void printVectorInfo(const std::vector<T>& vec) {
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	std::cout << "Max Size: " << vec.max_size() << std::endl;
	std::cout << "Elements: ";
	for (const auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}

//// Перегрузка оператора вывода для вектора векторов
//template <typename T>
//std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv)
//	{
//	for (int i =0; i < vv.size(); i++) 
//	{
//		os << vv[i] << " ";
//		os << std::endl;
//	}
//	return os;
//}
// 
// Перегрузка оператора вывода для вектора векторов
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& vv) {
	for (std::vector<std::vector<int>>::const_iterator row = vv.begin(); row != vv.end(); ++row) {
		for (std::vector<int>::const_iterator val = row->begin(); val != row->end(); ++val) {
			os << *val << " ";
		}
		os << std::endl;
	}
	return os;
}

// Функция для вывода вектора
template <typename T>
void printVector(const std::vector<T>& vec) {
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Функция для вставки элемента перед каждым элементом вектора
template <typename T>
void insertBeforeEveryElement(std::vector<T>& vec, const T& value) {
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it = std::next(it, 2)) {
		it = vec.insert(it, value); // Вставляем элемент и сдвигаем итератор на новый элемент
	}
}

template <typename T>
void removeConsecutiveDuplicates(std::vector<T>& vec) {
	typename std::vector<T>::iterator newEnd = std::unique(vec.begin(), vec.end());
	vec.erase(newEnd, vec.end()); // Удаляем все дубликаты после последнего уникального элемента
}

template <typename T>
void removeAllDuplicates(std::vector<T>& vec) {
	sort(vec.begin(), vec.end()); // Сортируем вектор
	typename std::vector<T>::iterator newEnd = unique(vec.begin(), vec.end()); // Удаляем последовательные дубликаты
	vec.erase(newEnd, vec.end()); // Удаляем неуникальные элементы в конце вектора
}

//Универсальная функция для вывода контейнеров
template <typename Container>
void printContainer(const Container& c) {
	for (const auto& elem : c) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}

template<typename T>
void insertIfNotExists(std::vector<T>& vec, const T& value) {
	// Проверяем, есть ли значение в векторе
	bool alreadyExists = false;
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (*it == value) {
			alreadyExists = true;
			break;
		}
	}
	if (!alreadyExists) {
		// Если значения нет, вставляем его в начало вектора
		vec.insert(vec.begin(), value);
	}
}

// Функция-предикат для удаления элементов меньше нуля
bool isNegative(int x) {
	return x < 0;
}
