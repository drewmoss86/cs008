#ifndef WASHING_H
#define WASHING_H

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class Washer
{
public:
    //Constructor
    Washer(unsigned int s = 60);  //s is number of seconds it takes to complete a wash

    //Mutator
    void one_second();     //records passage of one simulated second after wash has started
    void start_washing();  //if wash cycle is not busy, start wash cycle by assigning total wash seconds to seconds left

    //Constant
    bool is_busy() const;

private:
    unsigned int Wash_Cycle_Seconds;  //seconds for one wash cycle
    unsigned int Wash_Seconds_Left;   //seconds remaining in wash cycle

};

class bool_source
{
public:
    //Constructor
    bool_source(double p = 0.5);

    //Constant
    bool query() const;

private:
    double probability;  //probability value that query() returns true
};

class Averager
{
public:
    Averager();

    void next_number(double value);

    size_t how_many_numbers() const;
    double average() const;

private:
    double sum;
    size_t count;
};

#endif // WASHING_H
