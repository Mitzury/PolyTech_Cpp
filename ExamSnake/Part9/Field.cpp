#include <iostream>
#include "Field.h"
using namespace std;

void Field::Create(int X, int Y)
{
    char** arr = new char* [Y];
    for (int i = 0; i < Y; i++) {
        arr[i] = new char[X];
    }

    for (int iy = 0; iy < Y; iy++) {
        for (int ix = 0; ix < X; ix++) {
            if ((iy == 0 || iy == Y - 1) || (ix == 0 || ix == X - 1)) {
                arr[iy][ix] = '#'; // символ решетки для границ
            }
            else {
                arr[iy][ix] = ' '; // пробел для пустых мест
            }
        }
    }
    // Вывод массива на экран
    for (int iy = 0; iy < Y; iy++) {
        for (int ix = 0; ix < X; ix++) {
            cout << arr[iy][ix];
        }
        cout << endl;
    }
}
