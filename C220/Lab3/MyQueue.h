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
	T* m_pp = nullptr;			// указатель на массив элементов очереди
	size_t m_nn = 0;			// количество элементов в очереди
	size_t m_cap = 0;			// максимальная емкость очереди
	size_t m_first = 0;			// индекс первого элемента в очереди
	const size_t delta = 1;	// размер увеличения емкости при переполнении

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
		// Возвращаем элемент массива m_pp по индексу m_i, учитывая размер массива m_cap
		T& operator* () { return m_pQ->m_pp[m_i % (m_pQ->m_cap)]; };
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
	iterator begin() { return iterator(*this, m_first); }
	iterator end() { return iterator(*this, m_first + m_nn); }

	iterator begin() const { return iterator(*this, m_first); }
	iterator end() const { return iterator(*this, m_first + m_nn); }


	//Методы cbegin() и cend() являются константными версиями методов begin() и end().
	// Они также возвращают итераторы, но с этими итераторами нельзя изменять элементы коллекции.
	// Они используются, когда нужно только просмотреть элементы коллекции без возможности изменения.
	iterator cbegin() const { return iterator(*this, m_first); }
	iterator cend() const { return iterator(*this, m_first + m_nn); }

	// Создаем пустую очередь.
	MyQueue() = default;
	~MyQueue() { delete[] m_pp; };

	MyQueue(const MyQueue& que) : m_first(0), m_cap(que.m_nn), m_nn(que.m_nn) {

		m_pp = new T[que.m_nn];
		for (size_t i = 0; i < que.m_nn; i++)
			m_pp[i] = que.m_pp[(que.m_first + i) % que.m_cap];
	}


	// конструктор перемещения для класса myqueue.
	MyQueue(MyQueue&& que) {
		m_pp = que.m_pp;
		m_nn = que.m_nn;
		m_cap = que.m_cap;
		m_first = que.m_first;

		que.m_pp = nullptr;
		que.m_nn = 0;
		que.m_cap = 0;
		que.m_first = 0;
	};

	// Создаем конструктор с использованием списка инициализации
	MyQueue(std::initializer_list<T> il) :m_nn(il.size()), m_cap(il.size()) {
		// Выделяем память для массива элементов
		m_pp = new T[il.size()];
		size_t i = 0;
		// Копируем элементы из списка инициализации в массив
		std::copy(il.begin(), il.end(), m_pp);
	};

	// Конструктор класса, принимающий размер очереди и начальный элемент
	MyQueue(size_t n, const T& node) {
		// Размер очереди
		m_nn = n;
		// Емкость очереди
		m_cap = n;
		// Индекс первого элемента в очереди
		m_first = 0;
		// Указатель на массив элементов очереди
		m_pp = new T[n];

		// Заполняем очередь начальным элементом
		for (size_t i = 0; i < n; i++) {
			m_pp[i] = node;
		}
	};

	// оператор присваивания
	MyQueue& operator= (const MyQueue& que) {
		// Проверяем, достаточно ли памяти для копирования элементов из объекта
		if (m_cap < que.m_nn)
		{
			delete[] m_pp;				// Освобождаем ранее выделенную память
			m_pp = new T[que.m_nn];	// Выделяем новую память
			m_cap = que.m_nn;			// Обновляем значение вместимости
		}
		m_first = 0;					// Обнуляем указатель на первый элемент
		m_nn = que.m_nn;				// Устанавливаем новое значение количества элементов

		std::copy(que.cbegin(), que.cend(), m_pp);
		return *this;
	};

	MyQueue& operator= (MyQueue&& que) {
		// Проверяем, не является ли объект que самим собой
		if (&que == this) {
			return *this;
		}
		delete[] m_pp;					// Освобождаем ранее выделенную память
		m_pp = que.m_pp;
		m_nn = que.m_nn;
		m_cap = que.m_cap;
		m_first = que.m_first;

		que.m_pp = nullptr;
		que.m_nn = 0;
		que.m_cap = 0;
		que.m_first = 0;
		return *this;
	};

	void addCapacity(size_t n) {
		// Создание нового динамического массива с увеличенной ёмкостью
		T* newArr = new T[m_cap + n];
		size_t i{ 0 };
		//for (auto& j : *this)
		//{
		//	newArr[i] = j;
		//	i++;
		//}
		for (auto it = begin(); it != end(); ++it) {
			newArr[i] = *it;
			i++;
		}
		delete[] m_pp;
		m_pp = newArr;
		m_first = 0;
		m_cap += n;
	}

	void push(const T& in) {
		// Проверяем, достигли ли текущий размер контейнера его максимальной вместимости.
		if (m_cap == m_nn) {
			addCapacity(delta); // Если достигли, увеличиваем вместимость контейнера на delta.
		}
		// Добавляем элемент в контейнер по формуле (m_first + m_nn) % m_cap,
		// чтобы обеспечить кольцевой буфер.
		m_pp[(m_first + m_nn) % m_cap] = in;
		m_nn++; // Увеличиваем счетчик элементов контейнера.
	};


	// Инициализация функции pop() для извлечения элемента из очереди
	T pop() {
		if (m_nn > 0) {

			// Сохраняем значение первого элемента во временную переменную
			T tmp = std::move(m_pp[m_first]);
			// Обновляем индекс первого элемента
			m_first = (m_first + 1) % m_cap;
			// Уменьшаем количество элементов в очереди
			m_nn--;

			// Возвращаем извлеченное значение
			return tmp;
		}
	};

	void print() const {
		std::cout << "\tКоличество э-тов очереди = " << m_nn << " / ";
		std::cout << "Максимальная емкость =  " << m_cap << " / ";
		std::cout << "m_first =  " << m_first << std::endl;
		for (const auto& item : *this) {
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}
	//void print() const {
	//	std::cout << "Queue: ";
	//	// Создаем объекты итератора для первого и последнего элементов очереди
	//	iterator begin(*this, m_first);
	//	iterator end(*this, m_first + m_nn);
	//	// Итерируемся по очереди и выводим элементы на экран
	//	for (iterator it = begin; it != end; ++it) {
	//		std::cout << *it << " ";
	//	}
	//	std::cout << std::endl;
	//}
};