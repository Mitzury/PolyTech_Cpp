#pragma once

//Задание 8 
template<typename T, size_t size>
class MyArray {
	T ar[size]{};   // Массив для хранения элементов типа T

public:
	MyArray() = default;
	MyArray(const T* p)
	{
		for (size_t i = 0; i < size; i++)
		{
			ar[i] = p[i];
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