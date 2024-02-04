#include <iostream>
#include "Field.h"

using namespace std;

void Field::createField()
{
    GameBoard = new char* [Y];
    for (int i = 0; i < Y; i++) {
        GameBoard[i] = new char[X];
    }


    for (int iy = 0; iy < Y; iy++) {
        for (int ix = 0; ix < X; ix++) {
            if ((iy == 0 || iy == Y - 1) || (ix == 0 || ix == X - 1)) {
                GameBoard[iy][ix] = '#'; // символ решетки для границ
            }
            else {
                GameBoard[iy][ix] = ' '; // пробел для пустых мест
            }
        }
    }

}

void Field::printField()
{
    system("cls"); // Очистка экрана
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            std::cout << GameBoard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
