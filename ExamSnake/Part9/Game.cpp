#include "Game.h"
#include <iostream>

void Game::startGame()
{
    // Ввод размеров поля
    std::cout << "Enter width: ";
    std::cin >> field.X;
    std::cout << "Enter height: ";
    std::cin >> field.Y;
    // Создание поля
    field.createField();
    // Вывод поля на экран
    field.printField();
}
