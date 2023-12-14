// File: list.cpp

#include "list.h"
#include <iostream>

Node* addToBeginning(Node* head, int value) {
    Node* newNode = new Node{value, head};
    return newNode;
}

bool removeFromList(Node*& head, int value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void printListReverse(Node* head) {
    if (head == nullptr) {
        return;
    }

    printListReverse(head->next);
    std::cout << head->data << " ";
}
