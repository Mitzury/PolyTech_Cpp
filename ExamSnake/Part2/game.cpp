#include <iostream>
#include "const.h"
#include "snake.h"
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