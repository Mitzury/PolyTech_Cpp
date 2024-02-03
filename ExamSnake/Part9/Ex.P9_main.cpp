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

    Field field;

    int X;
    int Y;
    cout << "¬ведите размерности массива (N M): ";
    cin >> X >> Y;

    field.CreateField(X,Y, field);
    field.PrintField(field, X, Y);

}