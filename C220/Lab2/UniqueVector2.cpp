#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

template <typename T>
class UniqueVector : public std::vector<T> {
private:
    T min_value;
    T max_value;

    // Проверка диапазона и уникальности
    bool should_add_value(const T& value) const {
        return (value >= min_value && value <= max_value) &&
            (std::find(this->begin(), this->end(), value) == this->end());
    }
public:
    // Конструктор с диапазоном и списком инициализации
    UniqueVector(T min, T max, const T init_list[], std::size_t size)
        : min_value(min), max_value(max) {
        add(init_list, size);
    }
    // Метод добавления значений из массива
    void add(const T new_values[], std::size_t size) {
        for (std::size_t i = 0; i < size; ++i) {
            if (should_add_value(new_values[i])) {
                this->push_back(new_values[i]);
            }
        }
    }
    // Метод добавления произвольного количества значений из диапазона итераторов
    template <typename InputIterator>
    void add(InputIterator first, InputIterator last) {
        for (InputIterator it = first; it != last; ++it) {
            if (should_add_value(*it)) {
                this->push_back(*it);
            }
        }
    }
    // Метод удаления значений из массива
    void remove(const T to_remove[], std::size_t size) {
        for (std::size_t i = 0; i < size; ++i) {
            auto it = std::find(this->begin(), this->end(), to_remove[i]);
            if (it != this->end()) {
                this->erase(it);
            }
        }
    }
    // Метод изменения диапазона
    void set_range(T min, T max) {
        min_value = min;
        max_value = max;
        this->erase(std::remove_if(this->begin(), this->end(), [this](const T& value) {
            return value < min_value || value > max_value;
            }), this->end());
    }
    // Метод сортировки с использованием компаратора
    template <typename Comparator>
    void sort(Comparator comp) {
        std::sort(this->begin(), this->end(), comp);
    }
    // Копирование значений в другой контейнер
    template <typename OutputIterator>
    void copy_to(OutputIterator result) const {
        std::copy(this->begin(), this->end(), result);
    }
    // Копирование и перемещение запрещены
    UniqueVector(const UniqueVector&) = delete;
    UniqueVector& operator=(const UniqueVector&) = delete;
    UniqueVector(UniqueVector&&) = delete;
    UniqueVector& operator=(UniqueVector&&) = delete;
    // Конструктор по умолчанию
    UniqueVector() = default;

};