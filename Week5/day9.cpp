// testing our queues
#include <iostream>
#include "QueueArr.h"
#include "QueueLL.h"
// #include <queue> // uncomment this when looking at the bottomost question
// #include <vector> // this too

using namespace std;

int main() {
    QueueArray<int> intQueue(5);
    cout << "Int Queue (Array Implementation)" << endl;
    cout << "Is queue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << endl;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    cout << "Front of the queue: " << intQueue.front() << endl;
    intQueue.dequeue();
    cout << "Front of the queue after dequeue: " << intQueue.front() << endl;

    try {
        while (!intQueue.isEmpty()) {
            intQueue.dequeue();
        }
        intQueue.dequeue(); // This should throw an exception
    } catch (const std::underflow_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    QueueLinkedList<int> llQueue;
    cout << "\nInt Queue (Linked List Implementation)" << endl;
    cout << "Is queue empty? " << (llQueue.isEmpty() ? "Yes" : "No") << endl;

    llQueue.enqueue(100);
    llQueue.enqueue(200);
    llQueue.enqueue(300);
    cout << "Front of the queue: " << llQueue.front() << endl;
    llQueue.dequeue();
    cout << "Front of the queue after dequeue: " << llQueue.front() << endl;

    try {
        while (!llQueue.isEmpty()) {
            llQueue.dequeue();
        }
        llQueue.dequeue(); // This should throw an exception
    } catch (const std::underflow_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}

// Quick side tangent - the STL Queue
/*
available methods:
- push()
- pop() - removes the front of the queue, does not return the value
- front()
- back() - see the back of the queue 
- empty()
- size()
*/

// If time permits
/*
Arendil made it out of the dungeon by calculating the greatest reactangular area in the histogram of pillars in the chamber. He can now go forward in his journey home. However, now he's been stopped by Thaladir IV, who wants to use Arendil against the monster left behind by the shadows. 

Arendil is taken into a great cavern, where all of the city's magic minerals, which they were once famed for in the trading business, are set into the stone walls to act as a barrier to contain the beast. It looks to him through shadows, hissing through his blood red fangs. It clearly wasn't an intelligent creature, yet strong it was.

Arendil knew, and suspected the King knew as well, that this monster wasn't someone he could defeat alone. He wasn't alone, though. Thaladir introduced him to a group of elves, all from different towns and cities, weilding different powers. Many of them had solved the King's puzzles in a variety of ways. One slithered out by breaking the ground beneath the door. Another melted the door, somehow, using his fire abilities. The last had commanded the plants to pull it out with their roots. 

So, he had a team:
1. Arendil, who was a master of logic and reasoning, and had a keen eye for patterns.
2. Aelith, who was a master of fire, and could melt through any obstacle
3. Drisk, who was a master of earth, and could manipulate the ground to his will
4. Luthien, who was a master of nature, and could command the plants to

Thaladir refused to fight, but said he'd support them with armor. He also explained the powers of the beast:
1. It was immune to fire, and would not be affected by Aelith's powers, but could be distracted.
2. It was vulnerable to earth and nature, and could be defeated by Drisk and Luthien's powers, but they would need to be in the right position to use their powers effectively.

From a game perspective, say Arendil does 3 damage, Aelith skips it's attack, but still takes a move, Drisk does 4 damage, and Luthien does 2 damage. The monster has 100 health to begin with, and the players have 10. If not stopped by Aelith, the monster attacks after every move the players make, and does 1 damage to each of the players. Given a stream of moves made by the players, we need to calculate the average damage done to the monster over the last 5 moves, and output that as a stream.
*/

/*
Essentially: Given a continuous stream of player actions where each action deals a specific amount of damage (Arendil: 3, Drisk: 4, Luthien: 2, Aelith: 0), design a system that outputs the moving average of damage dealt over the last 5 actions.
*/
// code
/*
void calculateMovingAverage(const vector<int>& damageStream) {
    queue<int> lastFiveDamages;
    int sum = 0;

    for (int damage : damageStream) {
        lastFiveDamages.push(damage);
        sum += damage;

        if (lastFiveDamages.size() > 5) {
            sum -= lastFiveDamages.front();
            lastFiveDamages.pop();
        }

        double average = static_cast<double>(sum) / lastFiveDamages.size();
        cout << "Current Moving Average: " << average << endl;
    }
}

int main() {
    vector<int> damageStream = {3, 4, 2, 0, 3, 4, 2, 0, 3};
    calculateMovingAverage(damageStream);
    damageStream.push_back(4);
    calculateMovingAverage(damageStream);
    damageStream.push_back(2);
    calculateMovingAverage(damageStream);
    return 0;
}

*/