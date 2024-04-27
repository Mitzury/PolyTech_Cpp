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
#if 0; // Часть 1. Задание 2. Способ 1
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
#if 1; // Часть 1. Задание 3. Способ 1
            enum ArrowKeys {
                LEFT_ARROW = 75,
                RIGHT_ARROW = 77,
                UP_ARROW = 72,
                DOWN_ARROW = 80,
                ESC = 27
            };
                std::cout << "Введите символ управления (← - влево, → - вправо, ↑ - вверх, ↓ - вниз, ESC - выход): " << std::endl;;
                while (true) {
                    unsigned int input = 0;

                    if ((input = _getch()) == 0 || input == 224) /* функциональная ли клавиша */
                    {
                        input = _getch(); /* получаем код клавиши */
                        switch (input) {
                        case LEFT_ARROW:
                            std::cout << '<' << std::endl;
                            break;
                        case RIGHT_ARROW:
                            std::cout << '>' << std::endl; 
                            break;
                        case UP_ARROW:
                            std::cout << '^' << std::endl;
                            break;
                        case DOWN_ARROW:
                            std::cout << 'v' << std::endl;
                            break;
                        }
                    }
                    else {
                        if (input == ESC)
                        {
                            std::cout << "Игра завершена. Спасибо за участие!" << std::endl;
                            break;
                        }
                        else
                            std::cout << "Ошибка: Неверный символ управления. Пожалуйста, введите корректный символ.\n" << std::endl;
                    }
                }
#endif;
return 0;
}

