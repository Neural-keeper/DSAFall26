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


    // insert only in sorted order
    void sortedInsert(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (isEmpty()) {
            cursor = newNode;
            cursor->next = cursor; // point back to itself
            size++;
            return;
        }

        Node<T>* prev = cursor->next; // Head
        Node<T>* current = prev->next;

        // If only one element in the list
        if (prev == cursor) {
            prev->next = newNode;
            newNode->next = prev;
            if (val >= prev->data) {
                cursor = newNode; // case where newNode is maximal
            }
            size++;
            return;
        }

        Node<T>* start = prev;
        do {
            // 1. Normal case: fits strictly between prev and current
            if (prev->data <= val && val <= current->data) {
                prev->next = newNode;
                newNode->next = current;
                size++;
                return;
            }
            // part I missed - this is a check for when prev = tail = max
            // and current = head = min
            else if (prev->data > current->data) {
                if (val >= prev->data || val <= current->data) {
                    prev->next = newNode;
                    newNode->next = current;
                    if (val >= prev->data) {
                        cursor = newNode;
                    } // it's the new maximum if it's bigger than the current maximum
                    size++;
                    return;
                } // can still add since it's a max or min point
            }

            prev = current;
            current = current->next;
        } while (prev != start); // instead of checking to match with head, we stop whe
        // we return to where we started

        // 3. Fallback case: if all elements are equal or it belongs at the very end
        prev->next = newNode;
        newNode->next = current;
        cursor = newNode; // adding to the very end = update tail/cursor
        size++;
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