/*
Merge K Sorted Arrays using a Min-Heap
------------------------------------------------------
You are given a vector of k sorted vectors, where each vector is sorted in ascending order.
Merge all the vectors into one single sorted vector and return it efficiently using a min-heap.
*/

/*
1 - [6, 8, 9, 15]
2 - [1, 7, 10]
3 - [2, 3, 4, 5]

*/


#include <iostream>
#include <vector>
#include <queue> // for priority queue, which is implemented using a max-heap

using namespace std;

// Structure to track the element's value, which array it came from, 
// and its current index within that array so we can fetch the next one.
struct ArrayElement {
    int val;
    int array_index; // which array it belongs to
    int element_index; // which element in that array

    // Overload the greater-than operator so the priority_queue acts as a min-heap
    bool operator>(const ArrayElement& other) const {
        return val > other.val;
    }
};

class Solution {
public:
    vector<int> mergeKArrays(const vector<vector<int>>& arrays) {
        vector<int> result;

        priority_queue<ArrayElement, vector<ArrayElement>, greater<ArrayElement>> minHeap;

        // initial min heap - first value of each non-empty array
        for (int i = 0; i < arrays.size(); ++i) {
            if (!arrays[i].empty()) {
                minHeap.push({arrays[i][0], i, 0});
            }
        }

        // extract minimum from each and then push the next element from same source
        while (!minHeap.empty()) {
            ArrayElement current = minHeap.top();
            minHeap.pop();

            result.push_back(current.val);

            int next_element_ids = current.element_index + 1;

            if (next_element_ids < arrays[current.array_index].size()) {
                minHeap.push(
                    {
                        arrays[current.array_index][next_element_ids],
                        current.array_index,
                        next_element_ids
                    }
                );
            }
        }
        return result;
    }
};

int main() {
    Solution solver;

    // Test case: 3 sorted arrays
    vector<vector<int>> input_arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    cout << "Testing Merge K Sorted Arrays..." << endl;

    vector<int> merged = solver.mergeKArrays(input_arrays);

    // Print the final result
    cout << "Your Result: ";
    for (int val : merged) {
        cout << val << " ";
    }
    cout << endl; 
    cout << "(Expected: 1 2 3 4 5 6 7 8 9)" << endl;

    return 0;
}

/*
After Arendil got past the bridge, the woods started acting strange. He was following the cardinal directions 
using the Sun, but his path was deviating from what the map showed. Still, he followed, because the trees 
were too dense off the path for him to be able to stray. 

He heard a child laugh. Odd, he thought. 

Then, he walked into a clearing and found himself face to face with a horde of wood elves he couldn't feel 
the life force of. Clearly, they were shadows sent by the Dark Lord. 

His skill tree unlocked two new abilities. One could tell him how much energy he needed to defeat each of them. 
Another allowed him to cast those exact energies in rapid succession, but he had to do it in the right order.

Looking through the entire crowd, putting them into an array, then sorting it, would take too long. 
He could scan once though, but after that, he'd have to start attacking before they could attack him. 

So, we need to put all of them into a min heap, then keep removing the minimum energy elf from the heap 
as he attacks. We print out the sorted order (so the order he attacks in).

When inserting, we'll give each elf an id number, and a priority number. We print the ids in the order of their priority (ascending).
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Structure representing a shadow elf threat in the clearing
struct ShadowElf {
    int id;           // Unique identifier for the shadow elf
    int energy_cost;  // Priority value (lower energy cost means higher attack priority)

    // Overload the greater-than operator so the priority_queue acts as a min-heap based on energy cost
    bool operator>(const ShadowElf& other) const {
        return energy_cost > other.energy_cost;
    }
};

class ShadowEncounter {
public:
    void processClearingEncounter(const vector<ShadowElf>& hough_horde) {
        // TODO
    }
};

int main() {
    ShadowEncounter battle;

    // The horde of shadow elves discovered in the clearing (ID, Energy Cost)
    vector<ShadowElf> horde = {
        {101, 45},
        {102, 12},
        {103, 78},
        {104, 5},
        {105, 30}
    };

    cout << "--- ARENDIL'S CLEARING SKIRMISH ---" << endl;
    battle.processClearingEncounter(horde);
    cout << "\nWith the shadow horde dispersed, Arendil catches his breath and presses onward." << endl;

    return 0;
}
*/
