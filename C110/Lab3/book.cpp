// File: book.cpp

#include "book.h"

void printBookInfo(const struct BOOK *book) {
    printf("Author: %s\n", book->author);
    printf("Title: %s\n", book->title);
    printf("Year: %d\n", book->year);
    printf("Price: %.2f\n", book->price);
    printf("Category: %s\n", book->category);
}

void fillBookFields(struct BOOK *book) {
    printf("Enter author: ");
    scanf("%99s", book->author);
    
    printf("Enter title: ");
    scanf("%99s", book->title);
    
    printf("Enter year: ");
    scanf("%d", &book->year);
    
    printf("Enter price: ");
    scanf("%f", &book->price);
    
    printf("Enter category: ");
    scanf("%49s", book->category);
}
