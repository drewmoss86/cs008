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
#include <iostream>
#include <iomanip>
#include "token.h"

using namespace std;
/**********************************************************
*
*  Runway(): Class Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  l : integer representing time it takes to land
*  t : integer representing time it takes to takeoff
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
Token::Token()
{
    _token = "";
    _type = 0;

}
Token::Token(string str, int type)
{
    _token = str;
    _type = type;
}
int Token::type()
{
    return _type;

}
string Token::type_string()
{
    //return type string i.e. ALPHA, DIGITS, PUNCT,
    switch(_type)
    {
    case 0: return "NUMBER";
    case 10: return "ALPHA";
    case 20: return "PUNCT";
    case 25: return "SPACE";
    default: return "UNKNOWN";
    }

}
string Token::token_str()
{
    return _token;
}
ostream& operator<<(ostream& outs, const Token& t)
{
    return outs << "|" + t._token + "|";
}

