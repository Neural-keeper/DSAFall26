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

    // get front element
    T front() const {
        if (isEmpty()) {
            throw std::underflow_error("List is empty!");
        }
        return cursor->next->data; // head element
    }


    // insert at end
    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (isEmpty()) {
            cursor = newNode;
            cursor->next = cursor; // point back to itself
            size++;
            return;
        }

        newNode->next = cursor->next; // point to head
        cursor->next = newNode; // old tail points to new node
        cursor = newNode; // update tail to new node
        size++;
    }

    // remove from front
    void removeFront() {
        if (isEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node<T>* head = cursor->next; // head
        if (head == cursor) { // only one element
            delete head;
            cursor = nullptr;
        } else {
            cursor->next = head->next; // tail points to new head
            delete head;
        }
        size--;
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node<T>* head = cursor->next;
        Node<T>* current = head;

        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        std::cout << "loops back" << std::endl;
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

// added a couple of methods to make it easier to use in the queue implementation