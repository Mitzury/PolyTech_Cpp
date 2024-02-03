#include <iostream>
#include <conio.h>

int main() {
    setlocale(LC_ALL, "Russian");

#if 0; // Часть 1. Задание 1. Способ 1
        char direction = '>';

        while (true) {
            std::cout << "Введите символ управления (a - влево, d - вправо, w - вверх, s - вниз, 0 - выход): ";
            char input;
            std::cin >> input;

            if (input == '0') {
                break;
            }
            else if (input == 'a' || input == 'd' || input == 'w' || input == 's') {
                direction = input;
            }
            else {
                std::cout << "Ошибка: Неверный символ управления. Пожалуйста, введите корректный символ.\n";
            }

            switch (direction) {
            case 'a':
                std::cout << '<' << std::endl;
                break;
            case 'd':
                std::cout << '>' << std::endl;
                break;
            case 'w':
                std::cout << '^' << std::endl;
                break;
            case 's':
                std::cout << 'v' << std::endl;
                break;
            }
        }
        std::cout << "Игра завершена. Спасибо за участие!\n";
#endif;

#if 0; // Часть 1. Задание 1. Способ 2
        char direction = '>';
        while (true) {
            std::cout << "Введите символ управления (a - влево, d - вправо, w - вверх, s - вниз, 0 - выход): ";
            char input = _getch();

            if (input == '0') {
                break;
            }
            else if (input == 'a' || input == 'd' || input == 'w' || input == 's') {
                direction = input;
            }
            else {
                std::cout << "Ошибка: Неверный символ управления. Пожалуйста, введите корректный символ.\n";
                continue;
            }
            switch (direction) {
            case 'a':
                std::cout << '<' << std::endl;
                break;
            case 'd':
                std::cout << '>' << std::endl;
                break;
            case 'w':
                std::cout << '^' << std::endl;
                break;
            case 's':
                std::cout << 'v' << std::endl;
                break;
            }
        }
        std::cout << "Игра завершена. Спасибо за участие!\n";
#endif;
#if 1; // Часть 1. Задание 2. Способ 1
        enum Keys {
            LEFT = 'a',
            RIGHT = 'd',
            UP = 'w',
            DOWN = 's',
            ESC = 27
        };
            char direction = '>';
            while (true) {
                std::cout << "\nВведите символ управления (a - влево, d - вправо, w - вверх, s - вниз, ESC - выход): ";
                unsigned int input = _getch();
                if (input == ESC) {
                    break;
                }
                else if (input == LEFT || input == RIGHT || input == UP || input == DOWN) {
                    direction = static_cast<char>(input);
                }
                else {
                    std::cout << "\nОшибка: Неверный символ управления. Пожалуйста, введите корректный символ.\n";
                    continue;
                }
                switch (direction) {
                case LEFT:
                    std::cout << '<';
                    break;
                case RIGHT:
                    std::cout << '>';
                    break;
                case UP:
                    std::cout << '^';
                    break;
                case DOWN:
                    std::cout << 'v';
                    break;
                }
            }
            std::cout << "Игра завершена. Спасибо за участие!\n";
#endif;
#if 0; // Часть 1. Задание 3. Способ 1
            enum ArrowKeys {
                LEFT_ARROW = 50,
                RIGHT_ARROW = 77,
                UP_ARROW = 72,
                DOWN_ARROW = 80,
                ESC = 27
            };
                char direction = '>';
                std::cout << "Введите символ управления (← - влево, → - вправо, ↑ - вверх, ↓ - вниз, ESC - выход):\n ";
                while (true) {
                    unsigned int input = _getch();
                    unsigned int secondInput;

                    if (input == 0xE0) {
                        secondInput = _getch();
                        input = secondInput + 256;
                    }
                    if (input == ESC) {
                        break;
                    }
                    else if (input == LEFT_ARROW || input == RIGHT_ARROW || input == UP_ARROW || input == DOWN_ARROW) {
                        switch (input) {
                        case LEFT_ARROW:
                            direction = '<';
                            break;
                        case RIGHT_ARROW:
                            direction = '>';
                            break;
                        case UP_ARROW:
                            direction = '^';
                            break;
                        case DOWN_ARROW:
                            direction = 'v';
                            break;
                        }
                    }
                    else {
                        std::cout << "Ошибка: Неверный символ управления. Пожалуйста, введите корректный символ.\n";
                        continue;
                    }
                    std::cout << direction;
                }
                std::cout << "Игра завершена. Спасибо за участие!\n";
#endif;
return 0;
}

