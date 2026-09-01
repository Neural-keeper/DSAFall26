#include <iostream> // to get terminal input and output access
#include <string> // to get access to stl string

/*
Arendil was just like any child of Waanor. He'd weave baskets of grass with his mother or climb 
the tallest trees in the forests around the village. Sometimes, he'd help his father forage, or 
help his grandmother care for their ancient family tree. Yet, now he woke up somewhere deep in
an unfamiliar forest. Worse yet, last he remembered, he was sound asleep in bed. 

We will (hopefully) follow Arendil on this journey back home and help him get there using 
Data Structures. (don't judge, I might lose this gimmick soon...)
*/

using namespace std; // I'd say just use it in your .cpp files, be a little wary in your .h files
// cout <- print to terminal -> std::cout -> cout; std::string stringa -> string stringa

// 0th, we will define the species in the world -> enumerators
enum Species {
    ELF,
    HUMAN,
    DWARF,
    UNKNOWN
}; // also have to end this with a semi colon

// First, we'll need to define Arendil, and every other character we might encounter
class Character {
// these are things we use to create objects, they have access specifiers
/*
public: anything in the code can access thsse
private: only this object can access, and "friend" classes can access it
protected: only this object and its successor (derived) can access things here
*/
private:
    string name;
    Species species;
    int health;
    int hungerPoints = 0;

public:
    //contructor
    Character(string n, Species s, int h) : name(n), species(s), health(h) {}
    //destructor - by default, it exists at the end of the code, but important to specify when
    // you are dealing with dynamic memory allocation

    string getName() const {
        return name;
    } //accessor

    void speak(const string& message) const {
        cout << name << " says: " << message << endl;
    }

    // letting our characters eat food
    void eatFood(int amount) {
        hungerPoints += amount;
        cout << name << " ate food and gained " << amount << " hunger points!" << endl;
        cout << "Total hunger: " << hungerPoints << endl;
    }

    int getHungerPoints() const {
        return hungerPoints;
    }

    int getHealth() const {
        return health;
    }
}; // end with a semicolon


/*
The first thing Arendil thinks to do is find food. He knows a lot about the food of the forests 
and is confident he can forage for them, Once he collects enough food to fill 30 hunger points,
he can recuperate enough energy to continue. 

The types of food available in the forest, along with the hunger points they fill, are:
Carrons         - 1 HP - C
Apponts         - 2 HP - A
Fruitberries    - 3 HP - F

As he forages, he finds the following in this order:
[C, A, F, F, A, A, C, A, F, C, A, F, C, C]
Size = 14

We will write a function to calculate how many items he needs to eat in this order to move on.
*/

// Write array traversal function here
int processForage(const char foodList[], int size, int targetHP) {
    int currentHP = 0;
    int itemsEath = 0;

    for (int i = 0; i < size; ++i) {
        char item = foodList[i];

        switch (item) {
            case 'C':
                currentHP += 1;
                break;
            case 'A':
                currentHP += 2;
                break;
            case 'F':
                currentHP += 3;
                break;
            default:
                cout << "Unknown food" << endl;
                break;
        }

        itemsEath++;

        if (currentHP >= targetHP) {
            cout << "Reached target after eating " << itemsEath << " food items!" << endl;
            break;
        } else {
            cout << "Ate " << item << ". Total HP: " << currentHP << endl;
        }
    }

    /* While loop demo
    int i = 0;
    while (i < n) {
        loopbodyfunctions;
    }
    
    Do-while loop
    do {
        thingtodo; // run at least once
    } while (false);
    */

    if (currentHP < targetHP) {
        return -1;
    }
    return itemsEath;
}


/*
Now that he's fully fed and ready to move on, he embarks on his journey. He stores everything he 
collected but didn't eat in a satchel. He wants freedom to check his satchel, add things to his 
satchel, and remove things from his satchel.
*/

// represent satchel as a class here 


/*
Finally, Arendil starts moving through the woods. A few miles in, he finds a large tree shell, 
seemingly burnt or struck by lightning. It starts raining, so he climbs inside for shelter, but 
the floor gives out underneath him. Now, he's fall through like Alice and ended up in what seems 
to be a tea-house x cafe (the perks of fiction). There are a bunch of different people here, all 
different species. Arendil wants to keep track of his connections as they appear. 
*/

// represent his new friends as structs in an array, making the array dynamic to grow or shrink


int main() {
    cout << "Arendil intro!" << endl;
    Character arendil("Arendil", ELF, 100);

    string dialogue = "Oh no! I'm so far away from home!";
    arendil.speak(dialogue);

    arendil.speak("Awh");

    cout << "He found food: " << endl;
    char foundFood[20] = {'C', 'A', 'F', 'F', 'A', 'A', 'C', 'A', 'F', 'C', 'A', 'F', 'C', 'C', 'A', 'C', 'C', 'F', 'C', 'C'};
    int eatenCount = processForage(foundFood, 20, 30);

    if (eatenCount == -1) {
        cout << "He didn't have enough food to proceed" << endl;
        return 0;
    }
    cout << "He had to eat " << eatenCount << " items before proceeding!" << endl;

    return 0;
}