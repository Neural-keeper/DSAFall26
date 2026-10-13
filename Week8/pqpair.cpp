// priority queue - implement using a list
// min-priority queue - remove the minimum priority value first - everything in descending order
// back will hold the minimum value
// keep track of priority using key-value pairs
// key = priority - high priority = low key
// key value - struct

// [5, 3, 8, 1] my priority = the integer value

// lost first in first out behavior of queues - lead up to heaps

#include <iostream>
#include <vector>
#include <list> // use a STL list for the priority queue
#include <stdexcept> 
#include <string>

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

struct element {
    int priority;
    string value;

    element(int p, string v) : priority(p), value(v) {}
};

class priority_queue {
private:
    list<element> elements; // acting as our priority queue

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
    void push(element& e) {
        // traverse the list
        auto it = elements.begin(); // the position of the list start
        while (it != elements.end() && it->priority > e.priority) {
            ++it;
        } // traverse list until we find right position
        elements.insert(it, e); // keeping things simple, value is key
        // ensuring everything is in descending order
    }

    // pop - this removes the value with the minimum key and return the value
    string pop() {
        if (empty()) {
            throw runtime_error("Priority Queue is empty!");
        }
        string minValue = elements.back().value; // minimum value is at the back
        elements.pop_back(); // remove that minimum value
        return minValue;
    }

    // top - this returns the minimum value
    string top() {
        if (empty()) {
            throw runtime_error("Priority Queue is empty!");
        }
        string minValue = elements.back().value;
        return minValue;
    }
};

int main() {
    priority_queue pq;
    element e1(100, "apple");
    element e2(1000, "frozen berries");
    element e3(50, "banana");

    pq.push(e1);
    pq.push(e2);
    pq.push(e3);

    cout << "Size of priority queue: " << pq.size() << endl; // expected: 3
    cout << "Top element (min): " << pq.top() << endl; // expected: banana

    while (!pq.empty()) {
        cout << "Popped element: " << pq.pop() << endl; // expected: banana, apple, frozen berries
    }

    return 0;
}

/*
explanation of why our pq was not adding things
pointer errors
*/