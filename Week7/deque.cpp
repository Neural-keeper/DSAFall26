// we'll use the STL deque container, to make things simpler
// exploring implementation of deque operations and their usefulness in interview style questions
/*
Arendil is back. He's missed us almost as much as we missed him. He's close to reaching home. 

However, like usual, there is another task he must complete before he can continue, and do this through the use of a deque. His skill tree, and training, allowed him to unlock elemental powers, and like the Avatar, he can use all of them. As he proceeds along his journey, he comes upon a troll guarding a bridge, the only one across the river, with a wall of stone. 

"Solve my puzzle and you may pass. Fail, and you shall surrender your heart to the forest," says the troll. 

The puzzle in question is a series of stone blocks with numbers on them, etched inside one of the four elemental runes. (We can consider this an array of integers). There is one stone buttons, which Arendil plays around with, and realizes they are a sliding window mechanism that allows him to view and manipulate a subset of 3 (k) of the blocks at a time. 

"You've figured it out, I see!" says the troll. "Destroy the maximum block each time, but you can only see the subset of 3 at a time. Do it quickly!"

The troll was named Maximus. 

LeetCode #239: Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window. (this means, return the max in each sliding window)
*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*
Deque methods:
    push_back(value) - adds an element to the back of the deque
    pop_back() - removes the element from the back of the deque
    push_front(value) - adds an element to the front of the deque
    pop_front() - removes the element from the front of the deque
    front() - accesses the element at the front of the deque
    back() - accesses the element at the back of the deque
    empty() - checks if the deque is empty
*/

/*
Logic:
1. empty deque to hold our windows (indices)
2. iterate through array, maintaining the deque to be decreasing in value
    remove small from the back
3. remove indices outside window (from front)
4. remove indices of value less than current element from back
5. add current to the back
6. once first window is formed, output to result

the front will always have the "local" maximum
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // will store indices for elements inside the window
    // iterature through array
    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front(); // remove indices outside window
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back(); // removing values less than current value from the back of the deque
        dq.push_back(i); // add current index to the deque
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}


int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7,8,34,10,19,-58};
    // expected value: 3, 3, 5, 5, 6, 7
    int k = 7;
    // expected output: 6 7 8 34 34 34 34
    vector<int> result = maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}