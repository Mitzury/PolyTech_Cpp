#include <iostream>
#include <conio.h> // Для функции _getch()
#include "Game.h"
#include "Const.h"

using namespace std;

// Функция для отображения главного меню
void showMainMenu() {
    system("cls");  // Очищаем консоль перед выводом меню
    cout << "1) Начать игру" << endl;
    cout << "2) Настройки размера поля" << endl;
    cout << "3) Выйти" << endl;
}

// Главная функция игры
int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    game.showMainMenu();

    return 0;
}

