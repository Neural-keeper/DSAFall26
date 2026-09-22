// Queue implementation using a circular linked list
#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>
#include <stdexcept>
#include "CLinkedList.h"

template <typename T>
class QueueLinkedList {
private:
    CLinkedList<T> queue;

public:
    QueueLinkedList() = default; // default constructor
    ~QueueLinkedList() = default; // default destructor

    bool isEmpty() const {
        return queue.isEmpty();
    }

    int getSize() const {
        return queue.getSize();
    }

    void enqueue(T val) {
        queue.insertEnd(val);
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        queue.removeFront();
    }

    T front() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return queue.front();
    }
};

#endif // QUEUELL_H