//*****************************************************************************
// COMSC-210 | Lab 33 | Gabriel Marquez
// Description: this program adds functionality to Lab 32's code set by adding
// multiple lanes into the management system to simulate an entire plaza of toll
// booths and the capability for a car at the rear of a lane to switch lanes. 
//*****************************************************************************

#include "Car.h"
#include <iostream>
#include <deque>
using namespace std;

const int INITIAL_SIZE = 2;
const int PAY_PROB = 55;
const int JOIN_PROB = 45;
const int LANES = 4;

int main() {
    srand(time(0)); //for RNG

    //create array of deques
    deque<Car> plaza[LANES];

    cout << "Testing array of deques... " << endl;
    cout << "Size of array of deques (should be 4): " << size(plaza);
    cout << "\nValidating that each element has an empty deque..." << endl;
    for (int i = 0; i < size(plaza); ++i) {
        cout << "Deque at element " << i << "...";
        cout << "Empty? (1 is true) " << plaza[i].empty() << endl;
    }

    /* //declare deque of Cars and populate with 2 cars
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
    while (!tollLine.empty()) {
        static int i = 1;
        cout << "Time: " << i++;
        cout << " Operation: ";
        //randomly choose pay or join
        int prob = rand() % 100 + 1; //car in front pays and leaves
        if (prob <= PAY_PROB) {
            cout << "Car paid: ";
            tollLine.front().print();
            tollLine.pop_front();
        }
        else { //car joins the back of the queue
            cout << "Joined lane: ";
            Car temp = Car();
            tollLine.push_back(temp);
            temp.print();
        }
        //print queue at end of cycle
        cout << "Queue: ";
        if (!tollLine.empty()) {
            cout << "\n";
            for (auto &car : tollLine) {
                cout << "\t";
                car.print();
            }
        }
        else 
            cout << "empty";
        cout << endl;
    }

    return 0; */
}