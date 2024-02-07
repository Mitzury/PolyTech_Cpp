#pragma once
// Структура поля игры
struct Field {
    int X; // Ширина поля
    int Y; // Высота поля
    char** GameBoard; // Двумерный динамический массив для хранения состояния каждой ячейки поля

    void createField(int width, int height);
    void printField();

};