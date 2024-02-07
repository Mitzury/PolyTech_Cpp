#pragma once
#include "Field.h"
#include "Snake.h"

struct Game {
    int delay; // �������� ����� ������ ����
    Field field; // ��������� �������� ����
    Snake snake; // ��������� ������

    ~Game();
    void startGame();

    void changeDirection(char key);

    void showMainMenu();

    void updateGame();

    void moveSnake();

};