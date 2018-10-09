#include <iostream>
#include <cstdlib>
#include <cassert>

#include "washing.h"
#include "../includes/myqueue.h"
#include "../includes/list.h"


using namespace std;

//prototype
void car_wash_simulation(unsigned int, double, unsigned int);

int main()
{
    car_wash_simulation(240, 0.0025, 6000);

    return 0;
}
void car_wash_simulation(unsigned int wash_time, double arrival_prob,
                         unsigned int total_time)
{
    myQueue<unsigned int> arrival_times;  //waiting customer time
    unsigned int next;  //value taken from the queue
    bool_source arrival(arrival_prob);
    Washer machine(wash_time);
    Averager wait_times;
    unsigned int current_sec;

    cout << "Seconds to wash one car: " << wash_time << endl;
    cout << "Probability of customer arrival during a second: ";
    cout <<  arrival_prob << endl;
    cout << "Total simulation seconds: " << total_time << endl;

    for(current_sec = 1; current_sec <= total_time; ++current_sec)
    {
        //Simulate the passage of one sec of time

        //Check if new customer has arrived
        if(arrival.query())
            arrival_times.push(current_sec);

        //Check if we can start washing the next car
        if(!machine.is_busy() && !arrival_times.empty())
        {
            next = arrival_times.front();
            arrival_times.pop();
            wait_times.next_number(current_sec - next);
            machine.start_washing();
        }

        //Tell washer to simulate the passage of one second
        machine.one_second();
    }

    //Summary of the simulation
    cout << "Customers served: " << wait_times.how_many_numbers() << endl;
    if(wait_times.how_many_numbers() > 0)
        cout << "Average wait: " << wait_times.average() << " sec" << endl;

}
