#include "Node.h"

class List {
private:
    Node Head;     // фиктивный элемент, который €вл€етс€ признаком начала списка
    Node Tail;     // фиктивный элемент, который €вл€етс€ признаком конца списка
    size_t m_size; // количество элементов

public:
    List();
    ~List();

    //  онструктор копировани€
    List(const List& other);

    // ќператор присваивани€
    List& operator=(const List& other);

    //  онструктор перемещени€
    List(List&& other) noexcept;

    // ќператор перемещени€
    List& operator=(List&& other) noexcept;

    void AddToTail(const Circle& circle);
    bool remove(const Circle& circle);
    size_t removeAll(const Circle& circle);
    void clear();
    void AddToHead(const Circle& circle);
    void SortList();

    // перегрузка оператора вывода дл€ класса List
    friend std::ostream& operator<<(std::ostream& os, const List& list);
};