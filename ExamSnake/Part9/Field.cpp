#include <iostream>
#include "Field.h"
#include "Const.h"

using namespace std;

// ��������� ��� ������������� �������� ����

    // ����� ��� �������� ���� � ��� �������������
    void Field::createField(int width, int height) {
        X = width;
        Y = height;

        // �������� ������ ��� ���������� ������� - �������� ����
        GameBoard = new char* [X];
        for (int i = 0; i < X; ++i) {
            GameBoard[i] = new char[Y];
        }

        // �������������� ������� ����, ����� ������� � �������� ������ ������������ ��� ������ � ������
        for (int iy = 0; iy < Y; iy++) {
            for (int ix = 0; ix < X; ix++) {
                if ((iy == 0 || iy == Y - 1) || (ix == 0 || ix == X - 1)) {
                    GameBoard[iy][ix] = '#';
                }
                else {
                    GameBoard[iy][ix] = ' ';
                }
            }
        }
    }

    // ����� ��� ������ �������� ��������� ���� � �������
    void Field::printField() {
        setCursorPosition(0, 0);
        //system("cls");  // ������� ������� ����� �������
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < Y; ++j) {
                if (i == fruitY && j == fruitX) {
                    cout << "* "; // ���� ������� ������� ������������� ������� ������, ������� �����
                }
                else {
                    cout << GameBoard[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    // ����������� ����� ��� ��������� ������� ����
    void Field::setFieldSize(int& width, int& height) {
        cout << "������� ����� ������� ���� (������ ������): ";
        cin >> width >> height;
    }