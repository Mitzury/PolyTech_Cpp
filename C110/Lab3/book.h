#ifndef BOOK_H
#define BOOK_H

#include <string>

struct BOOK {
    std::string author;
    std::string title;
    int year;
    float price;
    std::string category;
};

void printBookInfo(const BOOK& book);
void fillBookFields(BOOK& book);

#endif // BOOK_H
