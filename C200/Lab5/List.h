#pragma once
#include "Node.h"
#include <string>
using namespace std;
// класс двусвязного списка
class List {
private:
    Node* head;
    Node* tail;

public:
    // пустой конструктор
    List() : head(nullptr), tail(nullptr) {}
    // очищаем память после использованя класса
    ~List();


    // Конструктор перемещения
    List(List&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }
    // Оператор присваивания перемещения
    List& operator=(List&& other);

    // Конструктор копирования
    List(const List& other);

    // Оператор присваивания копирования
    List& operator=(const List& other);


    // метод добавления ноды в конец списка
    void AddToTail(const Circle& data);
    // метод добавления ноды в начало списка
    void AddToHead(const Circle& data);
    // метод удаления первой ноды, поля которой совпадают с данной
    void Remove(const Circle& data);
    // метод удаления всех нод, поля которых совпадают с данной
    void RemoveAll(const Circle& data);
    // сортировка спика по площади кругов
    void SortList();


    // метод, выводящий содержимое списка, с помощью вывода в консоль каждого своего элемента
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    // метод, позволяющий из поступающего потока задать двусвязный список
    friend std::istream& operator>>(std::istream& is, List& list);
};