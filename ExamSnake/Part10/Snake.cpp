#include "Snake.h"
#include "Game.h"

void Snake::createSnake() {
    snakeBody = new coordinate[size];
    // ������������� ��������� ��������� ������
    for (int i = 0; i < size; i++) {
        snakeBody[i].x = 0;
        snakeBody[i].y = i;
    }
    direction = 'r'; // ��������� ����������� �������� ������
}
