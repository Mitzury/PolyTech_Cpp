// Файл "card_index.h"

#ifndef CARD_INDEX_H
#define CARD_INDEX_H

#include "book.h"

enum SortField {
    AUTHOR,
    TITLE,
    YEAR,
    PRICE,
    CATEGORY
};

struct CARD_INDEX {
    BOOK* books; // указатель на массив структур BOOK
    int capacity; // емкость массива
    int count; // текущее количество книг в массиве
};

void initializeCardIndex(CARD_INDEX& cardIndex, int initialCapacity);
void printMenu();
void printMenu_1();
void printCardIndex(const CARD_INDEX& cardIndex);
void addBook(CARD_INDEX& cardIndex);
void removeBook(CARD_INDEX& cardIndex);
void saveToFile(const CARD_INDEX& cardIndex, const char* fileName);
void loadFromFile(CARD_INDEX& cardIndex, const char* fileName);
void sortBooks(CARD_INDEX& cardIndex, SortField sortField);
void cleanUp(CARD_INDEX& cardIndex);

#endif // CARD_INDEX_H
