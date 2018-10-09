/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/19/2018
 *
 * Class: CS 008
 *
 * Assignment: EXTRA: Recursion Drill
 *
 ******************************************/

#include <iostream>
#include <cassert>
#include <iomanip>


using namespace std;
//proto
void random_fractal(double left_ht, double right_ht, double width, double epsilon, int index);
void display(double x);
double random_real(double low, double high);
double random_fraction();

int main()
{
    random_fractal(10.0, 10.0, 16.0, 1.0, 5);
    cout << endl;
    return 0;
}
void random_fractal(double left_ht, double right_ht, double width, double epsilon, int index)
{
    double mid_height;

    assert(width > 0);
    assert(epsilon > 0);

    //base case
    if(width <= epsilon)
    {
        display(right_ht);
        cout << setw(5*index) << index << endl;
    }

    else
    {
        mid_height = (left_ht + right_ht) / 2;
        mid_height += random_real(-width, width);
        cout << setw(5*index) << index << endl;
        random_fractal(left_ht, mid_height, width/2, epsilon, index-1);
        cout << setw(5*index) << index << endl;
        random_fractal(mid_height, right_ht, width/2, epsilon, index-1);
        cout << setw(5*index) << index << endl;
    }
}

void display(double x)
{
    const char STAR = '*';
    const char BLANK = ' ';
    const char VERTICAL_BAR = '|';
    const int LIMIT = 39;
    int i;

    if(x < -LIMIT)
        x = -LIMIT;

    else if (x > LIMIT)
        x = LIMIT;

    for(i = -LIMIT; i < 0; i++)
    {
        if(i >= x)
            cout << STAR;
        else
            cout << BLANK;
    }
    cout << VERTICAL_BAR;

    for(i = 1; i <= LIMIT; i++)
    {
        if(i <= x)
            cout << STAR;
        else
            cout << BLANK;
    }
    cout << endl;
}

double random_real(double low, double high)
{
    assert(low <= high);
    return low + random_fraction() * (high - low);
}
//return valueis a random real number between 0..1
double random_fraction()
{
    return rand() / double(RAND_MAX);
}
