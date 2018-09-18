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

//prototype
void print_STokenizer(char str[]);
int main()
{
    //assignment header
    cout << "/******************************************" << endl;
    cout << "* Name: Andrew Moss" << endl;
    cout << "*" << endl;
    cout << "* Date: 9/17/2018" << endl;
    cout << "*" << endl;
    cout << "* Class: CS 008" << endl;
    cout << "*" << endl;
    cout << "* Assignment: STokenizer" << endl;
    cout << "*" << endl;
    cout << " ******************************************/" << endl << endl;

    //test cases
    char s[] = "it was the night of october 17th. pi was still 3.14.";
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
    char s_carriageReturn[] = "\n";
    char double_carriageReturn[] = "\n\n";
    char s_tab[] = "\t";
    char double_tab[] = "\t\t";


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
        cout << "------" << endl;

    cout << "Start of test ---SINGLE DIGIT---" << endl;
    print_STokenizer(s_digit);
    cout << "End of test ---SINGLE DIGIT---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---12---" << endl;
    print_STokenizer(twelve);
    cout << "End of test ---12---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SINGLE UNKNOWN---" << endl;
    print_STokenizer(s_unk);
    cout << "End of test ---SINGLE UNKNOWN---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SEVERAL UNKNOWNS---" << endl;
    print_STokenizer(m_unk);
    cout << "End of test ---SEVERAL UNKNOWNS---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---123.45---" << endl;
    print_STokenizer(one23point45);
    cout << "End of test ---123.45---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---123.4---" << endl;
    print_STokenizer(one23pointfour);
    cout << "End of test ---123.4---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---123.4 is a number!---" << endl;
    print_STokenizer(one23pointfouris);
    cout << "End of test ---123.4 is a number!---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SINGLE SPACE---" << endl;
    print_STokenizer(s_space);
    cout << "End of test ---SINGLE SPACE---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---FOUR SPACES---" << endl;
    print_STokenizer(four_spaces);
    cout << "End of test ---FOUR SPACES---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SINGLE CARRIAGE RETURN---" << endl;
    print_STokenizer(s_carriageReturn);
    cout << "End of test ---SINGLE CARRIAGE RETURN---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---DOUBLE CARRIAGE RETURN---" << endl;
    print_STokenizer(double_carriageReturn);
    cout << "End of test ---DOUBLE CARRIAGE RETURN---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SINGLE TAB---" << endl;
    print_STokenizer(s_tab);
    cout << "End of test ---SINGLE TAB---" << endl << endl;
        cout << "------" << endl;
    cout << "Start of test ---DOUBLE TAB---" << endl;
    print_STokenizer(double_tab);
    cout << "End of test ---DOUBLE TAB---" << endl << endl;
        cout << "------" << endl;

    cout << "Start of test ---SENTENCE (NUMBER + ALPHA + PUNCT)---" << endl;
    print_STokenizer(s);
    cout << "End of test ---SENTENCE (NUMBER + ALPHA + PUNCT)---" << endl << endl;
        cout << "------" << endl;

    return 0;
}

/**********************************************************
*
*  print_STokenizer(): Token Class
*  _________________________________________________________
*  This method prints out the input string in STokenizer format
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (char) : Character array
*
*  POST-CONDITIONS
*  This function prints out the input string in STokenizer format. Returns nothing.
***********************************************************/
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
