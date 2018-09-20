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
*  Token(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
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

/**********************************************************
*
*  Token(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  str (string) :
*  type (int)   :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
Token::Token(string str, int type)
{
    _token = str;
    _type = type;
}

/**********************************************************
*
*  type(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
int Token::type()
{
    return _type;

}

/**********************************************************
*
*  type_string(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
string Token::type_string()
{
    //return type string i.e. ALPHA, DIGITS, PUNCT,
    switch(_type)
    {
    case -1: return "UNKNOWN";
    case 0: return "NUMBER";
    case 10: return "ALPHA";
    case 14: return "CARRIAGE RETURN";
    case 17: return "TAB";
    case 20: return "PUNCT";
    case 25: return "SPACE";
    default: return "UNKNOWN";
    }

}

/**********************************************************
*
*  token_str(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
string Token::token_str()
{
    return _token;
}

/**********************************************************
*
*  operator<<(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  outs (ostream) :
*  t (Token)      :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
ostream& operator<<(ostream& outs, const Token& t)
{
    return outs << "|" + t._token + "|";
}

