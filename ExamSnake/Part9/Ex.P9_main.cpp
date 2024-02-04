#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Field.h"

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");


    int X;
    int Y;
    cout << "¬ведите размерности массива (N M): ";
    cin >> X >> Y;
    Field field;
    field.X = X;
    field.Y = Y;

    field.Create(X, Y);


}