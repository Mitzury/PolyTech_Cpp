#pragma once
#include <bitset>
#include <vector>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
}

constexpr int binary_literal(const char* str) {
    int result = 0;
    while (*str) {
        result = (result << 1) + (*str++ - '0');
    }
    return result;
}
//Функция operator "" _b будет вызываться для строкового литерала с суффиксом _b, 
// например, "100000000"_b.Она передает строковый литерал в функцию binary_literal, 
// которая преобразует двоичное число в десятичное значение.
constexpr int operator "" _b(const char* str, size_t) {
    return binary_literal(str);
}

std::string to_binary_string(int value) {
    std::string binary;
    const int num_bits = sizeof(int) * CHAR_BIT;
    for (int i = num_bits - 1; i >= 0; --i) {
        binary.push_back(((value >> i) & 1) ? '1' : '0');
    }
    return "0b" + binary;
}

std::string operator""_toBinStr(unsigned long long num) {
    return to_binary_string(static_cast<int>(num));
}


template<typename T>
class Range {
private:
    T min_value;
    T max_value;
public:
    constexpr Range(T min, T max) : min_value(min), max_value(max) {}
    constexpr T getMin() const { return min_value; }
    constexpr T getMax() const { return max_value; }
    constexpr bool isInRange(T value) const {
        return (value >= min_value && value <= max_value);
    }
    constexpr T clamp(T value) const {
        return (value < min_value) ? min_value : (value > max_value) ? max_value : value;
    }
};


template<typename T>
void printSequence(const T& container) {
    for (const auto& item : container) {
        if constexpr (std::is_pointer_v<typename T::value_type>) {
            std::cout << *item << " ";
        }
        else {
            std::cout << item << " ";
        }
    }
    std::cout << std::endl;
}
template<typename T, size_t N>
void printSequence(const T(&arr)[N]) {
    for (const auto& item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


template<typename T1, typename T2>
auto add(T1 a, T2 b) {
    if constexpr (std::is_same<T1, std::vector<T2>>::value) {
        for (auto& element : a) {
            element += b;
        }
        return a;
    }
    else {
        return a + b;
    }
}


template <typename T>
void printAdapter(std::stack<T> stack) {
    while (!stack.empty()) {
        printValue(stack.top());
        stack.pop();
    }
    std::cout << std::endl;
}

template <typename T>
void printAdapter(std::queue<T> queue) {
    while (!queue.empty()) {
        printValue(queue.front());
        queue.pop();
    }
    std::cout << std::endl;
};