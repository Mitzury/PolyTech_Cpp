#pragma once
#include "Field.h"

// ��������� ������
struct Snake {
    int size;
    struct coordinate {
        int x, y;
    } *snakeBody;
    char direction;

    void createSnake(Field& field);

};