#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

/*
Heap Property:
(Usually) a binary tree structure WHERE:
Property: min-heap - The parent of any node in the heap is smaller than said node
the children of any node in the heap are larger than said node
max-heap reverses that - maximum at the top
*/

using namespace std;

// we will be using an array representation of a complete binary tree to implement a min heap
/*
Array Binary Trees:
[ - 0 1 3 4 2 6 7 8 9 5]
tree starts at index 1 (textbook-style)
for any node at index i
left child's index:   2i
right child's index:  2i + 1
node's parent:        i / 2   (floor, so only integer part)

         0 
       /   \
      1     3
     / \   / \
    4   2 6   7
   / \  /
  8   9 5

last node - rightmost node - the last one in the array

height of a complete binary tree log(n) (base 2)

Our worst case insertion - inserting a new minimum - log(n) steps

Time complexity - O(log n)
*/

// the element stored as a "node" in the heap - priority-value pair
struct element {
    int priority;
    string value;

    element(int p, string v) : priority(p), value(v) {}
};

class min_heap {
private:
    vector<element> heap; // array version

    int parent(int i) {
        return i / 2; // this is integer division, returns just the integer part
    }

    int left_child(int i) {
        return 2*i;
    }

    int right_child(int i) {
        return (2*i) + 1;
    }

    // upheap - bubble up - to maintain our heap property - iterative - after insertion
    void upheap(int i) {
        while (i > 1 && heap[i].priority < heap[parent(i)].priority) {
            swap(heap[i], heap[parent(i)]);

            printHeap();

            i = parent(i);
        }
    }

    // downheap - bubble down - after removing root or min
    void downheap(int i) {
        int size = heap.size() - 1; // last valid index

        // keep looping left as long as there is a left child to go to
        while (left_child(i) <= size) {
            int smallest = i; // assume current node hold smallest priority
            int left = left_child(i);
            int right = right_child(i);
            
            if (left <= size && heap[left].priority < heap[smallest].priority) {
                smallest = left;
            }

            if (right <= size && heap[right].priority < heap[smallest].priority) {
                smallest = right;
            }

            if (smallest == i) {
                break; // current is smallest even where it is
            }

            swap(heap[i], heap[smallest]); // swap the two
            
            i = smallest;

            printHeap();
        }
    }

public:
    min_heap() {
        heap.push_back(element(0, "DUMMY"));
    }

    ~min_heap() {}

    bool empty() {
        return heap.size() <= 1;
    }

    size_t size() {
        return heap.size() - 1;
    }

    void push(element e) {
        heap.push_back(e);
        upheap(heap.size() - 1); // give upheap the index of the last element
    } // main method for adding to our heap

    // pop the minimum element
    string pop() {
        if (empty()) {
            throw runtime_error("Min-heap is empty! Nothing to pop...");
        }

        string minValue = heap[1].value;

        heap[1] = heap.back(); // replace top of heap with the last element in the heap
        heap.pop_back(); // get rid of that element in the back that we put in the top

        if (!empty()) {
            downheap(1);
        }

        return minValue;
    } 

    // top - look at the minimum
    string top() {
        if (empty()) {
            throw runtime_error("Min-heap is empty! Nothing to pop...");
        }
        return heap[1].value;
    }

    void printHeap() {
        for(int i = 0; i < heap.size(); i++) {
            cout << heap[i].value << " : " << heap[i].priority << " | ";
        }
        cout << endl;
    }
};

int main() {
    min_heap mh;
    mh.push(element(100, "apple"));
    mh.push(element(1000, "frozen berries"));
    mh.push(element(50, "banana"));

    mh.printHeap();
    
    cout << "Min-Heap Top Element: " << mh.top() << endl; // Expected: banana (priority 50)
    
    while (!mh.empty()) {
        cout << "Popped: " << mh.pop() << endl; // Expected order: banana, apple, frozen berries
    }

    mh.push(element(1, "1"));
    mh.push(element(2, "2"));
    mh.push(element(3, "3"));
    mh.push(element(4, "4"));
    mh.push(element(5, "5"));
    mh.push(element(6, "6"));
    mh.push(element(7, "7"));
    mh.push(element(8, "8"));
    mh.push(element(9, "9"));
    mh.pop();


    return 0;
}