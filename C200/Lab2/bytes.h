#pragma once
#include <iostream>

// ����� Bin
class Bin {
public:
    unsigned char m_bin0 : 1; // ��� 0
    unsigned char m_bin1 : 1; // ��� 1
    unsigned char m_bin2 : 1; // ��� 2
    unsigned char m_bin3 : 1; // ��� 3
    unsigned char m_bin4 : 1; // ��� 4
    unsigned char m_bin5 : 1; // ��� 5
    unsigned char m_bin6 : 1; // ��� 6
    unsigned char m_bin7 : 1; // ��� 7

    void Show();                        // ����� ��� ������ �������� � �������� �������
    void ShowPos(int pos);              // ����� ��� ������ �������� �� ������������ ������� � �������� �������
    void Edit(int pos, int val);        // ����� ��� ��������� �������� �� ������������ �������

    friend union Bytes;                 // ���������� ����������� bytes
};

// ����� Oct
class Oct {
public:
    unsigned char m_oct0 : 3; // ���� 0-2
    unsigned char m_oct1 : 3; // ���� 3-5
    unsigned char m_oct2 : 2; // ���� 6-7

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// ����� Hex
class Hex {
public:
    unsigned char m_hex0 : 4; // ���� 0-3
    unsigned char m_hex1 : 4; // ���� 4-7

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// ����������� Bytes
union Bytes {
public:
    Bin m_bin;                      // ������ ������ bin
    Oct m_oct;                      // ������ ������ oct
    Hex m_hex;                      // ������ ������ hex
    unsigned char m_dec;            // ����������� ����� �����

    Bytes(unsigned char byte);

    void ShowBin();                 // ����� ��� ������ �������� � �������� �������
    void ShowOct();                 // ����� ��� ������ �������� � ������������ �������
    void ShowHex();                 // ����� ��� ������ �������� � ����������������� �������
    void ShowDec();                 // ����� ��� ������ �������� � ���������� �������
    void ShowChar();                // ����� ��� ������ �������, ���������������� ��������

    void ShowBinPos(int pos);       // ����� ��� ������ �������� �� ������������ ������� � �������� �������
    void ShowOctPos(int pos);       // ����� ��� ������ �������� �� ������������ ������� � ������������ �������
    void ShowHexPos(int pos);       // ����� ��� ������ �������� �� ������������ ������� � ����������������� �������

    void EditBin(int pos, int val);
    void EditOct(int pos, int val);
    void EditHex(int pos, int val);
};