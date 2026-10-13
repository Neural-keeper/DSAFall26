// using a priority queue
#include <iostream>
#include <vector>
#include <queue> // we have STL priority queue
#include <functional>

/*
STL Priority Queues

Max heap - default - maximum is at "top," easiest to reach
    priority_queue<int> maxPq;
Min heap - minimum is at "top." easiest to reach
    priority_queue<int, vector<int>, greater<int>> minPq;
*/

/*
    LeetCode Problem #215: Kth Largest Element in an Array (Medium)
    Problem Statement: Given an integer array nums and an integer k, return the k-th 
    largest element in the array. Note that it is the k-th largest element in the 
    sorted order, not the k-th distinct element. 
*/

using namespace std;

class FindKth {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > (size_t)k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main() {
    FindKth solver;
    vector<int> nums = {3, 2, 1, 5, 6, 4, 23, 56, 67, 81, 99, 201, 101, 45, 10, 19, 14, 17, 21, 25, 26};
    int k = 10;

    cout << "The " << k << "-th largest element is: " << solver.findKthLargest(nums, k) << endl;
    // expected: 5

    return 0;
}