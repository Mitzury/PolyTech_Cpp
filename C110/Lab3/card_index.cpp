// File: card_index.cpp

#include "card_index.h"
#include <cstdio>
#include <cstring>

void saveToFile(const struct CARD_INDEX *cardIndex, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != nullptr) {
        fprintf(file, "%d\n", cardIndex->count);
        for (int i = 0; i < cardIndex->count; ++i) {
            fprintf(file, "%s %s %d %.2f %s\n",
                    cardIndex->books[i].author,
                    cardIndex->books[i].title,
                    cardIndex->books[i].year,
                    cardIndex->books[i].price,
                    cardIndex->books[i].category);
        }
        fclose(file);
        printf("Card Index saved to %s\n", filename);
    } else {
        printf("Error opening the file for writing.\n");
    }
}

void loadFromFile(struct CARD_INDEX *cardIndex, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != nullptr) {
        int count;
        fscanf(file, "%d", &count);

        if (count > cardIndex->capacity) {
            delete[] cardIndex->books;
            cardIndex->capacity = count;
            cardIndex->books = new struct BOOK[cardIndex->capacity];
        }

        for (int i = 0; i < count && i < cardIndex->capacity; ++i) {
            fscanf(file, "%s %s %d %f %s",
                    cardIndex->books[i].author,
                    cardIndex->books[i].title,
                    &cardIndex->books[i].year,
                    &cardIndex->books[i].price,
                    cardIndex->books[i].category);
        }

        cardIndex->count = count;

        fclose(file);
        printf("Card Index loaded from %s\n", filename);
    } else {
        printf("Error opening the file for reading.\n");
    }
}


void swapBooks(struct BOOK *book1, struct BOOK *book2) {
    struct BOOK temp = *book1;
    *book1 = *book2;
    *book2 = temp;
}

void bubbleSort(struct CARD_INDEX *cardIndex, enum SortField sortField) {
    for (int i = 0; i < cardIndex->count - 1; ++i) {
        for (int j = 0; j < cardIndex->count - i - 1; ++j) {
            switch (sortField) {
                case AUTHOR:
                    if (strcmp(cardIndex->books[j].author, cardIndex->books[j + 1].author) > 0) {
                        swapBooks(&cardIndex->books[j], &cardIndex->books[j + 1]);
                    }
                    break;
                case TITLE:
                    if (strcmp(cardIndex->books[j].title, cardIndex->books[j + 1].title) > 0) {
                        swapBooks(&cardIndex->books[j], &cardIndex->books[j + 1]);
                    }
                    break;
                case YEAR:
                    if (cardIndex->books[j].year > cardIndex->books[j + 1].year) {
                        swapBooks(&cardIndex->books[j], &cardIndex->books[j + 1]);
                    }
                    break;
                case PRICE:
                    if (cardIndex->books[j].price > cardIndex->books[j + 1].price) {
                        swapBooks(&cardIndex->books[j], &cardIndex->books[j + 1]);
                    }
                    break;
                case CATEGORY:
                    if (strcmp(cardIndex->books[j].category, cardIndex->books[j + 1].category) > 0) {
                        swapBooks(&cardIndex->books[j], &cardIndex->books[j + 1]);
                    }
                    break;
                default:
                    printf("Invalid sort field.\n");
            }
        }
    }
}

