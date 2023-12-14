// File: book.h

#ifndef BOOK_H
#define BOOK_H

#include <stdio.h>

struct BOOK {
    char author[100];
    char title[100];
    int year;
    float price;
    char category[50];
};

void printBookInfo(const struct BOOK *book);
void fillBookFields(struct BOOK *book);

#endif // BOOK_H
