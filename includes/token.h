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
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
//#include "state_machine_functions.h"
#include "constants.h"
using namespace std;

class Token
{

public:
    //default constructor
    Token();
    //constructor
    Token(string str, int type);
    //overloaded insertion operator
    friend ostream& operator <<(ostream& outs, const Token& t);

    int type();            //initial state value of each state type
    string type_string();  //string representation of state type
    string token_str();    //string representation of token
private:
    string _token;         //string stores token variable
    int _type;             //integer storing token state value
};

#endif // TOKEN_H
