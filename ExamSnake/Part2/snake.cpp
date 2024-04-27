#include <iostream>
#include "const.h"
#include "snake.h"

int head_position;
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

	if (head_position > snake_size) // ���� ����� ������ ������ �� �������
	{
		for (int i = 0; i < head_position - snake_size; ++i) // ������ ����������� ���������� ��������
		{
			std::cout << ' ';
		}
	}

	if (head_position < snake_size) // ���� ������ �� ��� ����� � ������
	{
		for (int i = 0; i < head_position; ++i) // ������ �����
		{
			std::cout << tail_symbol;
		}
	}
	else if (head_position >= snake_size) // ���� ������ ��� ��������
	{
		for (int i = 0; i < snake_size - 1; ++i) // ������ �����
		{
			std::cout << tail_symbol;
		}
	}
	std::cout << head_symbol;  // ������ ������

	for (int i = 1; i < (columns - head_position); ++i) // ������ ������� ����
	{
		std::cout << ' ';
	}

	++head_position;

}