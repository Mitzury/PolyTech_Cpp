#pragma once
#include "Field.h"

struct Game {
    int delay; // Задержка между шагами игры
    Field field; // Экземпляр игрового поля

    void startGame();

};