#include <iostream>
#include "const.h"


int snake_size;  // Текущий размер змейки

// Инициализация змейки
void initializeSnake() {
    snake_size = 1;  // Начальный размер змейки
    head_position = 0;  // Начальная позиция головы
}


// Движение змейки
void moveSnake() {
    // Увеличиваем позицию головы
    head_position++;

    // Проверяем, достигла ли змейка границы
    if (head_position >= columns) {
        // Змейка достигла границы, начинаем заново
        head_position = 0;
    }
}

// Отрисовка змейки
void drawSnake() {
    // Выводим пробелы перед головой
    for (int i = 0; i < head_position; i++) {
        std::cout << ' ';
    }

    // Выводим голову
    std::cout << head_symbol << std::endl;

    // Выводим хвост
    for (int i = 0; i < snake_size - 1; i++) {
        std::cout << tail_symbol << std::endl;
    }
}