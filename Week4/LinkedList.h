#ifndef LINKEDLIST_H
#define LINKEDLIST_H
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
class LinkedList {
private:
    Node<T>* head;
    int size = 0;

public:
    //constructor
    LinkedList() : head(nullptr) {}

    // ban shallow copies
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    //destructor 
    ~LinkedList() {
        clear(); // clear method will do all of our cleanup
    }

    void insertFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void removeFront() {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
    }

    void insertAfter(T val, T before) {
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node<T>* current = head;
        while (current != nullptr && current->data != before) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Could not find the value you wanted" << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(val);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        size++;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NONE" << std::endl;
    }

    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }
};

#endif // LINKEDLIST_H