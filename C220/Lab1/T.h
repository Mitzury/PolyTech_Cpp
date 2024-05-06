#pragma once
// Функция для печати элементов контейнера
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // итерация по контейнеру
        std::cout << elem << " "; // вывод элемента
    }
    std::cout << std::endl; // переход на новую строку
}