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

template<typename T>
void insertIfNotExists(std::vector<T>& vec, const T& value) {
	// Проверяем, есть ли значение в векторе
	if (std::find(vec.begin(), vec.end(), value) == vec.end()) {
		// Если значения нет, вставляем его в начало вектора
		vec.insert(vec.begin(), value);
	}
}

template<typename T>
void removeDuplicates(std::vector<T>& vec) {
	// Сортируем вектор
	std::sort(vec.begin(), vec.end());
	// Используем std::unique() для перемещения всех дублирующихся элементов в конец вектора
	auto last = std::unique(vec.begin(), vec.end());
	// Используем метод erase() для удаления всех дубликатов
	vec.erase(last, vec.end());
}

// Шаблон функции для вывода элементов любого контейнера на печать
template<typename Container>
void printContainer(const Container& cont, const std::string& contName) {
	std::cout << "Container type: " << typeid(Container).name() << std::endl;
	std::cout << "Container name: " << contName << std::endl;
	std::cout << "Container elements: ";
	for (const auto& elem : cont) {
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;
}


// Функция-предикат для удаления элементов меньше нуля
bool isNegative(int x) {
	return x < 0;
}

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