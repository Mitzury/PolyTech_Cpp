#include <iostream>
#include <conio.h> // Для функции _getch()
#include "Game.h"
#include "Const.h"
#include <Windows.h>

using namespace std;

void setCursorPosition(int x, int y)
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static bool init = false;
	if (!init) {				// скрываем курсор
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hConsole, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &structCursorInfo);
		init = true;
	}
	COORD position = { x, y }; // устанавливаем в нужную позицию
	SetConsoleCursorPosition(hConsole, position);
}

// Функция для отображения главного меню
void showMainMenu() {
    //system("cls");  // Очищаем консоль перед выводом меню
    cout << "1) Начать игру" << endl;
    cout << "2) Настройки размера поля" << endl;
    cout << "3) Выйти" << endl;
}

// Главная функция игры
int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    do {
        game.showMainMenu();
    } while (true);
   

    return 0;
}

