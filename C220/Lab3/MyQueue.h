#pragma once
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>

// Данный код представляет собой реализацию шаблонного класса myqueue, 
// который представляет собой очередь на основе динамического массива.
// В классе myqueue реализованы основные операции добавления и удаления элементов, 
// а также реализованы итераторы для обхода элементов очереди.

template<typename T>
class MyQueue {
	T* mm_pp{};					// указатель на массив элементов очереди
	size_t mm_nn{};				// количество элементов в очереди
	size_t mm_cap{};			// максимальная емкость очереди
	size_t mm_first{};			// индекс первого элемента в очереди
	const size_t delta{ 1 };	// размер увеличения емкости при переполнении

	// вложенный класс итератора
	class iterator {
		const MyQueue<T>* m_pQ; 
		int m_i;
	public:
		// чтобы для работы с очередью можно было использовать алгоритмы STL вводим псевдонимы
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		iterator() :m_pQ(nullptr), m_i(0) {};
		// конструктор итератора с указателем на очередь и индексом элемента
		iterator(const MyQueue& m_q, size_t q_n) :m_pQ(&m_q), m_i(q_n) {};

		// перегрузка оператора инкремента для перемещения на следующий элемент
		iterator& operator++ () {
			m_i++;
			return *this;
		};
		// перегрузка оператора разыменования для доступа к элементу
		T& operator* () { return m_pQ->mm_pp[m_i % (m_pQ->mm_cap)]; };
		// перегрузка оператора неравенства для сравнения двух итераторов
		bool operator!= (const iterator& in) const {
			return m_pQ != in.m_pQ || m_i != in.m_i;
		};
	};
public:
	// методы для получения итераторов на начало и конец очереди,
	// а также константные версии для использования в алгоритмах
	// Методы begin() и end() возвращают итераторы,
	// с помощью которых можно проходить по элементам коллекции от начала до конца.
	iterator begin() { return iterator(*this, mm_first); }
	iterator end() { return iterator(*this, mm_first + mm_nn); }

	//Методы cbegin() и cend() являются константными версиями методов begin() и end().
	// Они также возвращают итераторы, но с этими итераторами нельзя изменять элементы коллекции.
	// Они используются, когда нужно только просмотреть элементы коллекции без возможности изменения.
	iterator cbegin() const { return iterator(*this, mm_first); }
	iterator cend() const { return iterator(*this, mm_first + mm_nn); }

	// Создаем пустую очередь.
	MyQueue() = default;
	~MyQueue() { delete[] mm_pp; };

	MyQueue(const MyQueue& in) : mm_first(0), mm_cap(in.mm_nn), mm_nn(in.mm_nn) {
		mm_pp = new T[in.mm_nn];
		for (size_t i = 0; i < in.mm_nn; i++)
			mm_pp[i] = in.mm_pp[(in.mm_first + i) % in.mm_cap];
	}
	// конструктор перемещения для класса myqueue.
	MyQueue(MyQueue&& in) {
		mm_pp = in.mm_pp;
		mm_nn = in.mm_nn;
		mm_cap = in.mm_cap;
		mm_first = in.mm_first;

		in.mm_pp = nullptr;
		in.mm_nn = 0;
		in.mm_cap = 0;
		in.mm_first = 0;
	};

	// Создаем конструктор с использованием списка инициализации
	MyQueue(std::initializer_list<T> il) :mm_nn(il.size()), mm_cap(il.size()) {
		// Выделяем память для массива элементов
		mm_pp = new T[il.size()];
		size_t i = 0;
		// Копируем элементы из списка инициализации в массив
		std::copy(il.begin(), il.end(), mm_pp);
	};

	// Конструктор класса, принимающий размер очереди и начальный элемент
	MyQueue(size_t n, const T& node) {
		// Размер очереди
		mm_nn = n;
		// Емкость очереди
		mm_cap = n;
		// Индекс первого элемента в очереди
		mm_first = 0;
		// Указатель на массив элементов очереди
		mm_pp = new T[n];

		// Заполняем очередь начальным элементом
		for (size_t i = 0; i < n; i++) {
			mm_pp[i] = node;
		}
	};

	// оператор присваивания
	MyQueue& operator= (const MyQueue& in) {
		// Проверяем, достаточно ли памяти для копирования элементов из объекта in
		if (mm_cap < in.mm_nn)
		{
			delete[] mm_pp;				// Освобождаем ранее выделенную память
			mm_pp = new T[in.mm_nn];	// Выделяем новую память
			mm_cap = in.mm_nn;			// Обновляем значение вместимости
		}
		mm_first = 0;					// Обнуляем указатель на первый элемент
		mm_nn = in.mm_nn;				// Устанавливаем новое значение количества элементов

		std::copy(in.cbegin(), in.cend(), mm_pp);
		return *this;
	};

	MyQueue& operator= (MyQueue&& in) {
		// Проверяем, не является ли объект in самим собой
		if (&in == this) {
			return *this;
		}
		delete[] mm_pp;					// Освобождаем ранее выделенную память
		mm_pp = in.mm_pp;
		mm_nn = in.mm_nn;
		mm_cap = in.mm_cap;
		mm_first = in.mm_first;

		in.mm_pp = nullptr;
		in.mm_nn = 0;
		in.mm_cap = 0;
		in.mm_first = 0;
		return *this;
	};

	void addCapacity(size_t n) { 
	// Создание нового динамического массива с увеличенной ёмкостью
		T* newArr = new T[mm_cap + n];
		size_t i{ 0 };
		for (auto& j : *this)
		{
			newArr[i] = j;
			i++;
		}
		delete[] mm_pp;
		mm_pp = newArr;
		mm_first = 0;
		mm_cap += n;
	}

	void push(const T& in) {
	// Проверяем, достигли ли текущий размер контейнера его максимальной вместимости.
		if (mm_cap == mm_nn) {
			addCapacity(delta); // Если достигли, увеличиваем вместимость контейнера на delta.
		}
	// Добавляем элемент в контейнер по формуле (mm_first + mm_nn) % mm_cap,
	// чтобы обеспечить кольцевой буфер.
		mm_pp[(mm_first + mm_nn) % mm_cap] = in;
		mm_nn++; // Увеличиваем счетчик элементов контейнера.
	};
	void push(T&& in) {
	// Проверяем, достигли ли текущий размер контейнера его максимальной вместимости.
		if (mm_cap == mm_nn) {
			addCapacity(delta); // Если достигли, увеличиваем вместимость контейнера на delta.
		}
		mm_pp[(mm_first + mm_nn) % mm_cap] = std::move(in);
		mm_nn++;
	};

	// Инициализация функции pop() для извлечения элемента из очереди
	T pop() {
	// Проверяем, пуста ли очередь
		if (mm_nn == 0) {
			throw "empty queue"; // Выбрасываем исключение, если очередь пуста
		}
	// Сохраняем значение первого элемента во временную переменную
		T tmp = std::move(mm_pp[mm_first]);
	// Обновляем индекс первого элемента
		mm_first = (mm_first + 1) % mm_cap;
	// Уменьшаем количество элементов в очереди
		mm_nn--;
	// Возвращаем извлеченное значение
		return tmp;
	};

	void print() {
		std::cout << "\tКоличество э-тов очереди = " << mm_nn << " / ";
		std::cout << "Максимальная емкость =  " << mm_cap << std::endl;
		for (const auto& item : *this) {
			std::cout << item <<" ";
		}
		std::cout << std::endl;
	}
};

