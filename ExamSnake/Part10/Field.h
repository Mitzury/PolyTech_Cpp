#pragma once
// ��������� ���� ����
struct Field {
    int X; // ������ ����
    int Y; // ������ ����
    char** GameBoard; // ��������� ������������ ������ ��� �������� ��������� ������ ������ ����

    void createField();
    void printField();
};