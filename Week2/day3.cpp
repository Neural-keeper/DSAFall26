/*
Continuing the last lecture, but rewriting things. Also, I can live code everything, or leave 
small snippets like today that we code live. Second option is faster and lets me demonstrate more.
We'll likely have a mix, where we'll implement a data structure once live, then just have it already
pre-set for future days. 
*/

#include <iostream>
#include <string> 
#include <vector> // dynamic array add - push_back, remove - erase (to remove specifically)

using namespace std; 

enum Species {
    ELF,
    HUMAN,
    DWARF,
    UNKNOWN
}; 

/*
public: anything in the code can access thsse
private: only this object can access, and "friend" classes can access it
protected: only this object and its successor (child) can access things here
*/

// base character class (Arendil will be a derived "MainCharacter" of this class)
class Character {
protected:
    string name; 
    Species species;
public:
    Character(string n, Species s) : name(n), species(s) {}
    
    virtual ~Character() {} // derived destructor goes first, then base class destructor

    string getName() const {
        return name;
    }

    void speak(const string& message) const {
        cout << name << " says: " << message << endl;
    }
};

// Satchel class for character's satchel
class Satchel {
private:
    vector<char> items; //vector of type character called items
public:
    void addItem(char item) {
        items.push_back(item);
        cout << "Added " << item << " to satchel." << endl;
    }

    // void removeItem(char item) {
    //     for (auto it = items.begin(); it != items.end(); ++it) {
    //         if (*it == item) {
    //             item.erase(it);
    //             cout << "Removed " << item << " from satchel." << endl;
    //             return;
    //         }
    //     }
    //     cout << "The item " << item << " was not found in satchel." << endl;
    // }

    // vector .empty() method
    void displaySatchel() const {
        cout << "---SATCHEL---" << endl;
        if (items.empty()) {
            cout << "[EMPTY]" << endl;
            return;
        }
        for (char item : items) {
            cout << "[" << item << "] ";
        }
        cout << "End of satchel." << endl;
        cout << "Total items: " << items.size() << endl;
    }

};

//friends
struct Friend {
    string name;
    Species species;
    string locationMet;
};

// derived main character class for when we care about their health and want them to eat food
class MainCharacter : public Character {
private:
    int health;
    int hungerPoints = 0; // all main characters start off hungry
    Satchel satchel;      // MainCharacter's satchel
    vector<Friend> connections; // dynamic array/collection of friend structs

public:
    MainCharacter(string n, Species s, int h) : Character(n, s), health(h) {} 

    Satchel& getSatchel() { return satchel; }

    void addFriend(const string& friendName, Species friendSpecies, const string& location) {
        connections.push_back({friendName, friendSpecies, location});
        cout << name << " added " << friendName << " as a connection!" << endl;
    }

    void displayFriends() const {
        cout << "---" << name << "'s freinds---" << endl;
        if (connections.empty()) {
            cout << name << " has no friends (yet)." << endl;
            return;
        }
        for (const auto& f : connections) {
            cout << "- " << f.name << ", met at " << f.locationMet << endl;
        }
        cout << "---" << endl;
    }

    void eatFood(int amount) {
        hungerPoints += amount;
        cout << name << " ate food and gained " << amount << " hunger points!" << endl;
        cout << "Total hunger: " << hungerPoints << endl;
    }

    void processForage(const char foodList[], int size, int targetHP) {
        int itemsEath = 0;

        for (int i = 0; i < size; ++i) {
            char item = foodList[i];

            switch (item) {
                case 'C':
                    hungerPoints += 1;
                    break;
                case 'A':
                    hungerPoints += 2;
                    break;
                case 'F':
                    hungerPoints += 3;
                    break;
                default:
                    cout << "Unknown food" << endl;
                    break;
            }

            itemsEath++;

            if (hungerPoints >= targetHP) {
                cout << "Reached target after eating " << itemsEath << " food items!" << endl;
                break;
            } else {
                cout << name << " ate " << item << ". Total HP: " << hungerPoints << endl;
            }
        }

        if (hungerPoints < targetHP) {
            cout << "There was not enough food. The End..." << endl;
        } else {
            cout << name << " ate " << itemsEath << " items of food and reached the target HP!";
        }
    }

    int getHungerPoints() const { return hungerPoints; }
    int getHealth() const { return health; }
}; // short intro to inheritance in classes


/*
The first thing Arendil thinks to do is find food. He knows a lot about the food of the forests 
and is confident he can forage for them, Once he collects enough food to fill 30 hunger points,
he can recuperate enough energy to continue. 

The types of food available in the forest, along with the hunger points they fill, are:
Carrons         - 1 HP - C
Apponts         - 2 HP - A
Fruitberries    - 3 HP - F

As he forages, he finds the following in this order:
['C', 'A', 'F', 'F', 'A', 'A', 'C', 'A', 'F', 'C', 'A', 'F', 'C', 'C', 'A', 'C', 'C', 'F', 'C', 'C']
Size = 20

We will write a function to calculate how many items he needs to eat in this order to move on, and 
make it part of the MainCharacter class.
*/

// DONE LAST SESSION, moved to line 60//update with a couple changes

