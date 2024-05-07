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

// Функция для печати элементов контейнера
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // итерация по контейнеру
        std::cout << elem << " "; // вывод элемента
    }
    std::cout << std::endl; // переход на новую строку
}

template<typename Cont>
void NegateAll(Cont& cont)
{
    cout << "a";
}