#pragma once
// ������� ��� ������ ��������� ����������
template<typename Container>
void PrintAnyCont(const Container& cont) {
    for (const auto& elem : cont) { // �������� �� ����������
        std::cout << elem << " "; // ����� ��������
    }
    std::cout << std::endl; // ������� �� ����� ������
}