#include <iostream>
#include <conio.h> // ��� ������� _getch()
#include "Game.h"
#include "Const.h"

using namespace std;

// ������� ��� ����������� �������� ����
void showMainMenu() {
    system("cls");  // ������� ������� ����� ������� ����
    cout << "1) ������ ����" << endl;
    cout << "2) ��������� ������� ����" << endl;
    cout << "3) �����" << endl;
}

// ������� ������� ����
int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    game.showMainMenu();

    return 0;
}

