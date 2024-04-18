#pragma once
#include <iostream>

template <typename T>
void Swap(T& a, T& b)
{
	if (&a != &b) { // ���������, ��� ���������� ��������
		T temp = std::move(a);
		a = std::move(b);
		b = std::move(temp);
	}
}
