#include <iostream>
#include <string>

#include "CLinkedList.h" //how to get access to a header file in your code

using namespace std;

// int main() {
//     // 1. Working with integers
//     LinkedList<int> intList;

//     std::cout << "--- Integer List ---" << std::endl;
//     intList.insertEnd(10);
//     intList.insertEnd(20);
//     intList.insertFront(5);
//     intList.display(); // Output: 5 -> 10 -> 20 -> NONE

//     intList.insertAfter(15, 10);
//     intList.display(); // Output: 5 -> 10 -> 15 -> 20 -> NONE

//     intList.removeFront();
//     intList.display(); // Output: 10 -> 15 -> 20 -> NONE

//     std::cout << "Size: " << intList.getSize() << std::endl; // Output: Size: 3

//     // 2. Working with strings
//     LinkedList<std::string> stringList;

//     std::cout << "\n--- String List ---" << std::endl;
//     stringList.insertEnd("Alice");
//     stringList.insertEnd("Bob");
//     stringList.insertEnd("Charlie");
//     stringList.display(); // Output: Alice -> Bob -> Charlie -> NONE

//     stringList.removeAfter("Alice");
//     stringList.display(); // Output: Alice -> Charlie -> NONE

//     return 0;
// }

// int main() {
//     LinkedList<int> intList;

//     intList.insertFront(10);
//     intList.insertFront(20);
//     intList.insertFront(5);
//     cout << intList.getSize() << endl;
//     intList.display(); // Output: 5 -> 10 -> 20 -> NONE

//     intList.removeFront();
//     intList.display();

//     return 0;
// }

int main() {
    CLinkedList<int> intList;

    intList.insertFront(10);
    intList.insertFront(20);
    intList.insertFront(5);
    cout << intList.getSize() << endl;
    intList.display(); 

    intList.removeFront();
    cout << intList.getSize() << endl;
    intList.display();

    return 0;
}

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

