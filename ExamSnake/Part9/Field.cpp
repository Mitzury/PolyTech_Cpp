#include <iostream>
#include "Field.h"
#include "Const.h"

using namespace std;

// Структура для представления игрового поля

    // Метод для создания поля и его инициализации
    void Field::createField(int width, int height) {
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
    void Field::printField() {
        setCursorPosition(0, 0);
        //system("cls");  // Очищаем консоль перед выводом
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

    // Добавленный метод для настройки размера поля
    void Field::setFieldSize(int& width, int& height) {
        cout << "Введите новые размеры поля (ширина высота): ";
        cin >> width >> height;
    }