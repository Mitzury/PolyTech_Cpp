#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

// Класс uniquevector является оберткой над std::vector и добавляет дополнительное поведение, 
// а именно, гарантирует, что вектор содержит только уникальные элементы.
template <typename T>
class UniqueVector : protected std::vector<T> {
private:
    T min_value;
    T max_value;
    // Метод для проверки, нужно ли добавить значение в вектор
    bool should_add_value(const T& value) const;

public:
    UniqueVector() = delete;                           // создает объект класса uniquevector с пустым вектором.
    UniqueVector(const UniqueVector& inp)
    {
     
    }//= default;        // Конструктор копирования
    UniqueVector& operator=(const UniqueVector&) = default;  // Оператор присваивания 
    UniqueVector(UniqueVector&&) = default;             // Конструктор перемещения
    UniqueVector& operator=(UniqueVector&&) = default;  // Оператор перемещения
    ~UniqueVector() = default;


    // Конструктор, принимающий минимальное и максимальное значение,
    // а также список инициализации
    UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list);
    // Добавление элементов из списка инициализации
    void add(std::initializer_list<T> init_list);

    // Добавление элементов из диапазона [first, last)
    template <typename InputIterator>
    void add(InputIterator first, InputIterator last);

    // Удаление элементов, указанных в массиве to_remove, размером size
    void remove(const T to_remove[], std::size_t size);
    // Установка диапазона значений [min, max]
    void set_range(T min, T max);

    // Сортировка элементов в векторе с использованием компаратора comp
    template <typename Comparator>
    void sort(Comparator comp);

    // Копирование элементов в вектор outputiterator
    template <typename OutputIterator>
    void copy_to(OutputIterator result) const;

    using std::vector<T>::begin;
    using std::vector<T>::end;

    //auto begin() { return vector<T>::begin(); }; 
    //auto end() { return vector<T>::end(); }; 

    // Перегрузка оператора вывода для удобного вывода содержимого UniqueVector в поток.
    friend std::ostream& operator<<(std::ostream& os, const UniqueVector& uv) {
        for (const T& value : uv) {
            os << value << " ";
        }
        return os;
    }
};

template <typename T>
bool UniqueVector<T>::should_add_value(const T& value) const {
    // Проверяем, что значение находится в диапазоне [min_value, max_value]
    // и что его нет в векторе
    return (value >= min_value && value <= max_value) &&
        (std::find(this->begin(), this->end(), value) == this->end());
}


template <typename T>
UniqueVector<T>::UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list)
    : min_value(min), max_value(max) {
    // Резервируем память для списка и добавляем элементы
    this->reserve(init_list.size());
    add(init_list.begin(), init_list.end());
}

template <typename T>
void UniqueVector<T>::add(std::initializer_list<T> init_list) {
    for (const T& value : init_list) {
        // Если нужно добавить значение, добавляем его в вектор
        if (should_add_value(value)) {
            this->push_back(value);
        }
    }
}

template <typename T>
template <typename InputIterator>
void UniqueVector<T>::add(InputIterator first, InputIterator last) {
    for (InputIterator it = first; it != last; ++it) {
        // Если нужно добавить значение, добавляем его в вектор
        if (should_add_value(*it)) {
            this->push_back(*it);
        }
    }
}

template <typename T>
void UniqueVector<T>::remove(const T to_remove[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        // Ищем элемент в векторе и удаляем его
        auto it = std::find(this->begin(), this->end(), to_remove[i]);
        if (it != this->end()) {
            this->erase(it);
        }
    }
}

template <typename T>
void UniqueVector<T>::set_range(T min, T max) {
    min_value = min;
    max_value = max;
    // Устанавливаем новые значения минимального и максимального
    // и удаляем элементы, не попадающие в новый диапазон
    this->erase(std::remove_if(this->begin(), this->end(), [this](const T& value) {
        return value < min_value || value > max_value;
        }), this->end());
}

template <typename T>
template <typename Comparator>
// Сортируем вектор с использованием компаратора
void UniqueVector<T>::sort(Comparator comp) {
    std::sort(this->begin(), this->end(), comp);
}

template <typename T>
template <typename OutputIterator>
void UniqueVector<T>::copy_to(OutputIterator result) const {
    std::copy(this->begin(), this->end(), result);
}
