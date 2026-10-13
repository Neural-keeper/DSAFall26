// priority queue - implement using a list
// min-priority queue - remove the minimum priority value first - everything in descending order
// back will hold the minimum value
// keep track of priority using key-value pairs
// key = priority - high priority = low key
// value = actual data

// [5, 3, 8, 1] my priority = the integer value

// lost first in first out behavior of queues - lead up to heaps

#include <iostream>
#include <vector>
#include <list> // use a STL list for the priority queue
#include <stdexcept> 

/*
STL List methods:
    push_back(value)
    pop_back(value)
    push_front(value)
    pop_front()
    front()
    back()
    empty()
    insert(iterator, value) - inserts a value before the position pointed to by the iterator
    erase(iterator)
*/

using namespace std;

class priority_queue {
private:
    list<int> elements; // acting as our priority queue

public:
    priority_queue() {}
    ~priority_queue() {}

    bool empty() {
        return elements.empty();
    }

    std::size_t size() {
        return elements.size();
    }

    // push = insert - O(n) - look for right place to insert to maintain descending order
    void push(int value) {
        // traverse the list
        auto it = elements.begin(); // the position of the list start
        while (it != elements.end() && *it > value) {
            ++it;
        } // traverse list until we find right position
        elements.insert(it, value); // keeping things simple, value is key
        // ensuring everything is in descending order
    }

    // pop - this removes the value with the minimum key and return the value
    int pop() {
        if (empty()) {
            throw runtime_error("Priority Queue is empty!");
        }
        int minValue = elements.back(); // minimum value is at the back
        elements.pop_back(); // remove that minimum value
        return minValue;
    }

    // top - this returns the minimum value
    int top() {
        if (empty()) {
            throw runtime_error("Priority Queue is empty!");
        }
        return elements.back();
    }
};

int main() {
    priority_queue pq;
    pq.push(5); // pq sorted descending = [5]
    pq.push(3); // pq sorted descending = [5, 3]
    pq.push(8); // pq sorted descending = [8, 5, 3]
    pq.push(1); // pq sorted descending = [8, 5, 3, 1] (1 is at the back, meaning it's the minimum)

    cout << "Size of priority queue: " << pq.size() << endl; // expected: 4
    cout << "Top element (min): " << pq.top() << endl; // expected: 1

    while (!pq.empty()) {
        cout << "Popped element: " << pq.pop() << endl; // expected: 1, 3, 5, 8
    }

    return 0;
}