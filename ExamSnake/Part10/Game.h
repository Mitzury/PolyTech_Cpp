#pragma once
#include "Field.h"
#include "Snake.h"

struct Game {
    int delay; // Задержка между шагами игры
    Field field; // Экземпляр игрового поля
    Snake snake; // Экземпляр змейки

    void startGame();
    void changeDirection();
    void updateGame();
    void moveSnake();
};