#include <iostream>
#include <iomanip>
#include "token.h"

using namespace std;

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
    case 0: cout << "DIGITS"; break;
    case 10: cout << "ALPHA"; break;
    case 20: cout << "PUNCT"; break;
    case 25: cout << "SPACE"; break;

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

