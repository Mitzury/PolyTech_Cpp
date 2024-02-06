#include <iostream>
#include "conio.h"
#include "windows.h"
#include <thread>
#include <chrono>

using namespace std;

int WIDTH = 10;
int HEIGHT = 10;

int Score = 0;          // Счет игры
bool GameOver = false;  // Флаг завершения игры
int fruitX, fruitY;     // Координаты фрукта

// Структура для представления игрового поля
struct Field {
    int X;
    int Y;
    char** GameBoard;

    // Метод для создания поля и его инициализации
    void createField(int width, int height) {
        X = width;
        Y = height;

        // Выделяем память для двумерного массива - игрового поля
        GameBoard = new char* [X];
        for (int i = 0; i < X; ++i) {
            GameBoard[i] = new char[Y];
        }

        // Инициализируем игровое поле, ставя границы и оставляя внутри пространство для змейки и фрукта
        for (int iy = 0; iy < Y; iy++) {
            for (int ix = 0; ix < X; ix++) {
                if ((iy == 0 || iy == Y - 1) || (ix == 0 || ix == X - 1)) {
                    GameBoard[iy][ix] = '#';
                }
                else {
                    GameBoard[iy][ix] = ' ';
                }
            }
        }
    }

    // Метод для вывода текущего состояния поля в консоль
    void printField() {
        system("cls");  // Очищаем консоль перед выводом
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (i == fruitY && j == fruitX) {
                    cout << "* "; // Если текущая позиция соответствует позиции фрукта, выводим фрукт
                }
                else {
                    cout << GameBoard[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

// Структура для представления змейки
struct Snake {
    int size;
    struct coordinate {
        int x, y;
    } *snakeBody;
    char direction;

    // Метод для создания змейки и ее инициализации
    void createSnake(Field& field) {
        size = 1;
        snakeBody = new coordinate[size];
        snakeBody[0].x = WIDTH / 2;  // Размещаем змейку посередине поля по горизонтали
        snakeBody[0].y = HEIGHT / 2; // Размещаем змейку посередине поля по вертикали
        direction = 'r';  // Изначальное направление вправо

        // Помещаем змейку на игровое поле
        field.GameBoard[snakeBody[0].y][snakeBody[0].x] = 'o';
    }
};

// Структура для представления игры
struct Game {
    int delay = 1000;  // Задержка по умолчанию
    Field field;
    Snake snake;

    // Метод для начала игры
    void startGame() {
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
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }

        // После завершения игры ожидаем нажатия Enter
        cout << "Игра окончена. Нажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }

    // Метод для обработки изменения направления движения змейки
    void changeDirection(char key) {
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

    // Метод для обновления состояния игры
    void updateGame() {
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
        for (int i = 0; i < snake.size; ++i) {
            if (snake.snakeBody[i].x >= 0 && snake.snakeBody[i].x < field.X && snake.snakeBody[i].y >= 0 && snake.snakeBody[i].y < field.Y)
                field.GameBoard[snake.snakeBody[i].y][snake.snakeBody[i].x] = 'o';
        }

        // Логика обновления игры
        // Проверка столкновения с самой собой
        for (int i = 1; i < snake.size; ++i) {
            if (snake.snakeBody[0].x == snake.snakeBody[i].x && snake.snakeBody[0].y == snake.snakeBody[i].y) {
                GameOver = true;
                break; // Если есть столкновение, нет смысла продолжать проверку
            }
        }

        // Перемещаем змейку только если игра еще не завершена
        if (!GameOver) {
            // Логика движения змейки
            moveSnake();
        }
    }

    // Метод для движения змейки
    void moveSnake() {
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
};

// Функция для отображения главного меню
void showMainMenu() {
    system("cls");  // Очищаем консоль перед выводом меню
    cout << "1) Начать игру" << endl;
    cout << "2) Настройки размера поля" << endl;
    cout << "3) Выйти" << endl;
}

// Добавленный метод для настройки размера поля
void setFieldSize(int& width, int& height) {
    cout << "Введите новые размеры поля (ширина высота): ";
    cin >> width >> height;
}

// Основная функция программы
int main() {
    setlocale(LC_ALL, "ru");

    Game game;
    int choice;
    showMainMenu();
    cout << "Выберите пункт меню: ";
    cin >> choice;

    switch (choice) {
    case 1:
        game.startGame();
        break;
    case 2:
        setFieldSize(WIDTH, HEIGHT);
        break;
    case 3:
        return 0;
    default:
        cout << "Неправильный выбор." << endl;
        break;
    }

    cout << "Нажмите Enter, чтобы выйти...";
    cin.ignore();
    cin.get();
    return 0;
}
