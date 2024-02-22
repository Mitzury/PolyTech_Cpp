#include "List.h"

// Конструктор класса List, инициализирующий указатели на начало и конец списка, а также размер списка
List::List() : head(nullptr), tail(nullptr), size(0) {}

void List::addToTail(const Circle& circle) {
    // Создание нового узла списка с помощью умного указателя
    std::shared_ptr<Node> newNode = std::make_shared<Node>(circle);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void List::addToHead(const Circle& circle) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(circle); // Создание нового узла списка с помощью умного указателя
    if (head == nullptr) { // Если список пуст
        head = newNode; // Устанавливаем новый узел как начало списка
        tail = newNode; // и как конец списка
    }
    else { // Если список не пуст
        newNode->next = head; // Устанавливаем указатель следующего узла нового узла на текущее начало списка
        head->prev = newNode; // Устанавливаем указатель предыдущего узла текущего начала списка на новый узел
        head = newNode; // Устанавливаем новый узел как новое начало списка
    }
    size++; // Увеличиваем размер списка
}

void List::remove(const Circle& circle) {
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == circle) { // Если данные текущего узла равны целевому кругу
            if (current == head) { // Если текущий узел - это начало списка
                head = current->next; // Устанавливаем новое начало списка на следующий узел
                if (head != nullptr)
                    head->prev.reset(); // Обнуляем указатель на предыдущий узел нового начала списка
            }
            else if (current == tail) { // Если текущий узел - это конец списка
                tail = current->prev; // Устанавливаем новый конец списка на предыдущий узел
                if (tail != nullptr)
                    tail->next.reset(); // Обнуляем указатель на следующий узел нового конца списка
            }
            else { // Если текущий узел находится где-то в середине списка
                current->prev->next = current->next; // Устанавливаем указатель на следующий узел от предыдущего узла текущего узла на следующий узел от текущего узла
                current->next->prev = current->prev; // Устанавливаем указатель на предыдущий узел от следующего узла текущего узла на предыдущий узел от текущего узла
            }
            size--; // Уменьшаем размер списка
            break; // Прерываем цикл
        }
        current = current->next; // Переходим к следующему узлу списка
    }
}

void List::removeAll(const Circle& circle) {
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == circle) { // Если данные текущего узла равны целевому кругу
            if (current == head) { // Если текущий узел - это начало списка
                head = current->next; // Устанавливаем новое начало списка на следующий узел
                if (head != nullptr)
                    head->prev.reset(); // Обнуляем указатель на предыдущий узел нового начала списка
            }
            else if (current == tail) { // Если текущий узел - это конец списка
                tail = current->prev; // Устанавливаем новый конец списка на предыдущий узел
                if (tail != nullptr)
                    tail->next.reset(); // Обнуляем указатель на следующий узел нового конца списка
            }
            else { // Если текущий узел находится где-то в середине списка
                current->prev->next = current->next; // Устанавливаем указатель на следующий узел от предыдущего узла текущего узла на следующий узел от текущего узла
                current->next->prev = current->prev; // Устанавливаем указатель на предыдущий узел от следующего узла текущего узла на предыдущий узел от текущего узла
            }
            size--; // Уменьшаем размер списка
        }
        current = current->next; // Переходим к следующему узлу списка
    }
}

void List::quickSort(std::vector<Circle>& arr, int low, int high) {
    if (low < high) { // Если индекс начала массива меньше индекса конца
        int pi = partition(arr, low, high); // Находим индекс опорного элемента после разбиения массива
        quickSort(arr, low, pi - 1); // Рекурсивно сортируем элементы меньше опорного элемента
        quickSort(arr, pi + 1, high); // Рекурсивно сортируем элементы больше опорного элемента
    }
}

int List::partition(std::vector<Circle>& arr, int low, int high) {
    Circle pivot = arr[high]; // Выбираем последний элемент массива как опорный элемент
    int i = low - 1; // Инициализируем индекс наименьшего элемента

    for (int j = low; j < high; j++) { // Проходим по всем элементам массива, кроме последнего (опорного элемента)
        if (arr[j].getRadius() <= pivot.getRadius()) { // Если текущий элемент меньше или равен опорному
            i++; // Увеличиваем индекс наименьшего элемента
            std::swap(arr[i], arr[j]); // Меняем местами текущий элемент и элемент с индексом наименьшего элемента
        }
    }
    std::swap(arr[i + 1], arr[high]); // Меняем местами опорный элемент и элемент, стоящий после наименьшего элемента
    return i + 1; // Возвращаем индекс опорного элемента
}

void List::sortList() {
    if (size <= 1) return; // Если размер списка меньше или равен 1, нет необходимости в сортировке
    std::vector<Circle> circles; // Создаем вектор для хранения элементов списка
    std::shared_ptr<Node> current = head; // Устанавливаем указатель на текущий узел в начало списка
    while (current != nullptr) { // Пока не достигнут конец списка
        circles.push_back(current->data); // Добавляем данные текущего узла в вектор
        current = current->next; // Переходим к следующему узлу списка
    }
    quickSort(circles, 0, circles.size() - 1); // Вызываем функцию быстрой сортировки для вектора
    current = head; // Устанавливаем указатель на текущий узел в начало списка
    for (const auto& circle : circles) { // Перебираем отсортированный вектор
        current->data = circle; // Заменяем данные текущего узла на данные из вектора
        current = current->next; // Переходим к следующему узлу списка
    }
}

List::List(const List& other) {
    std::shared_ptr<Node> current = other.head;
    while (current != nullptr) {
        addToTail(current->data);
        current = current->next;
    }
}

List& List::operator=(const List& other) {
    if (this != &other) {
        head.reset();
        tail.reset();
        size = 0;

        std::shared_ptr<Node> current = other.head;
        while (current != nullptr) {
            addToTail(current->data);
            current = current->next;
        }
    }
    return *this;
}

List::List(List&& other) noexcept {
    head = std::move(other.head);
    tail = std::move(other.tail);
    size = other.size;

    other.head.reset();
    other.tail.reset();
    other.size = 0;
}

List& List::operator=(List&& other) noexcept {
    if (this != &other) {
        head = std::move(other.head);
        tail = std::move(other.tail);
        size = other.size;

        other.head.reset();
        other.tail.reset();
        other.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    std::shared_ptr<Node> current = list.head;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    os << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, List& list) {
    Circle circle(0, 0, 0);
    while (is >> circle) {
        list.addToTail(circle);
    }
    return is;
}