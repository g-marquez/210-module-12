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
const int PAY_PROB = 55;
const int JOIN_PROB = 45;

int main() {
    srand(time(0)); //for RNG

    //declare deque of Cars and populate with 2 cars
    deque<Car> tollLine;
    for (int i = 0; i < INITIAL_SIZE; ++i) {
        Car temp = Car();
        tollLine.push_back(temp);
    }

    //print initial queue of cars
    cout << "Initial queue: " << endl;
    //coding this way specifically to exercise deque methods
    if (!tollLine.empty()) {
        Car car1 = tollLine.front();
        Car car2 = tollLine.back();
        cout << "\t"; car1.print();
        cout << "\t"; car2.print();
    }
    else 
        cout << "empty";

    //begin simulation
    for (int i = 0; i < tollLine.size(); ++i) {
        cout << "Time: " << i + 1;
        cout << " Operation: ";
        //randomly choose pay or join
        int prob = rand() % 100 + 1; //car in front pays and leaves
        if (prob <= PAY_PROB) {
            cout << "Car paid: ";
            Car temp = tollLine.front();
            temp.print();
        }
        else { //car joins the back of the queue

        }
    }

    return 0;
}