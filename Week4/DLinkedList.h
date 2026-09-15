#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
// ^ starting for header files - you can put code you'll reuse a lot here

#include <iostream>

// Generic Node structure
template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

// Generic LinkedList Class
template <typename T>
class DLinkedList {
private:
    Node<T>* head;
    Node<T>* tail; 
    int size = 0;

public:
    //constructor
    DLinkedList() : head(nullptr) {}

    // ban shallow copies
    DLinkedList(const DLinkedList&) = delete;
    DLinkedList& operator=(const DLinkedList&) = delete;

    //destructor 
    ~DLinkedList() {
        clear(); // clear method will do all of our cleanup
    }

    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    void insertFront(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode; // set both head and tail to newNode
        } else {
            newNode->next = head->next;
            head->prev = newNode; // one change
            head = newNode;
        }
        size++;
    }
    
    void insertAfter(T val, T before) {
        Node<T>* current = head;
        while (current != nullptr && current->data != before) {
            current = current->next;
        } 

        if (current == nullptr) {
            std::cout << "The value " << before << " was not found!" << std::endl;
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        newNode->next = current->next;
        newNode->prev = current;
        
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        size++;
    }

    void insertEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void remove(T val) {
        // generic removing the first node with value val
        if (isEmpty()) return;

        Node<T>* current = head;
        while (current != nullptr && current->data != val) {
            current = current.next;
        }

        // value not found
        if (current == nullptr) return;

        if (current == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (current == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            /*
                  /------------------------\
            <- |     |  <- |     | ->   |     | ->
                   \------------------------/
            */
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        size--;
    }

    void display() {
        Node<T>* current = head;
        std::cout << "nullptr <-> ";
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
};

#endif // DLINKEDLIST_H