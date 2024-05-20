#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

template <typename T>
class UniqueVector : protected std::vector<T> {
private:
    T min_value;
    T max_value;
    bool should_add_value(const T& value) const;

public:
    UniqueVector() = default;
    UniqueVector(const UniqueVector&) = default;
    UniqueVector& operator=(const UniqueVector&) = default;
    UniqueVector(UniqueVector&&) = default;
    UniqueVector& operator=(UniqueVector&&) = default;

    UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list);
    void add(std::initializer_list<T> init_list);

    template <typename InputIterator>
    void add(InputIterator first, InputIterator last);

    void remove(const T to_remove[], std::size_t size);
    void set_range(T min, T max);

    template <typename Comparator>
    void sort(Comparator comp);

    template <typename OutputIterator>
    void copy_to(OutputIterator result) const;

    typename std::vector<T>::const_iterator begin() const;
    typename std::vector<T>::const_iterator end() const;

    // Перегрузка оператора вывода для удобного вывода содержимого UniqueVector в поток.
    friend std::ostream& operator<<(std::ostream& os, const UniqueVector& uv) {
        for (const T& value : uv.data) {
            os << value << " ";
        }
        return os;
    }
};

template <typename T>
bool UniqueVector<T>::should_add_value(const T& value) const {
    return (value >= min_value && value <= max_value) &&
        (std::find(this->data.begin(), this->data.end(), value) == this->data.end());
}

template <typename T>
UniqueVector<T>::UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list)
    : min_value(min), max_value(max) {
    this->data.reserve(init_list.size());
    add(init_list.begin(), init_list.end());
}

template <typename T>
void UniqueVector<T>::add(std::initializer_list<T> init_list) {
    for (const T& value : init_list) {
        if (should_add_value(value)) {
            this->data.push_back(value);
        }
    }
}

template <typename T>
template <typename InputIterator>
void UniqueVector<T>::add(InputIterator first, InputIterator last) {
    for (InputIterator it = first; it != last; ++it) {
        if (should_add_value(*it)) {
            this->data.push_back(*it);
        }
    }
}

template <typename T>
void UniqueVector<T>::remove(const T to_remove[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        auto it = std::find(this->data.begin(), this->data.end(), to_remove[i]);
        if (it != this->data.end()) {
            this->data.erase(it);
        }
    }
}

template <typename T>
void UniqueVector<T>::set_range(T min, T max) {
    min_value = min;
    max_value = max;
    this->data.erase(std::remove_if(this->data.begin(), this->data.end(), [this](const T& value) {
        return value < min_value || value > max_value;
        }), this->data.end());
}

template <typename T>
template <typename Comparator>
void UniqueVector<T>::sort(Comparator comp) {
    std::sort(this->data.begin(), this->data.end(), comp);
}

template <typename T>
template <typename OutputIterator>
void UniqueVector<T>::copy_to(OutputIterator result) const {
    std::copy(this->data.begin(), this->data.end(), result);
}

template <typename T>
typename std::vector<T>::const_iterator UniqueVector<T>::begin() const { return data.cbegin(); }

template <typename T>
typename std::vector<T>::const_iterator UniqueVector<T>::end() const { return data.cend(); }

