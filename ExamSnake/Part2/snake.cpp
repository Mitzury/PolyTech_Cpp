#include <iostream>
#include "const.h"


int snake_size;  // ������� ������ ������

// ������������� ������
void initializeSnake() {
    snake_size = 1;  // ��������� ������ ������
    head_position = 0;  // ��������� ������� ������
}


// �������� ������
void moveSnake() {
    // ����������� ������� ������
    head_position++;

    // ���������, �������� �� ������ �������
    if (head_position >= columns) {
        // ������ �������� �������, �������� ������
        head_position = 0;
    }
}

// ��������� ������
void drawSnake() {
    // ������� ������� ����� �������
    for (int i = 0; i < head_position; i++) {
        std::cout << ' ';
    }

    // ������� ������
    std::cout << head_symbol << std::endl;

    // ������� �����
    for (int i = 0; i < snake_size - 1; i++) {
        std::cout << tail_symbol << std::endl;
    }
}