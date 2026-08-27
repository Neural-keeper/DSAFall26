/*
Welcome to Data Structures (Fall 2026, COP4530)
*/

#include <iostream>
#include <string> //this is new, in C you'd have to make an array of characters
#include <cstdlib> //EXIT_SUCCESS

using namespace std; //so I don't have to use std::cout

void helloWorld() {
    cout << "Hello World!" << endl;
}

void sumof2() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    int sum = x + y;
    cout << "The sum of your numbers is: " << sum << endl;
}

void iseven() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (x % 2 == 0) {
        cout << "Your number is even." << endl; // warning, if you choose to use "else" to catch even
        // you will end up with "-1" being even, which it is not
    } else {
        cout << "Your number is odd." << endl;
    }
}

/*
Stacks - pile a books
Only access the top
*/

int main() {
    // helloWorld();
    // sumof2();

    iseven();

    return EXIT_SUCCESS;
}