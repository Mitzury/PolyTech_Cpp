#include <iostream>
#include "const.h"
#include "snake.h"
#include "game.h"
#include <Windows.h>

// ������ ����
void startGame() {
    initializeSnake();

    while (true) {
        system("cls");  // ������� ������

        moveSnake();
        drawSnake();

        Sleep(timeout);  // �������� ����� ������ ����
    }
}