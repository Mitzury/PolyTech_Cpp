#include "bytes.h"

// ���������� ������� ������ Bin
void Bin::Show() {
    std::cout << static_cast<int>(m_bin7) << m_bin6 << m_bin5 << m_bin4 << " "
        << m_bin3 << m_bin2 << m_bin1 << m_bin0 << "b";
}

// ����� �������� ������������ ������� ����� � �������� �������
void Bin::ShowPos(int pos) {
    if (pos >= 0 && pos <= 7) {
        std::cout << static_cast<int>((m_bin7 >> pos) & 1);
    }
    else {
        std::cout << "Invalid position";
    }
}

// ��������� �������� ������������ ������� ����� � �������� �������
void Bin::Edit(int pos, int val) {
    if (pos >= 0 && pos <= 7 && (val == 0 || val == 1)) {
        if (val == 1) {
            m_bin7 |= (1 << pos);
        }
        else {
            m_bin7 &= ~(1 << pos);
        }
    }
    else {
        std::cout << "Invalid position or value";
    }
}

// ���������� ������� ������ Oct
void Oct::Show() {
    std::cout << static_cast<int>(m_oct2) << m_oct1 << m_oct0 << "o";
}

void Oct::ShowPos(int pos) {
    if (pos >= 0 && pos <= 5) {
        int shift = 3 * (1 - pos % 2);
        std::cout << static_cast<int>((m_oct2 >> shift) & 7);
    }
    else {
        std::cout << "Invalid position";
    }
}

void Oct::Edit(int pos, int val) {
    if (pos >= 0 && pos <= 5 && val >= 0 && val <= 7) {
        int shift = 3 * (1 - pos % 2);
        m_oct2 &= ~(7 << shift);
        m_oct2 |= (val << shift);
    }
    else {
        std::cout << "Invalid position or value";
    }
}

// ���������� ������� ������ Hex
void Hex::Show() {
    std::cout << std::hex << static_cast<int>(m_hex1) << m_hex0 << "h" << std::dec;
}

void Hex::ShowPos(int pos) {
    if (pos >= 0 && pos <= 3) {
        int shift = 4 * (1 - pos % 2);
        std::cout << std::hex << static_cast<int>((m_hex1 >> shift) & 0xF) << std::dec;
    }
    else {
        std::cout << "Invalid position";
    }
}

// ��������� �������� ������������ ������� ����� � ����������������� �������
void Hex::Edit(int pos, int val) {
    if (pos >= 0 && pos <= 3 && val >= 0 && val <= 15) {
        int shift = 4 * (1 - pos % 2);
        m_hex1 &= ~(0xF << shift);
        m_hex1 |= (val << shift);
    }
    else {
        std::cout << "Invalid position or value";
    }
}

// ���������� ������� ����������� Bytes
Bytes::Bytes(unsigned char byte) : m_dec(byte) {}
// ����� �������� ����� � �������� �������
void Bytes::ShowBin() { m_bin.Show(); }
// ����� �������� ����� � ������������ �������
void Bytes::ShowOct() { m_oct.Show(); }
// ����� �������� ����� � ����������������� �������
void Bytes::ShowHex() { m_hex.Show(); }
// ����� �������� ����� � ���������� �������
void Bytes::ShowDec() { std::cout << static_cast<int>(m_dec) << "d"; }

// ����� �������, ���������������� �������� ����� (���� ��� �������� ������)
void Bytes::ShowChar() {
    if (m_dec >= 32 && m_dec <= 126) {
        std::cout << static_cast<char>(m_dec);
    }
    else {
        std::cout << "Not printable";
    }
}

// ����� �������� ������������ ������� ����� � �������� �������
void Bytes::ShowBinPos(int pos) { m_bin.ShowPos(pos); }
// ����� �������� ������������ ������� ����� � ������������ �������
void Bytes::ShowOctPos(int pos) { m_oct.ShowPos(pos); }
// ����� �������� ������������ ������� ����� � ����������������� �������
void Bytes::ShowHexPos(int pos) { m_hex.ShowPos(pos); }
// ��������� �������� ������������ ������� ����� � �������� �������
void Bytes::EditBin(int pos, int val) { m_bin.Edit(pos, val); }
// ��������� �������� ������������ ������� ����� � ������������ �������
void Bytes::EditOct(int pos, int val) { m_oct.Edit(pos, val); }
// ��������� �������� ������������ ������� ����� � ����������������� �������
void Bytes::EditHex(int pos, int val) { m_hex.Edit(pos, val); }