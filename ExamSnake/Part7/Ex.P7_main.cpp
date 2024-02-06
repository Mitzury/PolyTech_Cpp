#include <iostream>
#include "conio.h"
#include "windows.h"
#include <thread>
#include <chrono>

using namespace std;

int WIDTH = 10;
int HEIGHT = 10;

int Score = 0;          // ���� ����
bool GameOver = false;  // ���� ���������� ����
int fruitX, fruitY;     // ���������� ������

// ��������� ��� ������������� �������� ����
struct Field {
    int X;
    int Y;
    char** GameBoard;

    // ����� ��� �������� ���� � ��� �������������
    void createField(int width, int height) {
        X = width;
        Y = height;

        // �������� ������ ��� ���������� ������� - �������� ����
        GameBoard = new char* [X];
        for (int i = 0; i < X; ++i) {
            GameBoard[i] = new char[Y];
        }

        // �������������� ������� ����, ����� ������� � �������� ������ ������������ ��� ������ � ������
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

    // ����� ��� ������ �������� ��������� ���� � �������
    void printField() {
        system("cls");  // ������� ������� ����� �������
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (i == fruitY && j == fruitX) {
                    cout << "* "; // ���� ������� ������� ������������� ������� ������, ������� �����
                }
                else {
                    cout << GameBoard[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

// ��������� ��� ������������� ������
struct Snake {
    int size;
    struct coordinate {
        int x, y;
    } *snakeBody;
    char direction;

    // ����� ��� �������� ������ � �� �������������
    void createSnake(Field& field) {
        size = 1;
        snakeBody = new coordinate[size];
        snakeBody[0].x = WIDTH / 2;  // ��������� ������ ���������� ���� �� �����������
        snakeBody[0].y = HEIGHT / 2; // ��������� ������ ���������� ���� �� ���������
        direction = 'r';  // ����������� ����������� ������

        // �������� ������ �� ������� ����
        field.GameBoard[snakeBody[0].y][snakeBody[0].x] = 'o';
    }
};

// ��������� ��� ������������� ����
struct Game {
    int delay = 1000;  // �������� �� ���������
    Field field;
    Snake snake;

    // ����� ��� ������ ����
    void startGame() {
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
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }

        // ����� ���������� ���� ������� ������� Enter
        cout << "���� ��������. ������� Enter ��� �����������...";
        cin.ignore();
        cin.get();
    }

    // ����� ��� ��������� ��������� ����������� �������� ������
    void changeDirection(char key) {
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

    // ����� ��� ���������� ��������� ����
    void updateGame() {
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
    }

    // ����� ��� �������� ������
    void moveSnake() {
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
};

// ������� ��� ����������� �������� ����
void showMainMenu() {
    system("cls");  // ������� ������� ����� ������� ����
    cout << "1) ������ ����" << endl;
    cout << "2) ��������� ������� ����" << endl;
    cout << "3) �����" << endl;
}

// ����������� ����� ��� ��������� ������� ����
void setFieldSize(int& width, int& height) {
    cout << "������� ����� ������� ���� (������ ������): ";
    cin >> width >> height;
}

// �������� ������� ���������
int main() {
    setlocale(LC_ALL, "ru");

    Game game;
    int choice;
    showMainMenu();
    cout << "�������� ����� ����: ";
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
        cout << "������������ �����." << endl;
        break;
    }

    cout << "������� Enter, ����� �����...";
    cin.ignore();
    cin.get();
    return 0;
}
