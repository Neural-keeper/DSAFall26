#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
// ^ starting for header files - you can put code you'll reuse a lot here

#include <iostream>

// Generic Node structure
template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Generic LinkedList Class
template <typename T>
class CLinkedList {
private:
    Node<T>* cursor;
    // tail and head
    int size = 0;

public:
    //constructor
    CLinkedList() : cursor(nullptr) {}

    // ban shallow copies
    CLinkedList(const CLinkedList&) = delete;
    CLinkedList& operator=(const CLinkedList&) = delete;

    //destructor 
    ~CLinkedList() {
        clear(); // clear method will do all of our cleanup
    }

    int getSize() const { return size; }
    bool isEmpty() const { return {size == 0};}

    void insertFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (cursor == nullptr) {
            cursor = newNode;
            cursor->next = cursor; // forgot to make it point to itself lol
        } else {
            newNode->next = cursor->next; // Point to current head
            cursor->next = newNode;       // Cursor's next becomes new head
        }
        size++;
    }
    
    void removeFront() {
        if (cursor == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node<T>* head = cursor->next; //store head

        if (cursor == head) { 
            delete cursor;
            cursor = nullptr;
        } else {
            // More than 1 node: bypass old head
            cursor->next = head->next;
            delete head;
        }
        size--;
    }

    void display() const {
        if (cursor == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node<T>* head = cursor->next;
        Node<T>* current = head;

        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head); // Stop when we return to where we started

        std::cout << "(back to head: " << head->data << ")" << std::endl;
    }

    void clear() {
        if (!cursor) return;

        Node<T>* head = cursor->next;
        cursor->next = nullptr;

        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        cursor = nullptr;
        size = 0;
    }
};

#endif // CLINKEDLIST_H