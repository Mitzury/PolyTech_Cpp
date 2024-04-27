#include <iostream>
#include "const.h"
#include "snake.h"

int head_position;
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

	if (head_position > snake_size) // если длина змейки меньше ее позиции
	{
		for (int i = 0; i < head_position - snake_size; ++i) // рисуем необходимое количество пробелов
		{
			std::cout << ' ';
		}
	}

	if (head_position < snake_size) // если змейка не вся видна в начале
	{
		for (int i = 0; i < head_position; ++i) // рисуем хвост
		{
			std::cout << tail_symbol;
		}
	}
	else if (head_position >= snake_size) // если змейка вся выползла
	{
		for (int i = 0; i < snake_size - 1; ++i) // рисуем хвост
		{
			std::cout << tail_symbol;
		}
	}
	std::cout << head_symbol;  // рисуем голову

	for (int i = 1; i < (columns - head_position); ++i) // рисуем остатки поля
	{
		std::cout << ' ';
	}

	++head_position;

}