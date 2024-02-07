#include <iostream>
#include <conio.h> // ��� ������� _getch()
#include "Game.h"
#include "Const.h"
#include <Windows.h>

using namespace std;

void setCursorPosition(int x, int y)
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static bool init = false;
	if (!init) {				// �������� ������
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hConsole, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &structCursorInfo);
		init = true;
	}
	COORD position = { x, y }; // ������������� � ������ �������
	SetConsoleCursorPosition(hConsole, position);
}

// ������� ��� ����������� �������� ����
void showMainMenu() {
    //system("cls");  // ������� ������� ����� ������� ����
    cout << "1) ������ ����" << endl;
    cout << "2) ��������� ������� ����" << endl;
    cout << "3) �����" << endl;
}

// ������� ������� ����
int main() {
    setlocale(LC_ALL, "ru");
    Game game;
    do {
        game.showMainMenu();
    } while (true);
   

    return 0;
}

