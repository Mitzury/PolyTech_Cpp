// Структура для представления игры
#include "Const.h"
#include "Game.h"
#include "Field.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
using namespace std;


Game::~Game() {
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; i < HEIGHT; ++j) {

            delete[] field.GameBoard[i];
        }
    }
}

void Game::startGame() {
        field.createField(WIDTH, HEIGHT);  // Создаем и инициализируем игровое поле
        snake.createSnake(field);  // Создаем и инициализируем змейку
        fruitX = rand() % (field.X - 2) + 1;  // Размещаем фрукт случайным образом внутри поля
        fruitY = rand() % (field.Y - 2) + 1;

        // Основной цикл игры
        while (!GameOver) {
            if (_kbhit()) {
                char key = _getch(); // Получаем нажатую клавишу
                changeDirection(key); // Обновляем направление змейки
            }
            updateGame();       // Обновляем состояние игры
            field.printField(); // Выводим текущее состояние поля
            Sleep(200);
        }

        // После завершения игры ожидаем нажатия Enter
        cout << "Игра окончена. Нажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
        GameOver = false; // сбрасываем флаг GameOver, чтобы игра снова могла начаться
    }

    // Метод для обработки изменения направления движения змейки
 void Game::changeDirection(char key) {
        switch (key) {
        case 'w':
            if (snake.direction != 'd') // Запрещаем разворот на 180 градусов
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

 // Функция для отображения главного меню
 void Game::showMainMenu() {
       
        system("cls");  // Очищаем консоль перед выводом меню
        cout << "1) Начать игру" << endl;
        cout << "2) Настройки размера поля" << endl;
        cout << "3) Выйти" << endl;
        cout << "Выберите пункт меню: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            Game game;
            game.startGame();
            break;
        case 2:
            cout << "Установить размер поля" << endl;
            field.setFieldSize(WIDTH, HEIGHT);
            break;
        case 3:
            cout << "До свидания!" << endl;
            exit(0);
            break;
        default:
            cout << "Неправильный выбор." << endl;
            break;
        }
        // Очистка буфера ввода
        cin.clear();
        cin.ignore();
        cout << "Нажмите Enter, чтобы продолжить...";
        cin.get();     
 }


    // Метод для обновления состояния игры
 void Game::updateGame() {
        // Проверяем наличие фрукта и увеличиваем змейку при необходимости
        if (snake.snakeBody[0].x == fruitX && snake.snakeBody[0].y == fruitY) {
            Score++;  // Увеличение счета
            // Генерируем новые координаты для фрукта
            do {
                fruitX = rand() % (field.X - 2) + 1;
                fruitY = rand() % (field.Y - 2) + 1;
            } while (field.GameBoard[fruitY][fruitX] != ' '); // Генерировать новые координаты, пока фрукт не окажется в пустой ячейке
            // Увеличиваем размер змейки и обновляем координаты
            snake.size++;
            Snake::coordinate* newSnakeBody = new Snake::coordinate[snake.size];
            for (int i = 0; i < snake.size - 1; ++i) {
                newSnakeBody[i] = snake.snakeBody[i];
            }
            delete[] snake.snakeBody;
            snake.snakeBody = newSnakeBody;
        }

        // Помещаем фрукт на поле
        if (fruitX > 0 && fruitX < field.X && fruitY > 0 && fruitY < field.Y)
            field.GameBoard[fruitY][fruitX] = '*';

        // Обновляем положение змейки на поле
        for (int i = 0; i < field.X; ++i) {
            for (int j = 0; j < field.Y; ++j) {
                if (i == 0 || i == field.Y - 1 || j == 0 || j == field.X - 1) {
                    field.GameBoard[i][j] = '#'; // Задаем символ для границ поля
                }
                else {
                    field.GameBoard[i][j] = ' '; // Остальные ячейки поля пустые
                }
            }
        }

        // Помещаем змейку на поле
        // Цикл перебирает каждый сегмент змейки. snake.size - это количество сегментов в змейке.
        //Помещение змейки на поле :
        // Если текущий сегмент змейки находится в пределах игрового поля, символ 'o'  помещается в соответствующую ячейку 
        // игрового поля. Это символизирует присутствие сегмента змейки на данной позиции.
        for (int i = 0; i < snake.size; ++i) {
            if (snake.snakeBody[i].x >= 0 && snake.snakeBody[i].x < field.X && snake.snakeBody[i].y >= 0 && snake.snakeBody[i].y < field.Y)
                field.GameBoard[snake.snakeBody[i].y][snake.snakeBody[i].x] = 'o';
        }

        // Логика обновления игры
        // Проверка столкновения с самой собой
        for (int i = 1; i < snake.size; ++i) {
            if (snake.snakeBody[0].x == snake.snakeBody[i].x && snake.snakeBody[0].y == snake.snakeBody[i].y) {
                GameOver = true;
                system("cls");
                cout << "Нажмите Enter, чтобы продолжить...";
                break; // Если есть столкновение, нет смысла продолжать проверку
            }
        }

        // Перемещаем змейку только если игра еще не завершена
        if (!GameOver) {
            // Логика движения змейки
            moveSnake();
        }
        else {
            // Возвращаемся в главное меню при завершении игры
            GameOver = false;
            cout << "Капец";
            cin.get();
            showMainMenu();
        }
    }

    // Метод для движения змейки

    /* Логика движения змейки(moveSnake()) :
     Этот метод отвечает за перемещение змейки по игровому полю в соответствии с ее текущим направлением.
     Сначала каждый сегмент змейки (кроме головы) перемещается на следующую позицию вперед.
     Затем координаты головы змейки обновляются в зависимости от текущего направления.
     Проверяются условия выхода за границы поля : если змейка достигла края поля, ее голова появляется с
     противоположной стороны поля(как если бы поле было замкнутым по краям).
     */
 void Game::moveSnake() {
        // Логика движения змейки
        for (int i = snake.size - 1; i > 0; --i) {
            snake.snakeBody[i] = snake.snakeBody[i - 1];
        }
        // Изменение координат головы змейки в зависимости от направления
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

        // Обработка выхода за границы поля
        if (snake.snakeBody[0].x < 1) snake.snakeBody[0].x = field.X - 2;
        if (snake.snakeBody[0].x >= field.X - 1) snake.snakeBody[0].x = 1;
        if (snake.snakeBody[0].y < 1) snake.snakeBody[0].y = field.Y - 2;
        if (snake.snakeBody[0].y >= field.Y - 1) snake.snakeBody[0].y = 1;
    }
