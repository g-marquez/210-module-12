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
const int RUNS = 5;
const int MILESTONE4_PROB = 50;

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
        for (auto &lane : plaza) {
            static int i = 1;
            cout << "Lane: " << i++;
            if (!lane.empty()) {
                int prob = rand() % 100 + 1; //car in front pays and leaves
                if (prob <= MILESTONE4_PROB) {
                    cout << "Paid: "; lane.front().print();
                    lane.pop_front();
                }
                else { //car joins the back of the queue
                    cout << "Joined: ";
                    Car temp = Car();
                    lane.push_back(temp);
                    temp.print();
                }
            }
        }
        //print each lane's queue at the end of each time
        for (auto &lane : plaza) {
            static int i = 1;
            cout << "Lane " << i++ << " Queue: ";
            if (!lane.empty()) {
                cout << "\n";
                for (auto &car : lane) {
                    cout << "\t"; car.print();
                }
            }
            else
                cout << "empty";
            cout << endl;

        }
    }

    /*//begin simulation
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