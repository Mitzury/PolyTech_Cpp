#include "List.h"

List::List() : head(nullptr), tail(nullptr), size(0) {}

void List::addToTail(const Circle& circle) {
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
    std::shared_ptr<Node> newNode = std::make_shared<Node>(circle);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void List::remove(const Circle& circle) {
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        if (current->data == circle) {
            if (current == head) {
                head = current->next;
                if (head != nullptr)
                    head->prev.reset();
            }
            else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr)
                    tail->next.reset();
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            size--;
            break;
        }
        current = current->next;
    }
}

void List::removeAll(const Circle& circle) {
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        if (current->data == circle) {
            if (current == head) {
                head = current->next;
                if (head != nullptr)
                    head->prev.reset();
            }
            else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr)
                    tail->next.reset();
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            size--;
        }
        current = current->next;
    }
}

void List::quickSort(std::vector<Circle>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int List::partition(std::vector<Circle>& arr, int low, int high) {
    Circle pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].getRadius() <= pivot.getRadius()) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void List::sortList() {
    if (size <= 1) return;
    std::vector<Circle> circles;
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        circles.push_back(current->data);
        current = current->next;
    }

    quickSort(circles, 0, circles.size() - 1);

    current = head;
    for (const auto& circle : circles) {
        current->data = circle;
        current = current->next;
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