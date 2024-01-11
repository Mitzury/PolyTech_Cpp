// Файл "card_index.cpp"

#include "card_index.h"
#include <iostream>
#include <cstdio>

void initializeCardIndex(CARD_INDEX& cardIndex, int initialCapacity) {
    cardIndex.books = new BOOK[initialCapacity];
    cardIndex.capacity = initialCapacity;
    cardIndex.count = 0;
}

void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Print card index\n";
    std::cout << "2. Add a book\n";
    std::cout << "3. Remove a book\n";
    std::cout << "4. Save to file\n";
    std::cout << "5. Load from file\n";
    std::cout << "6. Sort card index\n";
    std::cout << "7. Exit\n";
}

void printMenu_1() {
    std::cout << "Menu:\n";
    std::cout << "1. Print card index\n";
    std::cout << "2. Add a book\n";
    std::cout << "3. Remove a book\n";
    std::cout << "4. Exit\n";
}

void printCardIndex(const CARD_INDEX& cardIndex) {
    std::cout << "Card Index:\n";
    for (int i = 0; i < cardIndex.count; ++i) {
        std::cout << "Book " << i + 1 << ":\n";
        printBookInfo(cardIndex.books[i]);
        std::cout << "---------------------\n";
    }
}

void addBook(CARD_INDEX& cardIndex) {
    if (cardIndex.count < cardIndex.capacity) {
        fillBookFields(cardIndex.books[cardIndex.count]);
        cardIndex.count++;
        std::cout << "Book added successfully!\n";
    }
    else {
        std::cout << "Card index is full. Unable to add more books.\n";
    }
}

void removeBook(CARD_INDEX& cardIndex) {
    if (cardIndex.count > 0) {
        cardIndex.count--;
        std::cout << "Last book removed successfully!\n";
    }
    else {
        std::cout << "Card index is empty. No books to remove.\n";
    }
}

void saveToFile(const CARD_INDEX& cardIndex, const char* fileName) {
    FILE* file = std::fopen(fileName, "w");
    if (file) {
        fprintf(file, "%d\n", cardIndex.count);
        for (int i = 0; i < cardIndex.count; ++i) {
            fprintf(file, "%s\n%s\n%d\n%f\n%s\n",
                cardIndex.books[i].author.c_str(),
                cardIndex.books[i].title.c_str(),
                cardIndex.books[i].year,
                cardIndex.books[i].price,
                cardIndex.books[i].category.c_str());
        }
        std::fclose(file);
        std::cout << "Card index saved to file successfully!\n";
    }
    else {
        std::cout << "Error saving to file.\n";
    }
}

void loadFromFile(CARD_INDEX& cardIndex, const char* fileName) {
    FILE* file = std::fopen(fileName, "r");
    if (file) {
        int numBooks;
        fscanf(file, "%d", &numBooks);

        if (numBooks <= cardIndex.capacity) {
            cardIndex.count = numBooks;
            for (int i = 0; i < numBooks; ++i) {
                fscanf(file, "%s %s %d %f %s",
                    &cardIndex.books[i].author[0],
                    &cardIndex.books[i].title[0],
                    &cardIndex.books[i].year,
                    &cardIndex.books[i].price,
                    &cardIndex.books[i].category[0]);
            }
            std::fclose(file);
            std::cout << "Card index loaded from file successfully!\n";
        }
        else {
            std::fclose(file);
            std::cout << "Error: Card index in the file exceeds the capacity.\n";
        }
    }
    else {
        std::cout << "Error loading from file.\n";
    }
}

void sortBooks(CARD_INDEX& cardIndex, SortField sortField) {
    // Пузырьковая сортировка
    for (int i = 0; i < cardIndex.count - 1; ++i) {
        for (int j = 0; j < cardIndex.count - i - 1; ++j) {
            switch (sortField) {
            case AUTHOR:
                if (cardIndex.books[j].author > cardIndex.books[j + 1].author) {
                    std::swap(cardIndex.books[j], cardIndex.books[j + 1]);
                }
                break;
            case TITLE:
                if (cardIndex.books[j].title > cardIndex.books[j + 1].title) {
                    std::swap(cardIndex.books[j], cardIndex.books[j + 1]);
                }
                break;
            case YEAR:
                if (cardIndex.books[j].year > cardIndex.books[j + 1].year) {
                    std::swap(cardIndex.books[j], cardIndex.books[j + 1]);
                }
                break;
            case PRICE:
                if (cardIndex.books[j].price > cardIndex.books[j + 1].price) {
                    std::swap(cardIndex.books[j], cardIndex.books[j + 1]);
                }
                break;
            case CATEGORY:
                if (cardIndex.books[j].category > cardIndex.books[j + 1].category) {
                    std::swap(cardIndex.books[j], cardIndex.books[j + 1]);
                }
                break;
            }
        }
    }
    std::cout << "Card index sorted successfully!\n";
}

void cleanUp(CARD_INDEX& cardIndex) {
    delete[] cardIndex.books;
    cardIndex.books = nullptr;
    cardIndex.capacity = 0;
    cardIndex.count = 0;
}
