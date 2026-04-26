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
const int PAY_PROB = 46;
const int JOIN_PROB = PAY_PROB + 39;
const int SWITCH_PROB = JOIN_PROB + 15;
const int EMPTY_PROB = 50;
const int LANES = 4;
const int RUNS = 5;

int main() {
    srand(time(0)); //for RNG

    //create array of deques
    deque<Car> plaza[LANES];

    //populate lanes in plaza with 2 cars each
    for (auto &lane : plaza) {
        for (int i = 0; i < INITIAL_SIZE; ++i) {
        Car temp = Car();
        lane.push_back(temp);
        }
    }

    //print initial queue of cars
    cout << "Initial queue: " << endl;
    for (auto &lane : plaza) {
        static int i = 1; //static, not const!
        cout << "Lane " << i++ << ":" << endl;
        for (auto &car : lane) {
            cout << "\t"; car.print(); //to better mimic output
        }
    }

    //begin simulation
    //starting with 5 cycles for testing
    for (int i = 0; i < RUNS; ++i) {
        cout << "Time: " << i + 1 << endl;
        for (int i = 0; i < size(plaza); i++) {
            cout << "Lane: " << i + 1;
            if (!plaza[i].empty()) {
                int prob = rand() % 100 + 1; //car in front pays and leaves
                if (prob <= PAY_PROB) {
                    cout << " Paid: "; plaza[i].front().print();
                    plaza[i].pop_front();
                }
                else if (prob <= JOIN_PROB) { //car joins the back of the queue
                    cout << " Joined: ";
                    Car temp = Car();
                    plaza[i].push_back(temp);
                    temp.print();
                }
                else if (prob <= SWITCH_PROB) { //car at back switches lanes
                    cout << " Switched: "; plaza[i].back().print();
                    //choose random lane to switch to
                    int lane_index = rand() % LANES;
                    //if index is same as current lane, add 1
                    if (lane_index == i) {
                        lane_index++;
                        //if index is out of bounds
                        //go back to index 0
                        if (lane_index >= size(plaza))
                            lane_index = 0;
                    }
                }
            }
            else { //lane is empty, 50/50 that a new car joins
                int prob = rand() % 100 + 1;
                if (prob <= EMPTY_PROB) {
                    cout << " Joined: ";
                    Car temp = Car();
                    plaza[i].push_back(temp);
                    temp.print();
                }
                else 
                    cout << " No change" << endl; //just in case a car doesn't join

            }
        }
        //print each lane's queue at the end of each time
        for (int i = 0; i < size(plaza); i++) {
            cout << "Lane " << i + 1 << " Queue: ";
            if (!plaza[i].empty()) {
                cout << "\n";
                for (auto &car : plaza[i]) {
                    cout << "\t"; car.print();
                }
            }
            else
                cout << "empty";
            cout << endl;

        }
    }
    return 0;
}