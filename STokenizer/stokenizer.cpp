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
#include "stokenizer.h"
#include <iostream>
#include <cstring>

// Global
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

using namespace std;

/**********************************************************
*
*  STokenizer(): Class STokenizer
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
STokenizer::STokenizer()
{
    _pos = 0;
    _buffer[_pos] = '\0';
    make_table(_table);
}


/**********************************************************
*
*  STokenizer(): Class STokenizer
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (char) :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
STokenizer::STokenizer(char str[])
{
    _pos = 0;
    while(str[_pos] != '\0')
    {
        assert(str[_pos] != '\0');
        _buffer[_pos] = str[_pos];
        _pos++;
    }
    _buffer[_pos] = '\0';

    make_table(_table);
    _pos = 0;  //reset position to 0
}

// true: there are no more tokens
/**********************************************************
*
*  done(): Class STokenizer
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*
***********************************************************/
bool STokenizer::done()
{
    if(_buffer[_pos+1] == '\0')
    {
        assert(_buffer[_pos] == '\0');
        return true;
    }

    return false;
}

// true: there are more tokens
/**********************************************************
*
*  more(): Class STokenizer
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
bool STokenizer::more()
{
    if(_pos <= strlen(_buffer))
    {
//        assert(_buffer[_pos] != '\0');
        return true;
    }

    return false;
}

// extract one token (very similar to the way cin >> works)
/**********************************************************
*
*  operator>>(): Class STokenizer
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  s (STokenizer) :
*  t (Token)      :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
STokenizer& operator>>(STokenizer& s, Token& t)
{
    const bool debug = false;  //for debugging
    //for debugging
    if(debug) {
        cout << "in operaor>>" << endl;
        cout << ">> _pos: " << s._pos << endl;
    }

    int DIGITS_STATE = 0;    //init variable to beginning of digits state
    int ALPHA_STATE = 10;    //init variable to beginning of alpha state
    int PUNCT_STATE = 20;    //init variable to beginning of punct state
    int SPACES_STATE = 25;   //init variable to beginning of spaces state

    string token = "";       //initialize token to empty string

    //for debugging
    if(debug) {
        cout << "-----\nDIGITS STATE\n-----" << endl;
    }

    //gets any numerical token
    if(s.get_token(DIGITS_STATE, token)) {
        t = Token(token, DIGITS_STATE);
        return s;
    }

    //gets any alpha token
    if(debug) {
        cout << "-----\nALPHA STATE\n-----" << endl;
    }
    //for debugging
    if(s.get_token(ALPHA_STATE, token)) {
        t = Token(token, ALPHA_STATE);
        return s;
    }

    //for debugging
    if(debug) {
        cout << "-----\nSPACE STATE\n-----" << endl;
    }

    //gets any space token
    if(s.get_token(SPACES_STATE, token)) {
        t = Token(token, SPACES_STATE);
        return s;
    }

    //for debugging
    if(debug) {
        cout << "-----\nPUNCT STATE\n-----" << endl;
    }
    //gets any punctuation token
    if(s.get_token(PUNCT_STATE, token)) {
        t = Token(token, PUNCT_STATE);
        return s;
    }

    //otherwise increment to the next position
    else {
        t = Token();
        s._pos++;
        return s;
    }
}

// set_string : resets new character array without creating a new STokenizer
// object
/**********************************************************
*
*  set_string(): Class STokenizer
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (char) :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void STokenizer::set_string(char str[])
{
    int index = 0;  // initialize index for traversing through char array

    while(str[index] > -1 && str[index] != '\0')
    {
        _buffer[index] = str[index];
        index++;
    }
    _buffer[index] = '\0';  // set end of last index to null
}

// create table for all the tokens we will recognize
//                      (e.g. doubles, words, etc.)
/**********************************************************
*
*  make_table(): Class STokenizer
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    const bool debug = false;  //for debugging

    init_table(_table);  // initialize table

    // set double table
    mark_fail(_table, 0);
    mark_success(_table, 1);
    mark_fail(_table, 2);
    mark_success(_table, 3);

    mark_cells(0, _table, DIGITS, 1);    // state [0] --- DIGITS ---> [1]
    mark_cells(0, _table, '.', '.', 2);  // state [0] --- '.' ------> [2]
    mark_cells(1, _table, DIGITS, 1);    // state [1] --- DIGITS ---> [1]
    mark_cells(1, _table, '.', '.', 2);  // state [1] --- '.' ------> [2]
    mark_cells(2, _table, DIGITS, 3);    // state [2] --- DIGITS ---> [3]
    mark_cells(3, _table, DIGITS, 3);    // state [3] --- DIGITS ---> [3]

    // set alpha table
    mark_fail(_table, 10);
    mark_success(_table, 11);

    mark_cells(10, _table, ALPHA, 11);  // state [10] --- ALPHA ---> [11]
    mark_cells(11, _table, ALPHA, 11);  // state [11] --- ALPHA ---> [12]

    // set punctuation table
    mark_fail(_table, 20);
    mark_success(_table, 21);

    mark_cells(20, _table, PUNCT, 21);  // state [20] --- ALPHA ---> [21]
    mark_cells(21, _table, PUNCT, 21);  // state [21] --- ALPHA ---> [22]

    // set space table
    mark_fail(_table, 25);
    mark_success(_table, 26);

    mark_cells(25, _table, SPACES, 26);  // state [25] --- ALPHA ---> [26]
    mark_cells(26, _table, SPACES, 26);  // state [26] --- ALPHA ---> [26]

    if(debug) {
        print_table(_table);
    }
}

// return true if a token was found that was accepted by the machine starting at
// given state
bool STokenizer::get_token(int start_state, string& token)
{
    int current_state = start_state;
    int next_state = 0;
    int old_pos = _pos;
    const bool debug = false;

    if(debug) {
        cout << "START GET TOKEN" << endl;
        cout << "pos = " << _pos << endl;
    }

    while(_table[current_state][_buffer[_pos]] != -1 && _buffer[_pos] != '\0' &&
          _buffer[_pos] > -1)
    {
        if(debug) {
            cout << "----" << endl << endl;
            cout << "buffer: " << _buffer[_pos] << endl;
            cout << "char int: " << static_cast<int>(_buffer[_pos]) << endl;
            cout << "table: " << _table[current_state][_buffer[_pos]] << endl;
            cout << "next_state: " << next_state << endl;
        }

        next_state = _table[current_state][_buffer[_pos]];
        token = token + _buffer[_pos];
        if(debug) {
            cout << "pos = " << _pos << endl;
            cout << "token = " << token << endl;
        }
        current_state = next_state;
        _pos++;
    }

    //
    if(is_success(_table, next_state))
    {
        if(debug) {
            cout << "\nsuccess" << endl;
            cout << "pos: " << _pos << endl;
        }

        return true;
    }
    else
    {
        token = "";
        _pos = old_pos;
    }

    if(debug) {
        cout << "\nfail" << endl;
        cout << "pos: " << _pos << endl;
        cout << "END GET TOKEN" << endl << endl;
    }

    return false;

    // return true if a token was found, false otherwise
    //    if()
    // pos will point to the next char to be processed if returning true
    // pos will be unchanged if returning false
    // if a succcess state was encountered while transitioning from
    // state-to-state, determining pos and token
}
