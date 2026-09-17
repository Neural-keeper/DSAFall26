#ifndef STACK_LL_H
#define STACK_LL_H

#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class StackVector {
private:
    std::vector<T> stack;

public:
    bool isEmpty() const { return stack.empty(); }
    int size() const { return static_cast<int>(stack.size()); }

    T top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty!");
        return stack.back();
    }

    void push(T val) {
        stack.push_back(val);
    }

    T pop() {
        if (isEmpty()) throw std::underflow_error("Stack is empty!");
        T popped = stack.back();
        stack.pop_back();
        return popped;
    }
};

#endif