#include "book.h"
#include <iostream>

void printBookInfo(const BOOK& book) {
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Year: " << book.year << std::endl;
    std::cout << "Price: " << book.price << std::endl;
    std::cout << "Category: " << book.category << std::endl;
}

void fillBookFields(BOOK& book) {
    std::cout << "Enter author: ";
    //std::getline(std::cin, book.author);
    std::cin >> book.author;

    std::cout << "Enter title: ";
    //std::getline(std::cin, book.title);
    std::cin >> book.title;

    std::cout << "Enter year: ";
    std::cin >> book.year;

    std::cout << "Enter price: ";
    std::cin >> book.price;

    // Дополнительная проверка на отрицательную цену
    while (book.price < 0) {
        std::cout << "Price cannot be negative. Please enter a valid price: ";
        std::cin >> book.price;
    }

    std::cin.ignore(); // Очистить буфер после ввода числа
    std::cout << "Enter category: ";
    std::getline(std::cin, book.category);
}
