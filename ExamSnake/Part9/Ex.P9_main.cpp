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

// Добавленный метод для настройки размера поля
void setFieldSize(int& width, int& height) {
    cout << "Введите новые размеры поля (ширина высота): ";
    cin >> width >> height;
}

// Главная функция игры
int main() {
    setlocale(LC_ALL, "ru");

    Game game;
    int choice;

    do {
        showMainMenu();
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
        case 1:
            game.startGame();
            break;
        case 2:
            cout << "Установить размер поля" << endl;
            setFieldSize(WIDTH, HEIGHT);
            break;
        case 3:
            cout << "До свидания!" << endl;
            return 0;
        default:
            cout << "Неправильный выбор." << endl;
            break;
        }

        // Очистка буфера ввода
        cin.clear();
        cin.ignore();

        cout << "Нажмите Enter, чтобы продолжить...";

        cin.get();
    } while (true);
        return 0;
}

