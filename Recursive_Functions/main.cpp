#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//prototype
void R1_levls(int start, int end);
void R2_Box(string prefix, unsigned levels);
void R3_first_second(string, string);
void R4_count_box(string prefix, unsigned m);
double R5_sumover(unsigned n);
void guess(int, int);

int main()
{
//    R1_levls(1,4);
//    cout << "----------------" << endl;
//    R2_Box("Box:", 2);
//    cout << "----------------" << endl;
//    R3_first_second("CAT","MAN");
//    cout << "----------------" << endl;

//    cout << "----------------" << endl;
//    unsigned m = 0;

//    cout << "How many unnumbered boxes can you see?" << endl;
//    cin >> m;

//    R4_count_box("Box:", m);
//    cout << "----------------" << endl;
//    cout << "3: " << R5_sumover(3) << endl;
//    cout << "2: " << R5_sumover(2) << endl;
//    cout << "1: " << R5_sumover(1) << endl;
//    cout << "0: " << R5_sumover(0) << endl;
//    cout << "----------------" << endl;

    cout << "----------------" << endl;
    guess(1, 1000000);

//    outFile.close();
    return 0;
}
void R1_levls(int start, int end)
{
    //base case - when the start and end values are the same
    if(start == end)
        cout << right << setw(18*start) << "This was written by call number " << start << "." << endl;
    //print when start exceeds or is equal to end
    if(start >= end)
        cout << right << setw(18*start) << "This ALSO written by call number " << start << "." << endl;

    //while start value is less than end value, call function recursively
    else
    {
        cout << right << setw(18*start) << "This was written by call number " << start << "." << endl;
        R1_levls(start+1, end);
        cout << right << setw(18*start) << "This ALSO written by call number " << start << "." << endl;
    }
}
void R2_Box(string prefix, unsigned levels)
{
    string s;

    //base case
    if(levels == 0)
    {
        cout << prefix << endl;
    }

    else
    {
        for(unsigned i = 1; i < 10; i++)
        {
            s = prefix;
            s += char('0' + i);
            s += ".";
            R2_Box(s, levels - 1);
        }
    }

}

void R3_first_second(string first, string second)
{
    string x = "";

    //base case
    if(!first.size())
    {
        cout << "sec: " << second << endl;
    }

    cout << "first: " << first << endl;

    for(unsigned i = 0; i < first.size(); i++)
    {
        cout << "i: " << i << endl;
        x = first[i];
        cout << "x:" << x << endl;
        R3_first_second(first.erase(0,1), second.insert(0,x));

    }
}

void R4_count_box(string prefix, unsigned m)
{
    string s;

    //base case
    if(m == 0)
    {
        cout << prefix << endl;
    }

    else
    {
        for(unsigned i = 1; i < 10; i++)
        {
            s = prefix;
            s += char('0' + i);
            s += ".";
            R4_count_box(s, m - 1);
        }
    }

}

double R5_sumover(unsigned n)
{
    //base case
    if(n == 0)
        return 0.0;
    else
    {
        return R5_sumover(n - 1) + 1.0/n;
    }

}


void guess(int low, int high)
{
    char answer = ' ';

    cout << "Think of a number between " << low << " and " << high << endl;

    if(low == high)
    {
        cout << low << " is your number." << endl;
    }

    else if(low < high)
    {
        int midpoint = 0;
        midpoint = (low + high) / 2;

        cout << "Is " << midpoint << " the correct number (y = YES or n = NO)?" << endl;
        cin >> answer;

        if(answer == 'y' || answer == 'Y')
        {
            cout << midpoint << " is your number." << endl;
        }
        else if(answer == 'n' || answer == 'N')
        {
            cout << "Is correct number higher or lower than " << midpoint << "(h = HIGHER or l = LOWER)" << endl;
            cin >> answer;

            if(answer == 'h' || answer == 'H')
            {
                guess(midpoint + 1, high);
            }
            else if(answer == 'l' || answer == 'L')
            {
                guess(low, midpoint - 1);
            }
        }
    }
}
