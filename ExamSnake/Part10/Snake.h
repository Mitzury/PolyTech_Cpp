#pragma once

// Структура змейки
struct Snake {
    int size; // размер змейки
    struct coordinate {
        int x, y; // координаты точки змейки
    } *snakeBody; // массив координат змейки
    char direction; // направление движения змейки

    // создание змейки
    void createSnake();
};