// hashing but problem solving

/*
Arendil managed to defeat the shadow elves, which led to the child he heard appear.

"You're the chosen one!" the child exclaimed.

Arendil sighed, "I'm just trying to get home."

The kid pondered for a moment, then said, "You should come with me! We can go to Vrair, the capital city 
of the wood elves. If anyone can get you home, it's our council!"

Arendil, despite having his doubts, followed. What else could he do against a forest changing the very 
path before him? Maybe if he helped them, he'd make it out and home. 

The city was almost exactly like home, but a lot bigger and louder. The council greeted him directly, 
a group of 4, women and men alike. And, as per course, very little conversation later, he was give a 
new task.
*/

/* 
LeetCode 146: LRU Cache spinoff
Arendil is given a basket with just enough room for 3 items. Allegedly, the forest is being controlled 
by the Dark Lord, so the elves are unable to pick up the three objects they need to build a magic staff. 
The Lord's also cursed the items so that they all appear the same. Only the chosen one can tell them 
apart, but only by using the item. They're internally drawn to the real item. 

So, if Arendil goes in a straight line, he can pick up an array of items in the given order. Every time 
he has three items, he will pick one to use using his intuition. That one will be a potential real item,
and he can drop the one he doesn't like much to pick up the next item. 

At the very end, if he continues this, he will have the three items he needs to build the staff.

We need to write a program that will take in an array of items, use the given "intuition" function 
to pick the real item at each stage when needed, and return the final three items in the basket.
*/

#include <iostream>
#include <vector>

using namespace std;

class ArendilsStaffBuilder {
private:
    // PROVIDED INTUITION FUNCTION: 
    // Takes a 4-digit item code and performs a mathematical ritual to 
    // calculate its "resonance score" (e.g., sum of digits multiplied by middle digits).
    int getIntuitionScore(int itemCode) {
        if (itemCode < 1000 || itemCode > 9999) return 0; // Ensure it's a 4-digit code

        int thousands = itemCode / 1000;
        int hundreds = (itemCode / 100) % 10;
        int tens = (itemCode / 10) % 10;
        int ones = itemCode % 10;

        // Magical math formula for Arendil's intuition
        return (thousands + ones) * (hundreds + tens);
    }

public:
    ArendilsStaffBuilder(int capacity) {
        // TODO
    }
    
    void processItem(int itemCode) {
        // TODO
    }
    
    vector<int> getFinalBasket() {
        // TODO
        return {};
    }
};

int main() {
    ArendilsStaffBuilder solver(3);
    
    // Forest path with 4-digit item codes
    vector<int> forestPath = {1024, 5089, 3142, 1024, 7777, 5089, 9999};
    
    for (int item : forestPath) {
        solver.processItem(item);
    }
    
    vector<int> finalItems = solver.getFinalBasket();
    
    cout << "Final 3 items in Arendil's basket: ";
    for (int item : finalItems) {
        cout << item << " ";
    }
    cout << "\n";
    // Expected output: Final 3 items in Arendil's basket: 9999 5089 7777
    
    return 0;
}