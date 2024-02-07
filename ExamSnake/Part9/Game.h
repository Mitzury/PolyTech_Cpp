#pragma once
#include "Field.h"
#include "Snake.h"

struct Game {
    int delay; // Задержка между шагами игры
    Field field; // Экземпляр игрового поля
    Snake snake; // Экземпляр змейки

    ~Game();
    void startGame();

    void changeDirection(char key);

    void showMainMenu();

    void updateGame();

    void moveSnake();

};