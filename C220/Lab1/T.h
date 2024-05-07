#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cctype>
#include <cmath>
#include <functional>
#include <type_traits>

// ������� ��� ������ ��������� ����������
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // �������� �� ����������
        std::cout << elem << " "; // ����� ��������
    }
    std::cout << std::endl; // ������� �� ����� ������
}

template<typename Cont>
void NegateAll(Cont& cont)
{
    cout << "a";
}