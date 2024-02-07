#pragma once
#include "Field.h"

// Структура змейки
struct Snake {
    int size;
    struct coordinate {
        int x, y;
    } *snakeBody;
    char direction;

    void createSnake(Field& field);

};