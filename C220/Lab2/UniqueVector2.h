#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>

// ����� uniquevector �������� �������� ��� std::vector � ��������� �������������� ���������, 
// � ������, �����������, ��� ������ �������� ������ ���������� ��������.
template <typename T>
class UniqueVector : protected std::vector<T> {
private:
    T min_value;
    T max_value;
    // ����� ��� ��������, ����� �� �������� �������� � ������
    bool should_add_value(const T& value) const;

public:
    UniqueVector() = delete;                           // ������� ������ ������ uniquevector � ������ ��������.
    UniqueVector(const UniqueVector& inp)
    {
     
    }//= default;        // ����������� �����������
    UniqueVector& operator=(const UniqueVector&) = default;  // �������� ������������ 
    UniqueVector(UniqueVector&&) = default;             // ����������� �����������
    UniqueVector& operator=(UniqueVector&&) = default;  // �������� �����������
    ~UniqueVector() = default;


    // �����������, ����������� ����������� � ������������ ��������,
    // � ����� ������ �������������
    UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list);
    // ���������� ��������� �� ������ �������������
    void add(std::initializer_list<T> init_list);

    // ���������� ��������� �� ��������� [first, last)
    template <typename InputIterator>
    void add(InputIterator first, InputIterator last);

    // �������� ���������, ��������� � ������� to_remove, �������� size
    void remove(const T to_remove[], std::size_t size);
    // ��������� ��������� �������� [min, max]
    void set_range(T min, T max);

    // ���������� ��������� � ������� � �������������� ����������� comp
    template <typename Comparator>
    void sort(Comparator comp);

    // ����������� ��������� � ������ outputiterator
    template <typename OutputIterator>
    void copy_to(OutputIterator result) const;

    using std::vector<T>::begin;
    using std::vector<T>::end;

    //auto begin() { return vector<T>::begin(); }; 
    //auto end() { return vector<T>::end(); }; 

    // ���������� ��������� ������ ��� �������� ������ ����������� UniqueVector � �����.
    friend std::ostream& operator<<(std::ostream& os, const UniqueVector& uv) {
        for (const T& value : uv) {
            os << value << " ";
        }
        return os;
    }
};

template <typename T>
bool UniqueVector<T>::should_add_value(const T& value) const {
    // ���������, ��� �������� ��������� � ��������� [min_value, max_value]
    // � ��� ��� ��� � �������
    return (value >= min_value && value <= max_value) &&
        (std::find(this->begin(), this->end(), value) == this->end());
}


template <typename T>
UniqueVector<T>::UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list)
    : min_value(min), max_value(max) {
    // ����������� ������ ��� ������ � ��������� ��������
    this->reserve(init_list.size());
    add(init_list.begin(), init_list.end());
}

template <typename T>
void UniqueVector<T>::add(std::initializer_list<T> init_list) {
    for (const T& value : init_list) {
        // ���� ����� �������� ��������, ��������� ��� � ������
        if (should_add_value(value)) {
            this->push_back(value);
        }
    }
}

template <typename T>
template <typename InputIterator>
void UniqueVector<T>::add(InputIterator first, InputIterator last) {
    for (InputIterator it = first; it != last; ++it) {
        // ���� ����� �������� ��������, ��������� ��� � ������
        if (should_add_value(*it)) {
            this->push_back(*it);
        }
    }
}

template <typename T>
void UniqueVector<T>::remove(const T to_remove[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        // ���� ������� � ������� � ������� ���
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
    // ������������� ����� �������� ������������ � �������������
    // � ������� ��������, �� ���������� � ����� ��������
    this->erase(std::remove_if(this->begin(), this->end(), [this](const T& value) {
        return value < min_value || value > max_value;
        }), this->end());
}

template <typename T>
template <typename Comparator>
// ��������� ������ � �������������� �����������
void UniqueVector<T>::sort(Comparator comp) {
    std::sort(this->begin(), this->end(), comp);
}

template <typename T>
template <typename OutputIterator>
void UniqueVector<T>::copy_to(OutputIterator result) const {
    std::copy(this->begin(), this->end(), result);
}
