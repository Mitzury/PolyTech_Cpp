// File: list.h

#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
};

Node* addToBeginning(Node* head, int value);
bool removeFromList(Node*& head, int value);
void printList(Node* head);
void printListReverse(Node* head);

#endif // LIST_H
