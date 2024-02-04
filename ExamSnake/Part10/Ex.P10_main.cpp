#include <iostream>
#include <conio.h> // ��� ������� _getch()
#include "Const.h"
#include "Game.h"

using namespace std;

// ������� ��� ����������� �������� ����
void showMainMenu() {
    system("cls");
    std::cout << "1) ������ ����" << std::endl;
    std::cout << "2) ��������� ����" << std::endl;
    std::cout << "3) ���" << std::endl;
    std::cout << "4) �����" << std::endl;
}

// ������� ������� ����
int main() {
        setlocale(LC_ALL, "ru");

        int choice;
        showMainMenu();
        std::cout << "�������� ����� ����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            Game game;
            game.startGame();
            game.delay = 2000; // �������� � 250 ����������� ����� ������ ����
            break;
        default:
            std::cout << "������������ �����." << std::endl;
        case 4:
            exit;
        }
        return 0;
}

