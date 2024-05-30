#pragma once

//Задание 8 
template<typename T, size_t size>
class MyArray {
	T ar[size];   // Массив для хранения элементов типа T

public:
	MyArray(const T* arr = nullptr) {
		// Конструктор класса
		if (arr) {
			std::memcpy(ar, arr, size * sizeof(T));  // Копирование значений из переданного массива
		}
		else {
			for (size_t i = 0; i < size; ++i) {
				ar[i] = T();   // Инициализация значений массива значением по умолчанию
			}
		}
	}
	T& operator[](size_t index) {
		// Перегрузка оператора [] для доступа к элементам массива
		return ar[index];   // Возвращение ссылки на элемент массива по указанному индексу
	}

	const T& operator[](size_t index) const {
		// Перегрузка оператора [] для доступа к элементам массива (константная версия)
		return ar[index];   // Возвращение константной ссылки на элемент массива по указанному индексу
	}

	size_t getSize() const {
		// Метод для получения размера массива
		return size;   // Возвращение размера массива
	}

	void print() const {
		// Метод для печати элементов массива
		for (size_t i = 0; i < size; ++i) {
			std::cout << ar[i] << " ";   // Печать каждого элемента массива
		}
		std::cout << std::endl;   // Переход на новую строку
	}
};


template<typename T, size_t size>
MyArray<T, size> makeMyArray(std::initializer_list<T> initList) {
	// Функция для создания объекта MyArray из списка инициализации
	MyArray<T, size> result;   // Создание объекта MyArray
	size_t i = 0;
	for (const T& element : initList) {
		// Перебор элементов списка инициализации
		if (i >= size) break;   // Прерывание цикла, если достигнут максимальный размер массива
		result[i++] = element;  // Заполнение элемента массива значением из списка инициализации
	}
	return result;   // Возвращение созданного объекта MyArray
}
