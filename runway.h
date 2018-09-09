#ifndef RUNWAY_H
#define RUNWAY_H

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

class Runway
{
public:
    //l is number of seconds it takes to land and t is number of seconds it
    //takes to take off
    Runway(unsigned int l = 60, unsigned int t = 70);

    void one_second_landing();
    void one_second_takeoff();
    void start_landing();
    void start_takeoff();

    //Constant
    bool landing_is_busy() const;
    bool takeoff_is_busy() const;


private:
    unsigned int landing_time;
    unsigned int landing_time_left;
    unsigned int takeoff_time;
    unsigned int takeoff_time_left;
};

class bool_source
{
public:
    //Constructor
    bool_source(double p = 0.5);  //initialize probability value that query() will return true

    bool query() const;  //returns true or false

private:
    double probability;  //represents probability that query() will return true

};

class Averager
{
public:
    //Constructor
    Averager();
    void next_number(double value);

    size_t how_many_numbers() const;
    double average() const;

private:
    size_t count;  //counter representing number of planes
    double sum;    //sum variable representing total wait time

};

#endif // RUNWAY_H
