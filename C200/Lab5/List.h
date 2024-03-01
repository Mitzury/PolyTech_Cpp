#include "Node.h"

class List {
private:
    Node Head;     // ��������� �������, ������� �������� ��������� ������ ������
    Node Tail;     // ��������� �������, ������� �������� ��������� ����� ������
    size_t m_size; // ���������� ���������

public:
    List();
    ~List();

    // ����������� �����������
    List(const List& other);

    // �������� ������������
    List& operator=(const List& other);

    // ����������� �����������
    List(List&& other) noexcept;

    // �������� �����������
    List& operator=(List&& other) noexcept;

    void AddToTail(const Circle& circle);
    bool remove(const Circle& circle);
    size_t removeAll(const Circle& circle);
    void clear();
    void AddToHead(const Circle& circle);
    void SortList();

    // ���������� ��������� ������ ��� ������ List
    friend std::ostream& operator<<(std::ostream& os, const List& list);
};