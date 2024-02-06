#include <iostream>
#include "const.h"
#include "snake.h"
#include <Windows.h>

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