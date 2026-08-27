#include <iostream>

using namespace std;

int main() {
    int a = 34;

    cout << "Hello World! " << a << " years of something" << endl;

    /*
    In C - to print to terminal - printf("thing to print")
    In C++ - cout <- prints to terminal: '<<' : thing you put inside to print
    */

    int b;

    cout << "How old are you? ";
    cin >> b; // input from user/terminal

    cout << "Wow, you're " << b << " years old!" << endl;
    return 0;
}