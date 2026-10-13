#include <iostream>
#include <list>

// PriorityQueue class definition
class PriorityQueue {
private:
    struct Element {
        int value;
        int priority;
        Element(int v, int p) : value(v), priority(p) {}
    };

    std::list<Element> elements;
    int counter;

public:
    PriorityQueue() : counter(0) {}

    void push(int element, int priority) {
        auto it = elements.begin();
        while (it != elements.end() && it->priority <= priority) {
            ++it;
        }
        elements.insert(it, Element(element, priority));
        counter++;
    }

    // int pop() {
    //     if (empty()) {
    //         throw std::out_of_range("Priority queue is empty");
    //     }
    //     int value = elements.front().value;
    //     elements.pop_front();
    //     return value;
    // }

    int removeMin() {
        if (empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        auto minIt = elements.begin();
        auto it = elements.begin();
        ++it;
        while (it != elements.end()) {
            if (it->priority < minIt->priority) {
                minIt = it;
            }
            ++it;
        }
        int value = minIt->value;
        elements.erase(minIt);
        return value;
    }

    // int top() const {
    //     if (empty()) {
    //         throw std::out_of_range("Priority queue is empty");
    //     }
    //     return elements.front().value;
    // }

    bool empty() const {
        return elements.empty();
    }

    std::size_t size() const {
        return elements.size();
    }
};

// Function to sort a std::list using the PriorityQueue class
void sortListWithPriorityQueue(std::list<int>& myList) {
    PriorityQueue pq;
    // Insert elements of the list into the priority queue
    for (int elem : myList) {
        pq.push(elem, elem); // Use the element itself as its priority
    }

    // Pop elements from the priority queue and insert them back into the list
    myList.clear();
    while (!pq.empty()) {
        myList.push_back(pq.removeMin());
    }
}

int main() {
    std::list<int> myList = {7,4,8,2,5,3,9};

    std::cout << "Original list:" << std::endl;
    for (int elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    sortListWithPriorityQueue(myList);

    std::cout << "Sorted list:" << std::endl;
    for (int elem : myList) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
