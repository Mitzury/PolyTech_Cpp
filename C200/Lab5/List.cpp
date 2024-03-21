#include "List.h"

List::List(List&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
 }

//Оператор присваивания перемещения
// используется для перемещения(move) содержимого одного объекта списка в другой.
List& List::operator=(List&& other) {
    if (this != &other) {
        // Очищаем текущий список
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        // Перемещаем данные из другого списка
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

List::List(const List& other) : head(nullptr), tail(nullptr) {
    Node* current = other.head;
    while (current != nullptr) {
        AddToTail(current->data);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) {
        // Очищаем текущий список
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        // Копируем данные из другого списка
        current = other.head;
        while (current != nullptr) {
            AddToTail(current->data);
            current = current->next;
        }
    } return *this;
}

void List::Reverse()
{
        Node* temp = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }

}

void List::AddToTail(const Circle& data) {
    Node* newnode = new Node(data); // Создаем новый узел с переданными данными
    if (head == nullptr) { // Если список пустой
        head = tail = newnode; // Устанавливаем новый узел как голову и хвост
    }
    else { // Если список не пустой
        newnode->prev = tail; // Устанавливаем указатель prev для нового узла на текущий хвост
        tail->next = newnode; // Устанавливаем указатель next для текущего хвоста на новый узел

        tail = newnode; // Обновляем хвост списка на новый узел
    }
}

void List::AddToHead(const Circle& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void List::InsertBefore(const Circle& newData, const Circle& data) {
    Node* newNode = new Node(newData);
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == data) {
            newNode->prev = curr->prev;
            newNode->next = curr;
            if (curr->prev != nullptr) {
                curr->prev->next = newNode;
            }
            curr->prev = newNode;
            if (curr == head) {
                head = newNode;
            }
            return;
        }
        curr = curr->next;
    }
}

void List::InsertAfter(const Circle& newData, const Circle& data) {
    Node* newNode = new Node(newData);
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == data) {
            newNode->prev = curr;
            newNode->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
            return;
        }
        curr = curr->next;
    }
}



void List::Remove(const Circle& data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            if (current == head) {
                head = current->next;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr)
                    tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            break;
        }
        current = current->next;
    }
}

// Функция для удаления всех узлов, поля которых совпадают с заданным значением
void List::RemoveAll(const Circle& data) {
// Если список пустой, то выходим из функции
    if (head == nullptr) {
        return;
    }
// Устанавливаем текущий узел на голову списка
    Node* current = head;
    while (current != nullptr) {
// Создаем временный указатель на текущий узел
        Node* temp = current;
        current = current->next;
// Проверяем, совпадает ли значение поля узла с заданным значением
        if (temp->data == data) {
// Проверяем, является ли текущий узел головой списка
            if (temp == head) {
                head = temp->next;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            else if (temp == tail) {
                tail = temp->prev;
                if (tail != nullptr)
                    tail->next = nullptr;
            }
            else {
// Переопределение связей перед и после элемента
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
    }
}

void List::SortList() {
    // Bubble sort
    if (head == nullptr || head == tail)
        return;
    Node* current;
    Node* temp = nullptr;
    bool swapped;
    do {
        swapped = false;
        current = head;
        while (current->next != temp) {
            if (current->data.getSquare() > current->next->data.getSquare()) {
                Circle tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = true;
            }
            current = current->next;
        } temp = current;
    } while (swapped);
}

List::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    Node* current = list.head;
    while (current != nullptr) {
        os << current->prev << " " << current->data << " " << current->next << endl;
        current = current->next;
    }
    return os;
}

std::istream& operator>>(std::istream& is, List& list) {
    std::string str;
    int x, y, radius;
    while (std::getline(is, str)) {
        sscanf(str.c_str(), "Circle (%d,%d,%d)", &x, &y, &radius);
        Circle c = Circle(x, y, radius);
        list.AddToTail(c);
    }
    return is;
}
