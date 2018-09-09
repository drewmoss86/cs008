#include <iostream>
#include <cstdlib>
#include <cassert>

#include "runway.h"

using namespace std;

//Constructor assigning l to landing_time and t to takeoff time and initializing
//landing time left and takeoff time left to 0
Runway::Runway(unsigned int l, unsigned int t)
{
    landing_time = l;      //time it takes to land on runway
    landing_time_left = 0; //time remaining before plane lands
    takeoff_time = t;      //time it takes to take off from runway
    takeoff_time_left = 0; //time remaining before plane takes off

}

//one_second_landing(): represents one simulated second of landing time
void Runway::one_second_landing()
{
    if(landing_is_busy())
        --landing_time_left;
}

//one_second_takeoff(): represents one simulated second of takeoff time
void Runway::one_second_takeoff()
{
    if(takeoff_is_busy())
        --takeoff_time_left;
}

//start_landing(): output error if busy, otherwise assign countdown timer to total landing time
void Runway::start_landing()
{
    assert(!landing_is_busy());  //error if is_busy is true
    landing_time_left = landing_time;  //assign countdown timer total landing time
}

//start_takeoff(): output error if busy, otherwise assign countdown timer to total takeoff time
void Runway::start_takeoff()
{
    assert(!takeoff_is_busy());  //error if is_busy is true
    takeoff_time_left = takeoff_time;  //assign countdown timer total takeoff time
}

//landing_is_busy(): true if landing time left or take of time left is greater than 0
bool Runway::landing_is_busy() const
{
    if(landing_time_left > 0)
        return true;

    return false;
}

//takeoff_is_busy(): true if landing time left or take of time left is greater than 0
bool Runway::takeoff_is_busy() const
{
    if(takeoff_time_left > 0)
        return true;

    return false;
}

//constructor: assigning p to probability, outputs error message if probability
//is greater than 1 or less than 0
bool_source::bool_source(double p)
{
    assert(p >= 0);   //error if probability is less than or equal to 0
    assert(p <= 1);   //error if probability is greater than or equal to 1
    probability = p;  //assign p to probability query() returns true
}

//query() const: helps generate random values to help determine if true or false
bool bool_source::query() const
{
    return rand() < probability * RAND_MAX;
}

//constructor: initializes sum and count to 0
Averager::Averager()
{
    sum = 0;      //initializes sum to 0
    count = 0;    //initializes count to 0
}

//next_number(double value): adds new value passed in to sum value and
//increments count by 1 each time a new value is passed
void Averager::next_number(double value)
{
    sum += value;  //sum adds next value to total current total wait time tracked
    count++;       //count increments 1 after ever new value is passed
}

//how_many_numbers() const: returns value of count representing total numbers
//tracked
size_t Averager::how_many_numbers() const
{
    return count;
}

//average() const: returns average by dividing sum by count
double Averager::average() const
{
    return sum/count;
}
