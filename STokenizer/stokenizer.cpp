#include <iostream>
#include "stokenizer.h"

//Global
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

using namespace std;

STokenizer::STokenizer()
{
    _pos = 0;
    _buffer[_pos] = '\0';
    make_table(_table);
}

STokenizer::STokenizer(char str[])
{
    _pos = 0;
    while(str[_pos] != '\0')
    {
        assert(str[_pos] != '\0');
        _buffer[_pos] = str[_pos];
//        cout << _buffer[_pos];
        _pos++;
    }
    cout << endl;
    make_table(_table);

}
//true: there are no more tokens
bool STokenizer::done()
{
    if(_buffer[_pos] == '\0')
    {
        assert(_buffer[_pos] == '\0');
        return true;
    }

    return false;
}
//true: there are more tokens
bool STokenizer::more()
{
    if(_buffer[_pos] != '\0')
    {
        assert(_buffer[_pos] != '\0');
        return true;
    }

    return false;

}
//-- big three --

//---------------
//extract one token (very similar to the way cin >> works)
STokenizer& operator >> (STokenizer& s, Token& t)
{
    int DIGITS_START = 0;
    int ALPHA_START = 10;
    int PUNCT_START = 20;
    int SPACES_START = 25;


//    cout << "ALPHA0:" << ALPHA[0] << endl;
//    cout << "DIGITS0:" << DIGITS[0] << endl;
//    cout << "PUNCT0:" << PUNCT[0] << endl;
//    cout << "SPACES0:" << SPACES[0] << endl;

    string token = "";

    if(s.get_token(ALPHA_START,token))
    {
        cout << "token: " << token;
        t = Token(token,ALPHA_START);
        return s;
    }

    else if(s.get_token(DIGITS_START,token))
    {
        cout << "token: " << token;
        t = Token(token,DIGITS_START);
        return s;
    }

    else if(s.get_token(PUNCT_START,token))
    {
        cout << "token: " << token;
        t = Token(token,PUNCT_START);
        return s;
    }

    else if(s.get_token(SPACES_START,token))
    {
        cout << "token: " << token;
        t = Token(token,SPACES_START);
        return s;
    }

    else
    {
        t = Token();
        s._pos++;
        return s;
    }
}

//set a new string as the input string
void STokenizer::set_string(char str[])
{
    int index = 0;
    while(str[index] != '\0')
    {
        _buffer[index] = str[index];
        index++;
    }
    _buffer[index] = '\0';  //set end of last index to null


}

//create table for all the tokens we will recognize
//                      (e.g. doubles, words, etc.)
void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    init_table(_table);

    //doubles
    mark_fail(_table,0);
    mark_success(_table,1);
    mark_fail(_table, 2);
    mark_success(_table,3);

    mark_cells(0, _table, DIGITS, 1);    //state [0] --- DIGITS ---> [1]
    mark_cells(0, _table, '.', '.', 2);  //state [0] --- '.' ------> [2]
    mark_cells(1, _table, DIGITS, 1);    //state [1] --- DIGITS ---> [1]
    mark_cells(1, _table, '.', '.', 2);  //state [1] --- '.' ------> [2]
    mark_cells(2, _table, DIGITS, 3);    //state [2] --- DIGITS ---> [3]
    mark_cells(3, _table, DIGITS, 3);    //state [3] --- DIGITS ---> [3]

    //alpha
    mark_fail(_table,10);
    mark_success(_table,11);

    mark_cells(10, _table, ALPHA, 11);    //state [10] --- ALPHA ---> [11]
    mark_cells(11, _table, ALPHA, 11);    //state [11] --- ALPHA ---> [12]

    //punctuation
    mark_fail(_table,20);
    mark_success(_table,21);

    mark_cells(20, _table, PUNCT, 21);    //state [20] --- ALPHA ---> [21]
    mark_cells(21, _table, PUNCT, 21);    //state [21] --- ALPHA ---> [22]

    //space
    mark_fail(_table,25);
    mark_success(_table,26);

    mark_cells(25, _table, SPACES, 26);    //state [20] --- ALPHA ---> [21]
    mark_cells(26, _table, SPACES, 26);    //state [21] --- ALPHA ---> [22]

    //print table
//    for(unsigned i = 0; i < MAX_ROWS; i++)
//    {
//        for(unsigned j = 0; j < MAX_COLUMNS; j++)
//        {
//            cout << _table[i][j];
//        }
//        cout << endl;
//    }

}

//return true if a token was found that was accepted by the machine starting at given state
bool STokenizer::get_token(int start_state, string& token)
{
    while(_table[start_state][_buffer[_pos]] != -1)
    {
        token = token + _buffer[_pos];
        _pos++;

        cout << token;
        return true;

    }

    return false;

    //return true if a token was found, false otherwise
//    if()
    //pos will point to the next char to be processed if returning true
    //pos will be unchanged if returning false
    //if a succcess state was encountered while transitioning from state-to-state, determining pos and token
}
