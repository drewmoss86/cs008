#include "stokenizer.h"
#include <iostream>
#include <cstring>

// Global
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

using namespace std;


/**********************************************************
*
*  STokenizer(): STOkenizer Runway
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
*  STokenizer(): STokenizer Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (int) :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
STokenizer::STokenizer(char str[])
{
    _pos = 0;
    while (str[_pos] != '\0')
    {
        assert(str[_pos] != '\0');
        _buffer[_pos] = str[_pos];
        _pos++;
    }
    _buffer[_pos] = '\0';

    make_table(_table);
    _pos = 0;
}
// true: there are no more tokens
/**********************************************************
*
*  done(): STokenizer Runway
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
bool STokenizer::done()
{
    if (_buffer[_pos + 1] == '\0')
    {
        assert(_buffer[_pos] == '\0');
        return true;
    }

    return false;
}
// true: there are more tokens
/**********************************************************
*
*  more(): STokenizer Runway
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
    return _pos <= strlen(_buffer);
}

// extract one token (very similar to the way cin >> works)
/**********************************************************
*
*  operator>>(): STokenizer Runway
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
STokenizer &operator>>(STokenizer &s, Token &t)
{
    const bool debug = false;
    if (debug)
    {
        cout << "in operaor>>" << endl;
        cout << ">> _pos: " << s._pos << endl;
    }

    int DIGITS_STATE = 0;
    int ALPHA_STATE = 10;
    int PUNCT_STATE = 20;
    int SPACES_STATE = 25;

    string token = "";

    if (debug)
    {
        cout << "-----\nDIGITS STATE\n-----" << endl;
    }
    if (s.get_token(DIGITS_STATE, token))
    {
        t = Token(token, DIGITS_STATE);
        if (debug)
        {
            cout << "DIGITS token created " << t.token_str() << endl;
        }
        return s;
    }

    if (debug)
    {
        cout << "-----\nALPHA STATE\n-----" << endl;
    }
    if (s.get_token(ALPHA_STATE, token))
    {
        t = Token(token, ALPHA_STATE);
        if (debug)
        {
            cout << "ALPHA token created " << t.token_str() << endl;
        }
        return s;
    }

    if (debug)
    {
        cout << "-----\nSPACE STATE\n-----" << endl;
    }
    if (s.get_token(SPACES_STATE, token))
    {
        t = Token(token, SPACES_STATE);
        if (debug)
        {
            cout << "SPACES token created " << t.token_str() << endl;
        }
        return s;
    }

    if (debug)
    {
        cout << "-----\nPUNCT STATE\n-----" << endl;
    }
    if (s.get_token(PUNCT_STATE, token))
    {
        t = Token(token, PUNCT_STATE);
        if (debug)
        {
            cout << "PUNCT token created " << t.token_str() << endl;
        }
        return s;
    }

    else
    {
        string str(1, s._buffer[s._pos]);  //converts one copy of buffer to string
        t = Token(str, -1);  //for unk characters
        if (debug)
        {
            cout << "ELSE token created " << t.token_str() << endl;
        }
        s._pos++;
        return s;
    }
}

// set_string : resets new character array without creating a new STokenizer
// object
/**********************************************************
*
*  set_string(): STokenizer Runway
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
    int index = 0; // initialize index for traversing through char array

    while (str[index] > -1 && str[index] != '\0')
    {
        _buffer[index] = str[index];
        index++;
    }
    _buffer[index] = '\0'; // set end of last index to null
    _pos = 0;
}

// create table for all the tokens we will recognize
//                      (e.g. doubles, words, etc.)
void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    const bool debug = false;

    init_table(_table); // initialize table

    // set double table
    mark_fail(_table, 0);
    mark_success(_table, 1);
    mark_fail(_table, 2);
    mark_success(_table, 3);

    mark_cells(0, _table, DIGITS, 1);   // state [0] --- DIGITS ---> [1]
    mark_cells(0, _table, '.', '.', 2); // state [0] --- '.' ------> [2]
    mark_cells(1, _table, DIGITS, 1);   // state [1] --- DIGITS ---> [1]
    mark_cells(1, _table, '.', '.', 2); // state [1] --- '.' ------> [2]
    mark_cells(2, _table, DIGITS, 3);   // state [2] --- DIGITS ---> [3]
    mark_cells(3, _table, DIGITS, 3);   // state [3] --- DIGITS ---> [3]

    // set alpha table
    mark_fail(_table, 10);
    mark_success(_table, 11);

    mark_cells(10, _table, ALPHA, 11); // state [10] --- ALPHA ---> [11]
    mark_cells(11, _table, ALPHA, 11); // state [11] --- ALPHA ---> [12]

    // set punctuation table
    mark_fail(_table, 20);
    mark_success(_table, 21);

    mark_cells(20, _table, PUNCT, 21); // state [20] --- ALPHA ---> [21]
    mark_cells(21, _table, PUNCT, 21); // state [21] --- ALPHA ---> [22]

    // set space table
    mark_fail(_table, 25);
    mark_success(_table, 26);

    mark_cells(25, _table, SPACES, 26); // state [25] --- ALPHA ---> [26]
    mark_cells(26, _table, SPACES, 26); // state [26] --- ALPHA ---> [26]

    if (debug)
    {
        print_table(_table);
    }
}

// return true if a token was found that was accepted by the machine starting at
// given state
/**********************************************************
*
*  get_token(): STokenizer Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  start_state (int) :
*  token (string)    :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
bool STokenizer::get_token(int start_state, string &token)
{
    int current_state = start_state;
    int next_state = 0;
    int old_pos = _pos;
    const bool debug = false;

    if (debug)
    {
        cout << "START GET TOKEN" << endl;
        cout << "pos = " << _pos << endl;
    }

    while (_table[current_state][_buffer[_pos]] != -1 && _buffer[_pos] != '\0' &&
           _buffer[_pos] > -1)
    {
        if (debug)
        {
            cout << "----" << endl
                 << endl;
            cout << "buffer: " << _buffer[_pos] << endl;
            cout << "char int: " << static_cast<int>(_buffer[_pos]) << endl;
            cout << "table: " << _table[current_state][_buffer[_pos]] << endl;
            cout << "next_state: " << next_state << endl;
        }

        next_state = _table[current_state][_buffer[_pos]];
        token = token + _buffer[_pos];
        if (debug)
        {
            cout << "pos = " << _pos << endl;
            cout << "token = " << token << endl;
        }
        current_state = next_state;
        _pos++;
    }

    if (is_success(_table, next_state))
    {
        if (debug)
        {
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

    if (debug)
    {
        cout << "\nfail" << endl;
        cout << "pos: " << _pos << endl;
        cout << "END GET TOKEN" << endl
             << endl;
    }

    return false;

    // return true if a token was found, false otherwise
    //    if()
    // pos will point to the next char to be processed if returning true
    // pos will be unchanged if returning false
    // if a succcess state was encountered while transitioning from
    // state-to-state, determining pos and token
}
