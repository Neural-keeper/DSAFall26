// Implementation vs. data structure - small discussion
/*
Stack - abstract, defined by LIFO rules
*/

/*
O(1) access 
O(k) = O(1) if k is constant
*/

// Linked List Implementation
// we use a linked list, but force only additions and removals from one end
// the tail end would be O(n) to access, add, and remove. 
// the head will be the top of our stack
// #include <iostream>
// #include "StackLL.h"

// using namespace std;

// int main() {
//     StackLinkedList<int> intStack;

//     cout << "Int Stack" << endl;
//     cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;

//     intStack.push(45);
//     intStack.push(12);
//     intStack.push(20);
//     cout << "The top is currently: " << intStack.top() << endl;
//     intStack.pop();
//     cout << "The top is currently: " << intStack.top() << endl;
//     intStack.pop();
//     intStack.pop();

//     try {
//         intStack.top();
//     } catch (const underflow_error& e) {
//         cout << "Caught exception: " << e.what() << endl;
//     }

//     try {
//         intStack.pop();
//     } catch (const underflow_error& e) {
//         cout << "Caught exception: " << e.what() << endl;
//     }

//     return 0;
// }

// Vector Implementation
// the tail end is used as the top - keeps it O(1)
// if you use first element as top, every addition is O(n) because the whole vector has to be shifted one
// #include <iostream>
// #include "StackV.h"

// using namespace std;

// int main() {
//     StackVector<int> intStack;

//     cout << "Int Stack" << endl;
//     cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;

//     intStack.push(45);
//     intStack.push(12);
//     intStack.push(20);
//     cout << "The top is currently: " << intStack.top() << endl;
//     intStack.pop();
//     cout << "The top is currently: " << intStack.top() << endl;
//     intStack.pop();
//     intStack.pop();

//     try {
//         intStack.top();
//     } catch (const underflow_error& e) {
//         cout << "Caught exception: " << e.what() << endl;
//     }

//     try {
//         intStack.pop();
//     } catch (const underflow_error& e) {
//         cout << "Caught exception: " << e.what() << endl;
//     }

//     return 0;
// }















// Interview style

/*
Arendil finally set off from the Teavern in the forest, on his journey home. The first city he stops at is Kahlbohr. Once a busy city and the center of a variety of interspecial trade, now reduced to a fortress. Arendil, desperate to get home, approaches the closed gates anyways and knocks, which gets him captured and thrown into a dungeon. Unbeknownst to him, the dark lord had months ago sent his shadows, shaped in the image of elves, to Kahlbohr and murdered their king before being subdued. Young prince, now King, Thaladir IV, used a treasure not even the dark lord knew about and banished his shadows. Mourning and distrustful, the young King closed off the city gates and imprisoned any elves that dared approach.



However, there was a monster left behind by the shadows that was wreaking havoc within the kingdom, and only an elf of the brightest mind could subdue it. So, he gave his prisoners a way out, if they had the cleverness enough to, as a cipher in the lock. Arendil solves it quickly (it's a caesar cipher, the code is his cell number, he figures it out quickly enough) and finds himself in a large room.

On the other side of the room are a series of pillars, all pressed against the wall and an impressively large pane of glass. A little pedestal has space for him to pick a number, but he has to do so quickly. He realizes he needs to find the largest rectangular area of pillars, since they look like a histogram. However, the clock is ticking really quickly.
*/

/*
1. stack to track indexes of the pillars
2. maxArea = 0, loop index i = 0
3. while i < n:
      current height of pillar we're looking
      if indexstack empty or top of indexstack value <= current pillar height:
        push i to stack
        increase i
      else:
        pop from top (oldHigh)
        calculate the width = i if stack empty, else i - currentTop - 1
        calculate area = pillars[oldHigh] * width
        update the maxArea if our area is bigger
4. return maxarea

*/
#include <iostream>
#include <vector>
#include <algorithm> // for max()
#include "StackLL.h"

using namespace std;

int solveHistogramPedestal(const vector<int>& pillars) {
    StackLinkedList<int> indexStack;
    int n = pillars.size();
    int maxArea = 0;
    int i = 0;

    while (i <= n) {
        int currentHeight = (i == n) ? 0 : pillars[i];

        if (indexStack.isEmpty() || pillars[indexStack.top()] <= currentHeight) {
            indexStack.push(i);
            i++;
        } else {
            int oldTop = indexStack.pop();
            int width = indexStack.isEmpty() ? i : (i - indexStack.top() - 1);
            int area = pillars[oldTop] * width;
            maxArea = max(area, maxArea);
        }
    }

    return maxArea;
}

int main() {
    // The histogram heights of the pillars in the chamber
    vector<int> pillars = {2, 1, 5, 6, 2, 3};

    cout << "The countdown ticks loudly. Arendil initializes his StackLinkedList...\n";
    
    int maximalArea = solveHistogramPedestal(pillars);

    cout << "Calculated Maximum Rectangular Area: " << maximalArea << "\n";

    if (maximalArea == 10) {
        cout << "Arendil slams '10' into the glowing pedestal just as the clock hits zero!\n";
        cout << "The countdown stops. With a heavy hiss, the secret door slides open, granting him passage deeper into Kahlbohr.\n";
    } else {
        cout << "Incorrect calculation! The walls begin to close in...\n";
    }

    return 0;
}