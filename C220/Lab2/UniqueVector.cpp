#include <vector>
#include <algorithm>
#include <iostream>



template <typename T>
class UniqueVector {
private:
    std::vector<T> values;
    T min_value;
    T max_value;

    // �������� ��������� � ������������
    bool should_add_value(const T& value) const {
        return (value >= min_value && value <= max_value) &&
            (std::find(values.begin(), values.end(), value) == values.end());
    }

public: // �� ������� //inis list
    // ����������� � ���������� � ������� �������������
    UniqueVector(const T& min, const T& max, std::initializer_list<T> init_list)
        : min_value(min), max_value(max) {
        values.reserve(init_list.size());
        add(init_list);
        
    }
    // ���������� �������� �� �������
    void add(std::initializer_list<T> init_list) {
        values.reserve(init_list.size() + values.size());

        for (init_ i = 0; i < size; ++i) {
            if (should_add_value(new_values[i])) {
                values.push_back(new_values[i]);
            }
        }
    }
    // operator << ����������
    template<typename Container>
    void PrintAnyCont(const Container& container) {
        for (const auto& element : container) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // ���������� ������������� ���������� �������� �� ��������� ����������
    template <typename InputIterator>
    void add(InputIterator first, InputIterator last) {
        for (InputIterator it = first; it != last; ++it) {
            if (should_add_value(*it)) {
                values.push_back(*it);
            }
        }
    }
    // �������� �������� �� �������
    void remove(const T to_remove[], std::size_t size) {
        for (std::size_t i = 0; i < size; ++i) {
            typename std::vector<T>::iterator it = std::find(values.begin(), values.end(), to_remove[i]);
            if (it != values.end()) {
                values.erase(it);
            }
        }
    }
    // ��������� ���������
    void set_range(T min, T max) {
        min_value = min;
        max_value = max;
        values.erase(std::remove_if(values.begin(), values.end(), [this](const T& value) {
            return value < min_value || value > max_value;
            }), values.end());
    }
    // ����������
    template <typename Comparator>
    void sort(Comparator comp) {
        std::sort(values.begin(), values.end(), comp);
    }
    // ������ � ������� ��� ����������� � ������ ��������
    typename std::vector<T>::const_iterator begin() const { return values.cbegin(); }
    typename std::vector<T>::const_iterator end() const { return values.cend(); }


    //// ������ ��������
    ~UniqueVector() 
    //// ����������� � ����������� ���������
    //UniqueVector(const UniqueVector&) = delete;
    //UniqueVector& operator=(const UniqueVector&) = delete;
    //UniqueVector(UniqueVector&&) = delete;
    //UniqueVector() = default; // ���� ��������� ����������� ������������� ����������
};