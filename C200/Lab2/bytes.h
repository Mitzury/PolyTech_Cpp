#pragma once
#include <iostream>

// Класс Bin
class Bin {
public:
    unsigned char m_bin0 : 1;
    unsigned char m_bin1 : 1;
    unsigned char m_bin2 : 1;
    unsigned char m_bin3 : 1;
    unsigned char m_bin4 : 1;
    unsigned char m_bin5 : 1;
    unsigned char m_bin6 : 1;
    unsigned char m_bin7 : 1;

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// Класс Oct
class Oct {
public:
    unsigned char m_oct0 : 3;
    unsigned char m_oct1 : 3;
    unsigned char m_oct2 : 2;

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// Класс Hex
class Hex {
public:
    unsigned char m_hex0 : 4;
    unsigned char m_hex1 : 4;

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// Объединение Bytes
union Bytes {
public:
    Bin m_bin;
    Oct m_oct;
    Hex m_hex;
    unsigned char m_dec;

    Bytes(unsigned char byte);

    void ShowBin();
    void ShowOct();
    void ShowHex();
    void ShowDec();
    void ShowChar();

    void ShowBinPos(int pos);
    void ShowOctPos(int pos);
    void ShowHexPos(int pos);

    void EditBin(int pos, int val);
    void EditOct(int pos, int val);
    void EditHex(int pos, int val);
};