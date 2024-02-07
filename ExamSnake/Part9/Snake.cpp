#include "Snake.h"
#include "Const.h"


    // ����� ��� �������� ������ � �� �������������
    void Snake::createSnake(Field& field) {
        size = 1;
        snakeBody = new coordinate[size];
        snakeBody[0].x = WIDTH / 2;  // ��������� ������ ���������� ���� �� �����������
        snakeBody[0].y = HEIGHT / 2; // ��������� ������ ���������� ���� �� ���������
        direction = 'r';  // ����������� ����������� ������

        // �������� ������ �� ������� ����
        field.GameBoard[snakeBody[0].y][snakeBody[0].x] = 'o';
    }


