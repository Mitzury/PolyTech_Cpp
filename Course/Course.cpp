#include <iostream>
#include <string>

using namespace std;

int main () {

    int value;

    do {
        std::cout << "������� ����� ��������: ";
        std::cin >> value;


    } while (!(value >= 10 && (value & 1) == 0));

    std::cout << "������� ���������� ��������: " << value << std::endl;

    int x_2 = 0;
    double sum_1 = 0.0;

    while (sum_1 <= 1.7) {
        x_2 = x_2 + 1;
        sum_1 = sum_1 + 1.0 / x_2;
    }

    std::cout << "�������� x, ��� ������� sum > 1.7: " << x_2 << std::endl;

return 0;
}