#include <iostream>
#include <cstdlib>
#include <cassert>

#include "washing.h"
#include "../assign1_cs008/myqueue.h"

using namespace std;

Washer::Washer(unsigned int s)
{
    Wash_Cycle_Seconds = s;
    Wash_Seconds_Left = 0;
}

//washer records and simulates passage of one second
void Washer::one_second()
{
    if(is_busy())
    {
       --Wash_Seconds_Left;  //indicates one simulated second has passed
    }
}

//returns true if washer is busy, otherwise false
bool Washer::is_busy() const
{
    if(Wash_Seconds_Left > 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

//check if washer is busy, if not, simulate one wash cycle
void Washer::start_washing()
{
    assert(!is_busy());  //error if machine is currently washing
    Wash_Seconds_Left = Wash_Cycle_Seconds;  //when the wash cycle begins, reset wash seconds left to wash cycle seconds
}

//assign probability
bool_source::bool_source(double p)
{
    assert(p >= 0);
    assert(p <= 1);
    probability = p;  //initialize probability with a value
}

//generate random boolean values
bool bool_source::query() const
{
    return rand() < probability * RAND_MAX;  //use to calc probability of returning true
}

//initialize averager
Averager::Averager()
{
    sum = 0.0;     //initialize sum
    count = 0;     //initialize count
}

void Averager::next_number(double value)
{
    ++count;       //count every time next_number is called
    sum += value;  //sums the next number
}

size_t Averager::how_many_numbers() const
{
    return count;  //counts number of planes
}

double Averager::average() const
{
    assert(how_many_numbers() > 0);  //error if count is <= 0 - cannot find avg if no cars
    return sum/count;   //find avg wait time by taking sum of all weight times divide by number of cars
}
