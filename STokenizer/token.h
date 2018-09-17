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
    Token();
    Token(string str, int type);
    friend ostream& operator <<(ostream& outs, const Token& t);
    int type();
    string type_string();
    string token_str();
private:
    string _token;
    int _type;
};

#endif // TOKEN_H
