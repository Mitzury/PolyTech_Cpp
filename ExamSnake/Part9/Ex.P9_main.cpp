#include <iostream>
#include <conio.h> // ��� ������� _getch()
#include "Const.h"
#include "Game.h"

using namespace std;

// ������� ������� ����
int main() {
        setlocale(LC_ALL, "ru");

        Game game;
        game.startGame();
        return 0;
}

