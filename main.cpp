//*****************************************************************************
// COMSC-210 | Lab 32 | Gabriel Marquez
// Description: this program simulate a line of cars lined up to pay their toll
// at a toll booth, utilizing the std::deque container.
//*****************************************************************************

#include "Car.h"
#include <iostream>
#include <deque>
using namespace std;

const int INITIAL_SIZE = 2;

int main() {
    srand(time(0)); //for RNG

    //declare deque of Cars and populate with 2 cars
    deque<Car> tollLine;
    for (int i = 0; i < INITIAL_SIZE; ++i) {
        Car temp = Car();
        tollLine.push_back(temp);
    }

    //print initial queue of cars
    cout << "Initial queue:" << endl;
    //exercise deque methods and display cars
    if (!tollLine.empty()) {
        Car car1 = tollLine.front();
        Car car2 = tollLine.back();
        cout << "\t";
        car1.print();
        car2.print();
    }
    else 
        cout << "empty";

    return 0;
}