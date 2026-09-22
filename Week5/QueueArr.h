// Queue implementation using a circular array
#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class QueueArray {
private:
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

public:
    QueueArray(int cap) : capacity(cap), frontIndex(0), rearIndex(-1), size(0) {
        arr = new T[capacity];
    } // capacity defined during contruction, frontIndex starts at 0, rearIndex starts at -1 (since the queue is empty), and size starts at 0

    ~QueueArray() {
        delete[] arr;
    } // we need a destructor to free the memory we allocated for the array, since we 
    // allocated it on the heap (using new)

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int getSize() const {
        return size;
    }

    void enqueue(T val) {
        if (isFull()) {
            throw std::overflow_error("Queue is full!");
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        size++;
    }    

    void dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    T front() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return arr[frontIndex];
    }
}; 



#endif // QUEUEARR_H