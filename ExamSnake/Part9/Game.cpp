#include "Game.h"
#include <iostream>

void Game::startGame()
{
    // ���� �������� ����
    std::cout << "Enter width: ";
    std::cin >> field.X;
    std::cout << "Enter height: ";
    std::cin >> field.Y;
    // �������� ����
    field.createField();
    // ����� ���� �� �����
    field.printField();
}
