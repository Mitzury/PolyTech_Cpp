#pragma once

template<typename T>
class Range {
private:
    T min_value;         // ����������� �������� ���������
    T max_value;        // ������������ �������� ���������
public:
    // ����������� ������
    constexpr Range(T min, T max) : min_value(min), max_value(max) {}
    // ����� ��� ��������� ������������ �������� ���������
    constexpr T getMin() const { return min_value; }
    // ����� ��� ��������� ������������� �������� ���������
    constexpr T getMax() const { return max_value; }
    constexpr bool isInRange(T value) const {
        // ����� ��� ��������, ��������� �� ���������� �������� � �������� ���������
        return (value >= min_value && value <= max_value);
    }
    constexpr T clamp(T value) const {
        // ����� ��� "�������" �������� � �������� ���������
        return (value < min_value) ? min_value : (value > max_value) ? max_value : value;
    }
};
