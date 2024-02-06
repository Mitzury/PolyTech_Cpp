#include "Game.h"
#include <iostream>
#include <conio.h>

void Game::startGame()
{
    // Ввод размеров поля
    std::cout << "Enter width: ";
    std::cin >> field.X;
    std::cout << "Enter height: ";
    std::cin >> field.Y;
    // Создание поля
    field.createField();
    // Вывод поля на экран
    field.printField();
    // Создание змейки
    snake.size = 1;
    snake.createSnake();
    // Цикл игры
    while (true) {
        field.printField(); // Вывод поля на экран
        updateGame(); // Обновление состояния игры
        if (_kbhit()) { // Проверка на нажатие клавиши
            changeDirection(); // Изменение направления движения змейки

        }
    }
}

void Game::changeDirection()
{
    char key = _getch();
    if (key == 'w' && snake.direction != 'd') {
        snake.direction = 'u'; // Движение вверх
    }
    else if (key == 's' && snake.direction != 'u') {
        snake.direction = 'd'; // Движение вниз
    }
    else if (key == 'a' && snake.direction != 'r') {
        snake.direction = 'l'; // Движение влево
    }
    else if (key == 'd' && snake.direction != 'l') {
        snake.direction = 'r'; // Движение вправо
    }
}

void Game::updateGame()
{
    moveSnake(); // Движение змейки
}

void Game::moveSnake()
{
    int headX = snake.snakeBody[0].x;
    int headY = snake.snakeBody[0].y;
    // Изменение координат головы змейки в зависимости от направления движения
    if (snake.direction == 'u') headY--;
    else if (snake.direction == 'd') headY++;
    else if (snake.direction == 'l') headX--;
    else if (snake.direction == 'r') headX++;
    // Перемещение головы змейки
    int tailX = snake.snakeBody[snake.size - 1].x;
    int tailY = snake.snakeBody[snake.size - 1].y;
    for (int i = snake.size - 1; i > 0; i--) {
        snake.snakeBody[i].x = snake.snakeBody[i - 1].x;
        snake.snakeBody[i].y = snake.snakeBody[i - 1].y;
    }
    snake.snakeBody[0].x = headX;
    snake.snakeBody[0].y = headY;
    // Обновление состояния поля после перемещения змейки
    for (int i = 0; i < field.Y; i++) {
        for (int j = 0; j < field.X; j++) {
            if (i == headY && j == headX) {
                field.GameBoard[i][j] = 'O'; // Голова змейки
            }
            else if (i == tailY && j == tailX) {
                field.GameBoard[i][j] = '.'; // Хвост змейки
            }
            else {
                field.GameBoard[i][j] = ' '; 
             }
        }
    }
}
