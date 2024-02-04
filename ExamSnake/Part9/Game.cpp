#include "Game.h"
#include <iostream>
#include <conio.h>

void Game::startGame()
{
    // ���� �������� ����
    std::cout << "Enter width: ";
    std::cin >> field.X;
    std::cout << "Enter height: ";
    std::cin >> field.Y;
    // �������� ����
    field.createField();
    // ����� ���� �� �����
    field.printField();
    // �������� ������
    snake.size = 1;
    snake.createSnake();
    // ���� ����
    while (true) {
        
        field.printField(); // ����� ���� �� �����
        updateGame(); // ���������� ��������� ����
        if (_kbhit()) { // �������� �� ������� �������
            changeDirection(); // ��������� ����������� �������� ������
        }
    }
}

void Game::changeDirection()
{
    char key = _getch();
    if (key == 'w' && snake.direction != 'd') {
        snake.direction = 'u'; // �������� �����
    }
    else if (key == 's' && snake.direction != 'u') {
        snake.direction = 'd'; // �������� ����
    }
    else if (key == 'a' && snake.direction != 'r') {
        snake.direction = 'l'; // �������� �����
    }
    else if (key == 'd' && snake.direction != 'l') {
        snake.direction = 'r'; // �������� ������
    }
}

void Game::updateGame()
{
    moveSnake(); // �������� ������
}

void Game::moveSnake()
{
    int headX = snake.snakeBody[0].x;
    int headY = snake.snakeBody[0].y;
    // ��������� ��������� ������ ������ � ����������� �� ����������� ��������
    if (snake.direction == 'u') headY--;
    else if (snake.direction == 'd') headY++;
    else if (snake.direction == 'l') headX--;
    else if (snake.direction == 'r') headX++;
    // ����������� ������ ������
    int tailX = snake.snakeBody[snake.size - 1].x;
    int tailY = snake.snakeBody[snake.size - 1].y;
    for (int i = snake.size - 1; i > 0; i--) {
        snake.snakeBody[i].x = snake.snakeBody[i - 1].x;
        snake.snakeBody[i].y = snake.snakeBody[i - 1].y;
    }
    snake.snakeBody[0].x = headX;
    snake.snakeBody[0].y = headY;
    // ���������� ��������� ���� ����� ����������� ������
    for (int i = 1; i < field.Y; i++) {
        for (int j = 1; j < field.X; j++) {
            if (i == headY && j == headX) {
                field.GameBoard[i][j] = 'O'; // ������ ������
            }
            // ������ ���������� �������������� ������ � ������
            if (field.GameBoard[i][j] != 'o' && field.GameBoard[i][j] != '.') {
                field.GameBoard[i][j] = ' '; // ������ ������
            }
        }
    }
}
