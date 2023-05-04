#ifndef LINKED_LIST_LIST_H
#define LINKED_LIST_LIST_H
#pragma once

// node to element listy, ktory przechowuje pointer do poprzedniego elementu, swoja wartosc i pointer do nastepnego
class node {
public:
    node() {
        this->next = nullptr;
        this->prev = nullptr;
    }
    node* next = nullptr;
    node* prev = nullptr;
    signed int value;
};

// lista elementow
class List {
public:
    // head przechowuje pointer do pierwszego noda listy, tail do ostatniego
    node* head = nullptr;
    node* tail = nullptr;


    // funkcja dodaje nastepny node do listy
    void addAfter(int element) {
        // jezeli nie istnieje pierwszy node, zostaje on stworzony
        if(head == nullptr) {
            head = new node();
            head->value = element;
            tail = head;
        }

        // jezeli istnieje juz pierwszy node listy: ostatni node listy otrzymuje pointer do "nowego noda", "nowy node" otrzymuje pointer do wczesniejszego
        else {
            tail->next = new node();
            tail->next->value = element;
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    void deleteFirst() {
        node* first = this->head;
        this->head = this->head->next;
        // jezeli lista nie ma noda (elementu), to tail i head nie przechowuja wartosci; jezeli ma, to head nie powinien wskazywac na element wczesniejszy
        if(head == nullptr) tail = head;
        else
            head->prev = nullptr;
        delete first;
    }

    // funkcja przekazuje pointer do nastepnego noda listy
    // jezeli nie pobrano zadnego noda, zwraca pierwszy
    node* getNext(node* currentNode) {
        if (currentNode == nullptr) return this->head;
        return currentNode->next;
    }

    int getIndex(int key) {
        node* searched = getNext(nullptr);
        int index = 0;
        while (searched != nullptr) {
            if (searched->value == key)
                return index;
            searched = searched->next;
            index += 1;
        }
        return -1;
    }

    // usuwa wszytskie nody
    void deleteAll() {
        if (this->head != nullptr) {
            // wyjdz z petli jezeli nie ma nastepnego noda
            while (this->head->next != nullptr) {
                deleteFirst();
            }
            deleteFirst();
        }
    }
};

#endif //LINKED_LIST_LIST_H
