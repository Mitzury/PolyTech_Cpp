// File: card_index.h

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
    struct BOOK *books;
    int capacity;
    int count;
};

void printMenu();
void printCardIndex(const struct CARD_INDEX *cardIndex);
void addBook(struct CARD_INDEX *cardIndex);
void deleteBook(struct CARD_INDEX *cardIndex);
void saveToFile(const struct CARD_INDEX *cardIndex, const char *filename);
void loadFromFile(struct CARD_INDEX *cardIndex, const char *filename);
void bubbleSort(struct CARD_INDEX *cardIndex, enum SortField sortField);

#endif // CARD_INDEX_H
