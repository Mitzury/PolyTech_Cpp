#include "Node.h"

class List {
private:
    Node Head;     // фиктивный элемент, который является признаком начала списка
    Node Tail;     // фиктивный элемент, который является признаком конца списка
    size_t m_size; // количество элементов

public:
    List();
    ~List();

    // Конструктор копирования
    List(const List& other);

    // Оператор присваивания
    List& operator=(const List& other);

    // Конструктор перемещения
    List(List&& other) noexcept;

    // Оператор перемещения
    List& operator=(List&& other) noexcept;

    void AddToTail(const Circle& circle);
    bool remove(const Circle& circle);
    size_t removeAll(const Circle& circle);
    void clear();
    void AddToHead(const Circle& circle);
    void SortList();


    // Перегрузка оператора << для вывода списка в поток
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    // Перегрузка оператора >> для чтения списка из потока
    friend std::istream& operator>>(std::istream& is, List& list);

};