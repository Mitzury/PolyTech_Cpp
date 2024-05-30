#pragma once

template<typename T>
class Range {
private:
    T min_value;         // ћинимальное значение диапазона
    T max_value;        // ћаксимальное значение диапазона
public:
    //  онструктор класса
    constexpr Range(T min, T max) : min_value(min), max_value(max) {}
    // ћетод дл€ получени€ минимального значени€ диапазона
    constexpr T getMin() const { return min_value; }
    // ћетод дл€ получени€ максимального значени€ диапазона
    constexpr T getMax() const { return max_value; }
    constexpr bool isInRange(T value) const {
        // ћетод дл€ проверки, находитс€ ли переданное значение в пределах диапазона
        return (value >= min_value && value <= max_value);
    }
    constexpr T clamp(T value) const {
        // ћетод дл€ "зажати€" значени€ в пределах диапазона
        return (value < min_value) ? min_value : (value > max_value) ? max_value : value;
    }
};
