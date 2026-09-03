#include <iostream>
#include <string>
#include <stdexcept> //access to standard exceptions - runtime_error

using namespace std;
/*
Day 4 - A little different

Instead of just livecoding a big project like last time, this session, we're going to build 
things together. 

0. Doubts

1. Back to the basics

2. Question 1 - On arguments

3. Question 2 - On structs

4. Question 3 - On loops and functions

5. Back to doubts - ask me anything
*/

/*
// while vs do - while
// case where do-while is better
using namespace std;

int main() {
    int input;

    do {
        cout << "Welcome to Arendil's adventure!" << endl;
        cout << "Press 1 to eat food" << endl;
        cout << "Press 2 to throw pebbles" << endl;
        cout << "Press 3 to exit menu" << endl;
        cout << "Input: ";
        cin >> input;

        switch (input) {
            case 1: 
                cout << "Arendil ate food!" << endl;
                break;
            case 2:
                cout << "Arendil threw pebbles" << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid. Try again!" << endl;
                break; 
        }
    } while (input != 3);

    return 0;
}
*/

// arguments 
//    pass by value - the function gets a copy of that argument
//    pass by references - & - the function gets the address to the argument's source

// void updateHP(int& currentHP, int damage = 90) {
//     currentHP -= damage;
// }

// int main() {
//     int characterHP = 789;

//     cout << "Initial HP: " << characterHP << endl;

//     updateHP(characterHP);

//     cout << "Updated HP: " << characterHP << endl;

//     return 0;
// }

// overload functions 
//    multiple functions with the same name that do different things
/*
say we wanted to multiply two numbers - return type, arguments types 
*/

// int multiply(int a, int b) {
//     return a * b;
// }

// double multiply(double a, double b) {
//     return a * b;
// }

// int main() {
//     int a1 = 89;
//     int a2 = 21;

//     double b1 = 87.4;
//     double b2 = 31.9;

//     cout << multiply(a1, a2) << endl;
//     cout << multiply(b1, b2) << endl;

//     return 0;
// }

// keywords (const) - come back to this later
// 

/*
QUESTION 3

Write me a function (not necessarily in C++, just your plan or pseudo code) that can find the 
area under a function given by f(x) = [3, 5, 7, 9, 11]? Assume that the value of f(x) for 
any index i sustains over the two boundary values of x (f(x) = 3 from 0 <= x < 1, f(x) = 5 from 
1 <= x < 2, ...). 
*/
// int areaUnder(const int input[], int domain) {
//     int area = 0;
//     for (int i = 0; i < domain; i++) {
//         area += input[i];
//     }
//     return area;
// }

// int main() {
//     int arr[] = {3, 5, 7, 9, 11};

//     cout << "Area under f(x) is: " << areaUnder(arr, 5) << endl;

//     return 0;
// }

// OBJECT ORIENTED DESIGN
/*
It has 4 pillars:

1. Encapsulation: put things (data and function) together into one item or object

2. Abstraction: hide complexities from the rest of the code - we don't need to know
                exactly how something works if we can just use it
    push_back -> adds an element to the end of your vector

3. Polymorphism: many forms, same thing works differently depending on the form, 
                function overloading

4. Inheritance: things can inherit or copy things from other objects - derived classes inherit from
                base classes
*/

class Character {
private:
    string name;
    int health;
    int hungerPoints = 30;

public:
    //contructor
    Character(string n, int h) : name(n), health(h) {}
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

    void yeet(int weight) {
        if (hungerPoints < weight) {
            throw runtime_error("not enough HP");
        }

        hungerPoints -= weight;
        cout << name << " successfully yeeted the thing." << endl;
    }
}; // end with a semicolon

int main() {
    Character arendil("Arendil", 100);

    try {
        arendil.yeet(10);
    } catch (const runtime_error& e) {
        cout << "Failed to yeet: " << e.what() << endl;
    }

    return 0;
}