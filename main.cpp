#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "../includes/list.h"
#include "../includes/myqueue.h"
#include "runway.h"

using namespace std;

//prototype
void runway_sim(unsigned int time_to_land, unsigned int time_to_takeoff,
                double landing_prob, double takeoff_prob,
                unsigned int fuel_limit, unsigned int total_sim_time);

void measuringStick(unsigned int, string);

int main()
{
    runway_sim(5, 15, 0.1, 0.08, 20, 1440);
    runway_sim(5, 15, 0.1, 0.08, 20, 10000);
    runway_sim(5, 15, 0.1, 0.08, 20, 100000);

    return 0;
}

//used to print lines for the data output
void measuringStick(unsigned int n, string x)
{
    for(unsigned int i = 0; i < n; i++)
    {
        cout << x;
    }
    cout << endl;
}

void runway_sim(unsigned int time_to_land, unsigned int time_to_takeoff,
                double landing_prob, double takeoff_prob,
                unsigned int fuel_limit, unsigned int total_sim_time)
{
    myQueue<unsigned int> landing_times;
    myQueue<unsigned int> takeoff_times;
    bool_source landing(landing_prob);
    bool_source takeoff(takeoff_prob);
    Runway runway(time_to_land, time_to_takeoff);
    Averager wait_times_landing;
    Averager wait_times_takeoff;
    unsigned int current_time;
    unsigned int next_landing;
    unsigned int next_takeoff;
    unsigned int crash = 0;
    unsigned int landing_push_count = 0;
    unsigned int takeoff_push_count = 0;
    unsigned int landing_pop_count = 0;
    unsigned int takeoff_pop_count = 0;
    unsigned int landing_queue = 0;
    unsigned int takeoff_queue = 0;

    measuringStick(35, "=");   //used for printing borders in the output
    cout << "TESTING PARAMETERS" << endl;
    measuringStick(35, "-");   //used for printing borders in the output
    cout << "Time to Take-off" << right << setw(10) << ": " << time_to_takeoff << endl;
    cout << "Time to Land" << right << setw(14) << ": " << time_to_land << endl;
    cout << "Probability of Landing" << right << setw(4) << ": " << landing_prob << endl;
    cout << "Probability of Takeoff" << right << setw(4) << ": " << takeoff_prob << endl;
    cout << "Fuel" << right << setw(22) << ": " << fuel_limit << endl;
    cout << "Total Simulation Time" << right << setw(5) << ": " << total_sim_time << endl;
    measuringStick(35, "=");

    for(current_time = 1; current_time <= total_sim_time; current_time++)
    {
        //Check if there is a plane ready to land or take off
        if(landing.query())
        {
            landing_times.push(current_time);
            landing_push_count++;
        }

        if(takeoff.query())
        {
            takeoff_times.push(current_time);
            takeoff_push_count++;
        }


        //landing
        if(!runway.landing_is_busy() && !landing_times.empty())
        {
            //store head value in variable next
            next_landing = landing_times.front();
            //remove head value from queue
            landing_times.pop();
            landing_pop_count++;
            if(current_time - next_landing > fuel_limit)
                crash++;

            //take wait time (current_time - next) add to sum
            wait_times_landing.next_number(current_time - next_landing);
            runway.start_landing();
        }
        
        runway.one_second_landing();

        //takeoff
        if(!runway.takeoff_is_busy() && !takeoff_times.empty())
        {
            //store head value in variable next
            next_takeoff = takeoff_times.front();
            //remove head value from queue
            takeoff_times.pop();
            takeoff_pop_count++;
            //take wait time (current_time - next) add to sum
            wait_times_takeoff.next_number(current_time - next_takeoff);
            runway.start_takeoff();
        }

        runway.one_second_takeoff();

    }

    //tracks remaining items in landing queue
    landing_queue = landing_push_count - landing_pop_count;
    //tracks remaining items in landing queue
    takeoff_queue = takeoff_push_count - takeoff_pop_count;

    measuringStick(100, "=");  //used for printing borders in the output
    cout << "\nSAMPLE OUTPUT" << endl;

    measuringStick(100, "-");  //used for printing borders in the output
    cout << left
         << setw(10) << "|Landed"
         << setw(10) << "|Took_Off"
         << setw(10) << "|Crashed"
         << setw(18) << "|Avg_Landing_Wait"
         << setw(19) << "|Avg_Takeoff_Wait"
         << setw(16) << "|Landing_Queue"
         << setw(10) << "|Takeoff_Queue" << endl;
   measuringStick(100, "-");  //used for printing borders in the output

    cout << left
         << "|"  << setw(8) << wait_times_landing.how_many_numbers()
         << " |" << setw(8) << wait_times_takeoff.how_many_numbers()
         << " |" << setw(9) << crash;
    if(wait_times_landing.how_many_numbers() > 0)
        cout << left << "|" << setw(17) << fixed << setprecision(3) 
             << wait_times_landing.average();
    if(wait_times_takeoff.how_many_numbers() > 0)
        cout << left << "|" << setw(18) << wait_times_takeoff.average();
    cout << left << "|" << setw(15) << landing_queue
         <<  "|" << setw(16) << takeoff_queue
         << endl;
    measuringStick(100, "-");  //used for printing borders in the output
    cout << endl;
    measuringStick(100, "=");  //used for printing borders in the output


}
