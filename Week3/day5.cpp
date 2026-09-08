// typedef - alias 

/*
#include <iostream>
#include <string>

using namespace std;

struct Player {
    string name;
};

typedef Player* PlayerPtr;
// typedef type new_name;

int main() {
    PlayerPtr p = new Player;
    p->name = "Jones Jones";
    delete p;
}

------- separation


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a*b;
}

// defining a typedef for a function (takes two int, returns int)
typedef int (*MathOperator)(int, int);

void computeMath(int x, int y, MathOperator op, const char* opName) {
    int result = op(x, y);
    cout << opName << " of " << x << " and " << y << " = " << result << endl;
}

int main() {
    int a = 221;
    int b = 10;

    computeMath(a, b, add, "Addition");
    computeMath(a, b, subtract, "Subtraction");
    computeMath(a, b, multiply, "Multiplication");

    return 0;
}
*/


// Now, back to our themed exploration
/*
You might recall that Arendil was promised a map after catching a golden carp. 
He has now done so, and has now recieved a map to get home. He checks his satchel and 
realizes it's fully empty (it got emptied). The teavern keep feels bad and decides to help 
out, by writing down all his friends' teavern locations as (x, y) coordinates on the map. At 
the teaven locations, he stores the amount of hungerPoints (I'm simplifying) that location can 
provide. Arendil decides he wants to go to all of the locations, and now wants to traverse the 
map before he heads out to see how many hungerPoints he can actually clear in total. 
*/
// 2d array traversal

// #include <iostream>

// using namespace std;

// const int ROWS = 10;
// const int COLS = 10;

// class Map {
// private:
//     int grid[ROWS][COLS];

// public:
//     // Constructor accepting a raw 2D array from main - have to copy it ourselves for 2d arrays
//     Map(const int inputGrid[ROWS][COLS]) {
//         for (int r = 0; r < ROWS; ++r) {
//             for (int c = 0; c < COLS; ++c) {
//                 grid[r][c] = inputGrid[r][c];
//             }
//         }
//     }

//     int calcTotal() const {
//         int totalFood = 0;

//         for (int r = 0; r < ROWS; ++r) {
//             for (int c = 0; c < COLS; ++c) {
//                 totalFood += grid[r][c];
//             }
//         }

//         return totalFood;
//     }

//     void displayMap() const {
//         cout << "\n--- Map Visual (10x10 Grid) ---" << endl;
//         for (int r = 0; r < ROWS; ++r) {
//             for (int c = 0; c < COLS; ++c) {
//                 if (grid[r][c] == 0) {
//                     cout << ".  ";
//                 } else {
//                     cout << grid[r][c] << (grid[r][c] < 10 ? " " : "") << " ";
//                 }
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     int rawMap[ROWS][COLS] = {
//         {0,  0, 12,  0,  0,  0,  0,  0,  0,  0},
//         {0,  0,  0,  0,  0,  0,  0,  8,  0,  0},
//         {0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
//         {0,  0,  0, 15,  0,  0,  0,  0,  0,  0},
//         {5,  0,  0,  0,  0,  0,  0,  0,  0,  0},
//         {0,  0,  0,  0,  0,  0,  0,  0, 20,  0},
//         {0,  0, 10,  0,  0,  0,  0,  0,  0,  0},
//         {0,  0,  0,  0,  0, 14,  0,  0,  0,  0},
//         {0,  0,  0,  0,  0,  0,  0,  0,  0,  7},
//         {0, 18,  0,  0,  0,  0,  0,  0,  0,  0}
//     };

//     Map arendilMap(rawMap);

//     arendilMap.displayMap();

//     int totalHP = arendilMap.calcTotal();
//     cout << "\nTotal collectable Hunger Points on the map: " << totalHP << endl;

//     return 0;
// }


// Now, really quick, here's insertion sort. We'll use it in a small example
/*
#include <iostream>

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Helper function to display the marble values
template <typename T>
void printMarbles(const T arr[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Arendil's bag of 20 magical marbles with random potency values
    int marbles[20] = {42, 7, 19, 88, 3, 65, 21, 9, 54, 31, 12, 76, 2, 90, 33, 47, 15, 6, 81, 25};
    int size = 20;

    std::cout << "--- Before Sorting Bag of Marbles ---" << std::endl;
    printMarbles(marbles, size);

    // Perform Insertion Sort
    insertionSort(marbles, size);

    std::cout << "\n--- After Insertion Sort (Ascending) ---" << std::endl;
    printMarbles(marbles, size);

    return 0;
}
*/

// poll - do we want to revise recursion really quickly with an example?
// if so, fibonacci: f(n) = f(n-1) + f(n-2), starting at 1 and 2

// f(n - 1) = f(n - 3) + f(n - 2)

// f(1) = 1; f(2) = 2

/*
1 2 3 5 8 13 21 ...
1 2 3 4 5 6  7  ...
*/
/*
#include <iostream>

using namespace std;

int fibonacci(int n) {
    //invalid case
    if (n <= 0) return 0;
    //base
    if (n == 1) return 1;
    if (n == 2) return 2;
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main() {
    cout << fibonacci(7) << endl;
    return 0;
}
*/

/*
Factorial
Sum of an array but recursive
*/
// factorial - f(n) = n(n-1)! goes until n = 1

#include <iostream>

using namespace std;

int factorial(int n) {
    //invalid case + base case
    if (n <= 1) return 1;
    return n*factorial(n-1);
}

double halfPower(int n) {
    if (n == 0) {
        return 1;
    } else  {
        return 0.5*halfPower(n - 1);
    }
}

double twoPower(int n) {
    if (n < 0) {
        return halfPower(-1 * n);
    } else if (n == 0) {
        return 1;
    } else {
        return 2*twoPower(n - 1);
    }
}

int main() {
    cout << factorial(3) << endl;
    cout << twoPower(-3) << endl;
    return 0;
}


// Finally, a short introduction to linked lists and an implementation if time permits
/*
Linked lists - chains of nodes
singularly - one direction - start at head, keep following the links between nodes in one direction
           - you can only go to next 
doubly     - two directions - start at head, follow links foward (next) or back (prev)
circularly - one direction, but you can go back to head by going next until you circle back
*/