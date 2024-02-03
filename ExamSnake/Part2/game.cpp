#include <iostream>
#include <cstdlib>
#include <windows.h>  // Для функции system("cls")
#include "const.h"
#include "snake.h"

// Начало игры
void startGame() {
    initializeSnake();

    while (true) {
        system("cls");  // Очистка экрана

        moveSnake();
        drawSnake();

        Sleep(timeout);  // Задержка между шагами игры
    }
}