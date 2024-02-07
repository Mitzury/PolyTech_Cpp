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

// ����������� ����� ��� ��������� ������� ����
void setFieldSize(int& width, int& height) {
    cout << "������� ����� ������� ���� (������ ������): ";
    cin >> width >> height;
}

// ������� ������� ����
int main() {
    setlocale(LC_ALL, "ru");

    Game game;
    int choice;

    do {
        showMainMenu();
        cout << "�������� ����� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            game.startGame();
            break;
        case 2:
            cout << "���������� ������ ����" << endl;
            setFieldSize(WIDTH, HEIGHT);
            break;
        case 3:
            cout << "�� ��������!" << endl;
            return 0;
        default:
            cout << "������������ �����." << endl;
            break;
        }

        // ������� ������ �����
        cin.clear();
        cin.ignore();

        cout << "������� Enter, ����� ����������...";

        cin.get();
    } while (true);
        return 0;
}

