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
        game.delay = 2000; // �������� � 250 ����������� ����� ������ ����
        return 0;
}

