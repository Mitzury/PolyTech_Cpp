#include <iostream>
#include <cstdlib>
#include <windows.h>  // ��� ������� system("cls")
#include "const.h"
#include "snake.h"

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