#pragma once
#include "Node.h"
#include <vector>
#include <fstream>

class List {
private:
    /*  C++11
        shared_ptr - это умный указатель, который обеспечивает автоматическое управление памятью для динамически выделенных объектов. 
        Умные указатели управляют временем жизни динамически выделенных ресурсов, таких как объекты классов, без явного вызова операторов new и delete, 
        что существенно упрощает управление памятью
    */
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t size;

    // Приватные методы для сортировки списка методом быстрой сортировки
    void quickSort(std::vector<Circle>& arr, int low, int high);
    int partition(std::vector<Circle>& arr, int low, int high);

public:
    // Конструктор по умолчанию
    List();
    // Метод для добавления элемента в конец списка
    void addToTail(const Circle& circle);
    // Метод для добавления элемента в начало списка
    void addToHead(const Circle& circle);
    // Метод для удаления первого вхождения элемента из списка
    void remove(const Circle& circle);
    // Метод для удаления всех вхождений элемента из списка
    void removeAll(const Circle& circle);
    // Метод для сортировки списка
    void sortList();
    // Конструктор копирования
    List(const List& other);
    // Оператор присваивания
    List& operator=(const List& other);
    // Конструктор перемещения
    List(List&& other) noexcept;
    // Оператор перемещения
    List& operator=(List&& other) noexcept;
    // Перегрузка оператора << для вывода списка в поток
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    // Перегрузка оператора >> для чтения списка из потока
    friend std::istream& operator>>(std::istream& is, List& list);
};