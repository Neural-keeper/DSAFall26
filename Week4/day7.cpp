// Arendil is back again we didn't get here, but here's last class
/*
Arendil got the names of all the Teavern keep's friends and wants to write them down, along with the
amount of food he can get from each. He wants to keep them in the order he sees them (left to right, 
top to bottom) on the map. Adapt main to match this. 
The names and food values are given below:
Elarion - 12
Miriel - 8
Thaladir - 15
Thrainor - 5
Galaric - 20
Bramdur - 10
Aldorath - 14
Eldrin - 7
Rohanath - 18
*/

// #include <iostream>
// #include <string>
// #include "DLinkedList.h"

// using namespace std;

// struct FriendData {
//     string name;
//     int food;

//     bool operator<=(const FriendData& other) const { return food <= other.food; }
//     bool operator>=(const FriendData& other) const { return food >= other.food; }
//     bool operator<(const FriendData& other) const { return food < other.food; }
//     bool operator>(const FriendData& other) const { return food > other.food; }
// }

// int main() {
//     DLinkedList<string> foodList;
//     foodList.insertEnd("Elarion");
//     foodList.insertEnd("Miriel");
//     foodList.insertEnd("Thaladir");
//     foodList.insertEnd("Galaric");

//     foodList.display();

//     return 0;
// }

/*
side tangent - virtual

class Animal {
    //...

    virtual void speak() {
        cout << "I'm an animal!" << endl;
    }
}

class Dog : public Animal {
    //...

    void speak() override {
        cout << "bowwow" << endl;
    } // note - override is useful here because it's resilient to types or parameter changes
}

int main() {
    Animal* doggy = new Dog()
    doggy.speak()
}

*/

// Say he put it in a doubly linked list. Now, what if he realized he wrote them in the 
// reverse order and needed to reserve them in one fell swoop, all together?


// Ok, he changed his mind and wants to be able to go from the last one to the first one 
// really quickly. And now, he doesn't really care about the order he found them in, and wants
// to sort them as he adds them into a circularly linked list. How would we implement this?
#include <iostream>
#include <string>
#include "CLinkedList.h"

using namespace std;

struct FriendData {
    string name;
    int food;

    bool operator<=(const FriendData& other) const { return food <= other.food; }
    bool operator>=(const FriendData& other) const { return food >= other.food; }
    bool operator<(const FriendData& other) const { return food < other.food; }
    bool operator>(const FriendData& other) const { return food > other.food; }

    friend ostream& operator<<(ostream& os, const FriendData& f) {
        os << f.name << " (" << f.food << " food)";
        return os;
    }
};

int main() {
    CLinkedList<FriendData> arendilsList;

    // Arendil adds each friend as he sees them on the map
    arendilsList.sortedInsert({"Elarion", 12});
    arendilsList.sortedInsert({"Miriel", 8});
    arendilsList.sortedInsert({"Thaladir", 15});
    arendilsList.sortedInsert({"Thrainor", 5});
    arendilsList.sortedInsert({"Galaric", 20});
    arendilsList.sortedInsert({"Bramdur", 10});
    arendilsList.sortedInsert({"Aldorath", 14});
    arendilsList.sortedInsert({"Eldrin", 7});
    arendilsList.sortedInsert({"Rohanath", 18});

    std::cout << "--- Arendil's Sorted Circular Food Map ---\n";
    arendilsList.display();

    return 0;
}