/*
Now that he's fully fed and ready to move on, he embarks on his journey. He stores everything he 
collected but didn't eat in a satchel. He wants freedom to check his satchel, add things to his 
satchel, and remove things from his satchel.
*/

// represented satchel as a class on line 47


/*
Finally, Arendil starts moving through the woods. A few miles in, he finds a large tree shell, 
seemingly burnt or struck by lightning. It starts raining, so he climbs inside for shelter, but 
the floor gives out underneath him. Now, he's fall through like Alice and ended up in what seems 
to be a tea-house x cafe (the perks of fiction). There are a bunch of different people here, all 
different species. Arendil wants to keep track of his connections as they appear. 
*/

// represent his new friends as structs in an array, but use something dynamic

/*
The teavern keep pulls Arendil aside and asks him where he's from. News of an elf from Waanor 
rattles the entire tea-house. They tell him of a dark lord sending the creatures of the world 
into hiding, and of a prophecy that a child of Waanor will find himself in a quest to quell the 
evil lord. Arendil wonders why he'd never heard of such a prophecy before, but then again, he'd 
never heard of the dark lord. Waanor liked to keep to itself. He says he needs to get home, and 
the teavern keep instead proposes a quest in exchange for showing him home.

We need a quest log to keep track of all the quests Arendil gets. I implemented the code here 
already for the sake of time, so that we can move on on Thursday and cover the actual semantics.
*/

// Dynamic Memory Allocation
struct Quest {
    string title;
    string objective;
    string reward;

    Quest(string t, string obj, string rew) : title(t), objective(obj), reward(rew) {
        cout << "Quest Accepted: '" << title << "'" << endl; //allocated to heap
    }

    ~Quest() {
        cout << "Quest Removed from Memory: '" << title << "'" << endl; //removed from heap
    }
};

class QuestTracker {
private:
    Quest* currentQuest = nullptr; // Raw pointer to dynamically allocated Quest

public:
    ~QuestTracker() {
        // PREVENT MEMORY LEAK: Clean up active quest if object is destroyed
        if (currentQuest != nullptr) {
            delete currentQuest;
            currentQuest = nullptr;
        }
    }

    // dynamic allocation - 'new'
    void acceptQuest(const string& title, const string& obj, string rew) {
        if (currentQuest != nullptr) {
            cout << "\n[WARNING] Already on a quest! Complete or abandon it first." << endl;
            return; // cannot be on multiple quests at once ofc
        }
        currentQuest = new Quest(title, obj, rew);
    }

    // deallocation - 'delete'
    void completeQuest() {
        if (currentQuest == nullptr) {
            cout << "No active quest to complete!" << endl;
            return;
        }

        cout << "\nCompleted Quest: " << currentQuest->title << "!" << endl;
        cout << "Gained " << currentQuest->reward << endl;

        delete currentQuest; // useon delete[] collection of dynamically allocated objects

        // CRITICAL STEP: Prevent Dangling Pointer!
        currentQuest = nullptr; 
    }

    void displayCurrentQuest() const {
        cout << "\n--- Current Active Quest ---" << endl;
        if (currentQuest != nullptr) {
            // (->) to access pointer members
            cout << "Title: " << currentQuest->title << endl;
            cout << "Objective: " << currentQuest->objective << endl;
            cout << "Reward: " << currentQuest->reward << endl;
        } else {
            cout << "No active quest right now." << endl;
        }
        cout << "----------------------------" << endl;
    }
};


int main() {
    cout << "Arendil - A DSA Game Storyline" << endl;

    Character narrator("Narrator", UNKNOWN);

    string dialogues[] = {
        "Arendil was just like any child of Waanor.",
        "He'd weave baskets of grass with his mother or climb the tallest trees in the forests around the village.",
        "Sometimes, he'd help his father forage, or help his grandmother care for their ancient family sapling.",
        "Yet, now he woke up somewhere deep in an unfamiliar forest.",
        "Worse yet, last he remembered, he was sound asleep in bed."
    };

    for (const string& line : dialogues) {
        narrator.speak(line);
    } // a type of for loop, for i in x. using & so we pass by reference and don't copy the long string

    MainCharacter arendil("Arendil", ELF, 100);
    string dialogue = "Oh no! I'm so far away from home!";
    arendil.speak(dialogue);

    arendil.speak("I should forage...there, I found food!");
    char foundFood[20] = {'C', 'A', 'F', 'F', 'A', 'A', 'C', 'A', 'F', 'C', 'A', 'F', 'C', 'C', 'A', 'C', 'C', 'F', 'C', 'C'};
    arendil.processForage(foundFood, 20, 30);

    arendil.getSatchel().displaySatchel();
    arendil.getSatchel().addItem('C');
    arendil.getSatchel().displaySatchel();

    arendil.speak("Wow, this teavern has so many people!");
    arendil.displayFriends();
    arendil.addFriend("Gimm", DWARF, "Teavern");
    arendil.addFriend("Fòrin", ELF, "Teavern");
    arendil.displayFriends();

    QuestTracker tracker;
    tracker.acceptQuest("Find Golden Carp", "Fish for a Golden Carp in the nearby pond", "Map");
    tracker.displayCurrentQuest();
    tracker.completeQuest(); // free memory
    tracker.displayCurrentQuest(); // nullptr

    return 0;
}