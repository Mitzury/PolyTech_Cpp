#pragma once
// ��������� ���� ����
struct Field {
    int X; // ������ ����
    int Y; // ������ ����
    char** GameBoard; // ��������� ������������ ������ ��� �������� ��������� ������ ������ ����

    void createField(int width, int height);
    void printField();
    void setFieldSize(int& width, int& height);

};