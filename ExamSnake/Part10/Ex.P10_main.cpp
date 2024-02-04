#include <iostream>
#include <conio.h> // Для функции _getch()
#include "Const.h"
#include "Game.h"

using namespace std;

// Главная функция игры
int main() {
        setlocale(LC_ALL, "ru");

        Game game;
        game.startGame();
        game.delay = 2000; // Задержка в 250 миллисекунд между шагами игры
        return 0;
}

