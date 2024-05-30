#pragma once

template<typename T>
class MultiValue
{
	T min;
	T max;
public:
	constexpr mmx(const T& mn, const T& mx) :min(mn), max(mx) {};
	constexpr bool isIn(const T& in) const { return in >= min && in <= max; }
	constexpr T getMin() const { return min; }
	constexpr T getMax() const { return max; }
	constexpr T inInD(const T& in) const {
		return ((in < min) ? min : ((in > max) ? max : in));
	}
};