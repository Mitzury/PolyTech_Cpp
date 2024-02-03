#include <iostream>
#include "Field.h"
using namespace std;


void Field::CreateField(int X, int Y, Field& Field) {

    int** arr = new int* [X];
    for (int i = 0; i < X; i++) {
        arr[i] = new int[Y];
    }

    for (int iy = 0; iy < Y; iy++)
    {
        for (int ix = 0; ix < X; ix++) {
            if ((iy == 0 || iy == Y - 1) || (ix == 0 || ix == X - 1)) {
                arr[iy][ix] = 1;
            }
            else {
                arr[iy][ix] = 0;
            }
        }

    }
}
void Field::PrintField(const Field& Field, int X, int Y) {

    

    for (int iy = 0; iy < Y; iy++) {
        for (int ix = 0; ix < X; ix++) {
            cout << Field.arr;

        } std::cout << std::endl;

    }
}



