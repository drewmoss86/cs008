/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/17/2018
 *
 * Class: CS 008
 *
 * Assignment: STokenizer
 *
 ******************************************/
#include <iomanip>
#include <iostream>
#include "stokenizer.h"

void print_STokenizer(char str[]);
int main()
{
    char s_digit[] = "4";
    char s_unk[] = "&";
    char m_unk[] = "&#";
    char empty[] = "";
    char s_space[] = " ";
    char four_spaces[] = "    ";
    char twelve[] = "12";
    char one23point45[]= "123.45";
    char one23pointfour[] = "123.4";
    char one23pointfouris[] = "123.4 is a number!";
    char returnLine[] = "\n";


    cout << "Start of test ---EMPTY w/ STK CONSTRUCTOR---" << endl;
    STokenizer stk(empty);
    Token t;
    // The all too familiar golden while loop:
    stk >> t;
    while(stk.more()) {
        // process token here...
        cout << setw(10) << t.type_string() << setw(10) << t << endl;

        t = Token();
        stk >> t;
    }
    cout << "End of test ---EMPTY w/ STK CONSTRUCTOR---" << endl << endl;

    cout << "Start of test ---SINGLE DIGIT---" << endl;
    print_STokenizer(s_digit);
    cout << "End of test ---SINGLE DIGIT---" << endl << endl;

    cout << "Start of test ---12---" << endl;
    print_STokenizer(twelve);
    cout << "End of test ---12---" << endl << endl;

    cout << "Start of test ---SINGLE UNKNOWN---" << endl;
    print_STokenizer(s_unk);
    cout << "End of test ---SINGLE UNKNOWN---" << endl << endl;

    cout << "Start of test ---SEVERAL UNKNOWNS---" << endl;
    print_STokenizer(m_unk);
    cout << "End of test ---SEVERAL UNKNOWNS---" << endl << endl;

    cout << "Start of test ---123.45---" << endl;
    print_STokenizer(one23point45);
    cout << "End of test ---123.45---" << endl << endl;

    cout << "Start of test ---123.4---" << endl;
    print_STokenizer(one23pointfour);
    cout << "End of test ---123.4---" << endl << endl;

    cout << "Start of test ---123.4 is a number!---" << endl;
    print_STokenizer(one23pointfouris);
    cout << "End of test ---123.4 is a number!---" << endl << endl;

    cout << "Start of test ---SINGLE SPACE---" << endl;
    print_STokenizer(s_space);
    cout << "End of test ---SINGLE SPACE---" << endl << endl;

    cout << "Start of test ---FOUR SPACES---" << endl;
    print_STokenizer(four_spaces);
    cout << "End of test ---FOUR SPACES---" << endl << endl;

    cout << "Start of test ---RETURN LINE---" << endl;
    print_STokenizer(returnLine);
    cout << "End of test ---RETURN LINE---" << endl << endl;


    return 0;
}
void print_STokenizer(char str[])
{
    STokenizer stk(str);
    Token t;

    stk.set_string(str);
    // The all too familiar golden while loop:
    stk >> t;
    while(stk.more()) {
        // process token here...
        cout << setw(10) << t.type_string() << setw(10) << t << endl;

        t = Token();
        stk >> t;
    }
}
