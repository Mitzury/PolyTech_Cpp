#include "Snake.h"
#include "Const.h"


    // Метод для создания змейки и ее инициализации
    void Snake::createSnake(Field& field) {
        size = 1;
        snakeBody = new coordinate[size];
        snakeBody[0].x = WIDTH / 2;  // Размещаем змейку посередине поля по горизонтали
        snakeBody[0].y = HEIGHT / 2; // Размещаем змейку посередине поля по вертикали
        direction = 'r';  // Изначальное направление вправо

        // Помещаем змейку на игровое поле
        field.GameBoard[snakeBody[0].y][snakeBody[0].x] = 'o';
    }


