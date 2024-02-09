#pragma once
#include <iostream>

//  ласс Bin
class Bin {
public:
    unsigned char m_bin0 : 1; // бит 0
    unsigned char m_bin1 : 1; // бит 1
    unsigned char m_bin2 : 1; // бит 2
    unsigned char m_bin3 : 1; // бит 3
    unsigned char m_bin4 : 1; // бит 4
    unsigned char m_bin5 : 1; // бит 5
    unsigned char m_bin6 : 1; // бит 6
    unsigned char m_bin7 : 1; // бит 7

    void Show();                        // метод дл€ вывода значени€ в двоичном формате
    void ShowPos(int pos);              // метод дл€ вывода значени€ на определенной позиции в двоичном формате
    void Edit(int pos, int val);        // метод дл€ изменени€ значени€ на определенной позиции

    friend union Bytes;                 // объ€вление объединени€ bytes
};

//  ласс Oct
class Oct {
public:
    unsigned char m_oct0 : 3; // биты 0-2
    unsigned char m_oct1 : 3; // биты 3-5
    unsigned char m_oct2 : 2; // биты 6-7

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

//  ласс Hex
class Hex {
public:
    unsigned char m_hex0 : 4; // биты 0-3
    unsigned char m_hex1 : 4; // биты 4-7

    void Show();
    void ShowPos(int pos);
    void Edit(int pos, int val);

    friend union Bytes;
};

// ќбъединение Bytes
union Bytes {
public:
    Bin m_bin;                      // объект класса bin
    Oct m_oct;                      // объект класса oct
    Hex m_hex;                      // объект класса hex
    unsigned char m_dec;            // беззнаковое целое число

    Bytes(unsigned char byte);

    void ShowBin();                 // метод дл€ вывода значени€ в двоичном формате
    void ShowOct();                 // метод дл€ вывода значени€ в восьмеричном формате
    void ShowHex();                 // метод дл€ вывода значени€ в шестнадцатеричном формате
    void ShowDec();                 // метод дл€ вывода значени€ в дес€тичном формате
    void ShowChar();                // метод дл€ вывода символа, соответствующего значению

    void ShowBinPos(int pos);       // метод дл€ вывода значени€ на определенной позиции в двоичном формате
    void ShowOctPos(int pos);       // метод дл€ вывода значени€ на определенной позиции в восьмеричном формате
    void ShowHexPos(int pos);       // метод дл€ вывода значени€ на определенной позиции в шестнадцатеричном формате

    void EditBin(int pos, int val);
    void EditOct(int pos, int val);
    void EditHex(int pos, int val);
};