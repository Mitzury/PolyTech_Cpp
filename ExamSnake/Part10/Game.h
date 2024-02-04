#pragma once
#include "Field.h"
#include "Snake.h"

struct Game {
    int delay; // �������� ����� ������ ����
    Field field; // ��������� �������� ����
    Snake snake; // ��������� ������

    void startGame();
    void changeDirection();
    void updateGame();
    void moveSnake();
};