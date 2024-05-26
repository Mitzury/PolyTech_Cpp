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
	const size_t delta{ 2 };	// размер увеличения емкости при переполнении

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
	iterator begin() { return iterator(*this, mm_first); }
	
	iterator end() {
		return iterator(*this, mm_first + mm_nn);
	}

	iterator cbegin() const { return iterator(*this, mm_first); }
	iterator cend() const {
		return iterator(*this, mm_first + mm_nn);
	}

	MyQueue() = default;
	~MyQueue() { delete[] mm_pp; };

	MyQueue(const MyQueue& in) : mm_first(0), mm_cap(in.mm_nn), mm_nn(in.mm_nn)
	{
		mm_pp = new T[in.mm_nn];

		for (size_t i = 0; i < in.mm_nn; i++)
			mm_pp[i] = in.mm_pp[(in.mm_first + i) % in.mm_cap];
	}
	MyQueue(MyQueue&& in) :mm_pp(in.mm_pp),
		mm_nn(in.mm_nn),
		mm_cap(in.mm_cap),
		mm_first(in.mm_first)
	{
		in.mm_pp = nullptr;
		in.mm_nn = 0;
		in.mm_cap = 0;
		in.mm_first = 0;
	};

	MyQueue(std::initializer_list<T> il) :mm_nn(il.size()), mm_cap(il.size())
	{
		mm_pp = new T[il.size()];
		size_t i = 0;

		std::copy(il.begin(), il.end(), mm_pp);
		

	};
	MyQueue(size_t n, const T& node) :mm_nn(n), mm_cap(n), mm_first(0)
	{
		mm_pp = new T[n];
		for (size_t i = 0; i < n; i++)
			mm_pp[i] = node;
	};

	MyQueue& operator= (const MyQueue& in) {
		if (mm_cap < in.mm_nn)
		{
			delete[] mm_pp;
			mm_pp = new T[in.mm_nn];
			mm_cap = in.mm_nn;
		}
		mm_first = 0;
		mm_nn = in.mm_nn;

		std::copy(in.cbegin(), in.cend(), mm_pp);
		return *this;
	};
	MyQueue& operator= (MyQueue&& in) {
		if (&in == this) return *this;
		delete[] mm_pp;
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

	void addCapasity(size_t n) { 
		T* newArr = new T[mm_cap + n];
		size_t i{ 0 };
		for (auto& no : *this)
		{
			newArr[i] = no;
			i++;
		}
		delete[] mm_pp;
		mm_pp = newArr;
		mm_first = 0;
		mm_cap += n;
	}

	void push(const T& in) {
		if (mm_cap == mm_nn) addCapasity(delta);
		mm_pp[(mm_first + mm_nn) % mm_cap] = in;
		mm_nn++;
	};
	void push(T&& in) {
		if (mm_cap == mm_nn) addCapasity(delta);
		mm_pp[(mm_first + mm_nn) % mm_cap] = std::move(in);
		mm_nn++;
	};
	T pop() {
		if (mm_nn == 0) throw "queue emty";
		T tmp1 = std::move(mm_pp[mm_first]);
		mm_first = (mm_first + 1) % mm_cap;
		mm_nn--;
		return tmp1;
	};

	void print() {
		for (const auto& item : *this) {
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}

};

