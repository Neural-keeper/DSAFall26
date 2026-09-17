#ifndef STACK_LL_H
#define STACK_LL_H

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

template <typename T>
class StackLinkedList {
private:
    LinkedList<T> stack;

public:
    bool isEmpty() const { return stack.isEmpty(); }
    int size() const { return stack.getSize(); }

    T top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty!");
        T top = stack.getHead()->data;
        return top;
    }

    void push(T val) {
        stack.insertFront(val);
    }

    T pop() {
        if (isEmpty()) throw std::underflow_error("Stack is empty!");
        T popped = stack.getHead()->data;
        stack.removeFront();
        return popped;
    }
};

#endif