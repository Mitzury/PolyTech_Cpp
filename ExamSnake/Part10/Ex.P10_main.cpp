#include <iostream>
#include <conio.h> // Для функции _getch()
#include "Const.h"
#include "Game.h"

using namespace std;

// Функция для отображения главного меню
void showMainMenu() {
    system("cls");
    std::cout << "1) Начало игры" << std::endl;
    std::cout << "2) Настройка игры" << std::endl;
    std::cout << "3) Топ" << std::endl;
    std::cout << "4) Выход" << std::endl;
}

// Главная функция игры
int main() {
        setlocale(LC_ALL, "ru");

        int choice;
        showMainMenu();
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Game game;
            game.startGame();
            game.delay = 2000; // Задержка в 250 миллисекунд между шагами игры
            break;
        default:
            std::cout << "Неправильный выбор." << std::endl;
        case 4:
            exit;
        }
        return 0;
}

