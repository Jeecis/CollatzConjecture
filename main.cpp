#include <iostream>
using namespace std;

void collatz(int number, bool start=true, int steps=0) {

    // Start case so we could print out the starting statement
    if (start) {
        cout <<"We start with: " << number << endl;
    }

    // Base case
    if (number == 1) {
        cout << "and finish with "<< steps << " steps" << endl;
        return;
    }

    // Asked chatGPT how to tackle overflow problem
    if (number > INT_MAX / 3) {  // Checking for potential overflow
        cout << "and the number caused overflow :(" << endl;
        cout << "Total steps taken "<< steps << endl;
        return;
    }

    // Recursive case/change
    if (number%2==0) {
        cout <<"then " << number/2 << endl;
        collatz(number/2, false, steps+1);
    } else {
        cout <<"then " << number*3+1 << endl;
        collatz(number*3+1, false, steps+1);
    }
}

int main() {
    int userInput;
    cout << "Input a number higher than 0" << std::endl;

    // Error catching implemented
    try {
        cin >> userInput;
        if (userInput<1){
            throw std::invalid_argument("Invalid Input");
        }
    }catch (const exception& e) {
        cout << "Invalid Input" << endl;

        //Return -1 due to error thrown
        return -1;
    }

    collatz(userInput);



    return 0;
}
