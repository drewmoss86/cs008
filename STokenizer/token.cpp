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

