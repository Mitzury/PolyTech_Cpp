// ��������� ��� ������������� ����
#include "Const.h"
#include "Game.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
using namespace std;


 void Game::startGame() {
        field.createField(WIDTH, HEIGHT);  // ������� � �������������� ������� ����
        snake.createSnake(field);  // ������� � �������������� ������
        fruitX = rand() % (field.X - 2) + 1;  // ��������� ����� ��������� ������� ������ ����
        fruitY = rand() % (field.Y - 2) + 1;

        // �������� ���� ����
        while (!GameOver) {
            if (_kbhit()) {
                char key = _getch(); // �������� ������� �������
                changeDirection(key); // ��������� ����������� ������
            }
            updateGame();       // ��������� ��������� ����
            field.printField(); // ������� ������� ��������� ����
            Sleep(1);
        }

        // ����� ���������� ���� ������� ������� Enter
        cout << "���� ��������. ������� Enter ��� �����������...";
        cin.ignore();
        cin.get();
        GameOver = false; // ���������� ���� GameOver, ����� ���� ����� ����� ��������
    }

    // ����� ��� ��������� ��������� ����������� �������� ������
 void Game::changeDirection(char key) {
        switch (key) {
        case 'w':
            if (snake.direction != 'd') // ��������� �������� �� 180 ��������
                snake.direction = 'u';
            break;
        case 's':
            if (snake.direction != 'u')
                snake.direction = 'd';
            break;
        case 'a':
            if (snake.direction != 'r')
                snake.direction = 'l';
            break;
        case 'd':
            if (snake.direction != 'l')
                snake.direction = 'r';
            break;
        }
    }

    // ������� ��� ����������� �������� ����
 void Game::showMainMenu() {
        system("cls");  // ������� ������� ����� ������� ����
        cout << "1) ������ ����" << endl;
        cout << "2) ��������� ������� ����" << endl;
        cout << "3) �����" << endl;
    }

    // ����� ��� ���������� ��������� ����
 void Game::updateGame() {
        // ��������� ������� ������ � ����������� ������ ��� �������������
        if (snake.snakeBody[0].x == fruitX && snake.snakeBody[0].y == fruitY) {
            Score++;  // ���������� �����
            // ���������� ����� ���������� ��� ������
            do {
                fruitX = rand() % (field.X - 2) + 1;
                fruitY = rand() % (field.Y - 2) + 1;
            } while (field.GameBoard[fruitY][fruitX] != ' '); // ������������ ����� ����������, ���� ����� �� �������� � ������ ������
            // ����������� ������ ������ � ��������� ����������
            snake.size++;
            Snake::coordinate* newSnakeBody = new Snake::coordinate[snake.size];
            for (int i = 0; i < snake.size - 1; ++i) {
                newSnakeBody[i] = snake.snakeBody[i];
            }
            delete[] snake.snakeBody;
            snake.snakeBody = newSnakeBody;
        }

        // �������� ����� �� ����
        if (fruitX > 0 && fruitX < field.X && fruitY > 0 && fruitY < field.Y)
            field.GameBoard[fruitY][fruitX] = '*';

        // ��������� ��������� ������ �� ����
        for (int i = 0; i < field.X; ++i) {
            for (int j = 0; j < field.Y; ++j) {
                if (i == 0 || i == field.Y - 1 || j == 0 || j == field.X - 1) {
                    field.GameBoard[i][j] = '#'; // ������ ������ ��� ������ ����
                }
                else {
                    field.GameBoard[i][j] = ' '; // ��������� ������ ���� ������
                }
            }
        }

        // �������� ������ �� ����
        for (int i = 0; i < snake.size; ++i) {
            if (snake.snakeBody[i].x >= 0 && snake.snakeBody[i].x < field.X && snake.snakeBody[i].y >= 0 && snake.snakeBody[i].y < field.Y)
                field.GameBoard[snake.snakeBody[i].y][snake.snakeBody[i].x] = 'o';
        }

        // ������ ���������� ����
        // �������� ������������ � ����� �����
        for (int i = 1; i < snake.size; ++i) {
            if (snake.snakeBody[0].x == snake.snakeBody[i].x && snake.snakeBody[0].y == snake.snakeBody[i].y) {
                GameOver = true;
                break; // ���� ���� ������������, ��� ������ ���������� ��������
            }
        }

        // ���������� ������ ������ ���� ���� ��� �� ���������
        if (!GameOver) {
            // ������ �������� ������
            moveSnake();
        }
        else {
            // ������������ � ������� ���� ��� ���������� ����
            GameOver = false;
            showMainMenu();
        }
    }

    // ����� ��� �������� ������
 void Game::moveSnake() {
        // ������ �������� ������
        for (int i = snake.size - 1; i > 0; --i) {
            snake.snakeBody[i] = snake.snakeBody[i - 1];
        }
        // ��������� ��������� ������ ������ � ����������� �� �����������
        switch (snake.direction) {
        case 'u':
            snake.snakeBody[0].y--;
            break;
        case 'd':
            snake.snakeBody[0].y++;
            break;
        case 'l':
            snake.snakeBody[0].x--;
            break;
        case 'r':
            snake.snakeBody[0].x++;
            break;
        }

        // ��������� ������ �� ������� ����
        if (snake.snakeBody[0].x < 1) snake.snakeBody[0].x = field.X - 2;
        if (snake.snakeBody[0].x >= field.X - 1) snake.snakeBody[0].x = 1;
        if (snake.snakeBody[0].y < 1) snake.snakeBody[0].y = field.Y - 2;
        if (snake.snakeBody[0].y >= field.Y - 1) snake.snakeBody[0].y = 1;
    }