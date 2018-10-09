#include "stokenizer.h"
#include <iostream>
#include <cstring>

// Global
int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

using namespace std;


/**********************************************************
*
*  STokenizer(): STokenizer Class
*  _________________________________________________________
*  This constructor initializes the position to 0, buffer to null
*    and creates the state table
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  This constructor initializes the position to 0, buffer to null
*    and creates the state table
***********************************************************/
STokenizer::STokenizer()
{
    _pos = 0;              //initialize position to 0
    _buffer[_pos] = '\0';  //initialize buffer to null
    make_table(_table);    //set adjancency table with states
}

/**********************************************************
*
*  STokenizer(): STokenizer Class
*  _________________________________________________________
*  This constructor initializes the position to 0, buffer to null
*    and creates the state table
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (char) : character array
*
*  POST-CONDITIONS
*  This constructor initializes the position to 0, buffer to null
*    and creates the state table
***********************************************************/
STokenizer::STokenizer(char str[])
{
    _pos = 0;  //initialize position to 0

    //copy character array input to buffer item by item
    while (str[_pos] != '\0')
    {
        assert(str[_pos] != '\0');
        _buffer[_pos] = str[_pos];  //copy item by item
        _pos++;  //increment position by 1
    }
    _buffer[_pos] = '\0'; //point last position in character array to null

    make_table(_table);  //set adjancency table with states
    _pos = 0;  //reset position to 0
}

/**********************************************************
*
*  done(): STokenizer Class
*  _________________________________________________________
*  This function checks to see if end of the character array
*    is reached (null) and there are no more tokens
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  If the position + 1 is the end of the character array (null),
*    then returns true. Otherwise, returns false.
***********************************************************/
bool STokenizer::done()
{
    //check if second to last position is null, since char array last character
    //should always be null
    if (_buffer[_pos + 1] == '\0')
    {
        assert(_buffer[_pos + 1] != '\0');
        return true;
    }

    return false;
}

/**********************************************************
*
*  more(): STokenizer Class
*  _________________________________________________________
*  This function checks to see if there are more tokens
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  If the position is less than the length of the buffer,
*    then there are more tokens, so returns true. Otherwise, returns false.
***********************************************************/
bool STokenizer::more()
{
    const int SIZE = strlen(_buffer);
    return _pos <= SIZE;
}

//
/**********************************************************
*
*  operator>>(): STokenizer Class
*  _________________________________________________________
*  This overloaded operator extracts one token (very similar
*    to the way cin >> works)
*  _________________________________________________________
*  PRE-CONDITIONS
*  s (STokenizer) : STokenizer object
*  t (Token)      : Token object
*
*  POST-CONDITIONS
*  This overloaded operator extracts one token (very similar
*    to the way cin >> works) and returns s
***********************************************************/
STokenizer &operator>>(STokenizer &s, Token &t)
{
    const bool debug = false;  //for turning on/off debugging
    //for debugging
    if (debug)
    {
        cout << "in operaor>>" << endl;
        cout << ">> _pos: " << s._pos << endl;
    }

    int DIGITS_STATE = 0;                //initial state for DIGITS
    int CARRIAGE_RETURN_STATE = 14;      //initial state for CARRIAGE RETURN
    int TAB_STATE = 17;                  //initial state for TAB
    int ALPHA_STATE = 10;                //initial state for ALPHA
    int PUNCT_STATE = 20;                //initial state for PUNCT
    int SPACES_STATE = 25;               //initial state for SPACES

    string token = "";                   //initialize token string to empty string

    //for debugging
    if (debug)
    {
        cout << "-----\nDIGITS STATE\n-----" << endl;
    }

    //creates DIGITS token if true
    if (s.get_token(DIGITS_STATE, token))
    {
        t = Token(token, DIGITS_STATE);
        if (debug)
        {
            cout << "DIGITS token created " << t.token_str() << endl;
        }
        return s;
    }

    //for debugging
    if (debug)
    {
        cout << "-----\nALPHA STATE\n-----" << endl;
    }

    //creates ALPHA token if true
    if (s.get_token(ALPHA_STATE, token))
    {
        t = Token(token, ALPHA_STATE);

        //for debugging
        if (debug)
        {
            cout << "ALPHA token created " << t.token_str() << endl;
        }
        return s;
    }

    //for debugging
    if (debug)
    {
        cout << "-----\nSPACE STATE\n-----" << endl;
    }

    //creates SPACES token if true
    if (s.get_token(SPACES_STATE, token))
    {
        t = Token(token, SPACES_STATE);

        //for debugging
        if (debug)
        {
            cout << "SPACES token created " << t.token_str() << endl;
        }
        return s;
    }

    //for debugging
    if (debug)
    {
        cout << "-----\nCARRIAGE RETURN STATE\n-----" << endl;
    }
    if (s.get_token(CARRIAGE_RETURN_STATE, token))
    {
        t = Token(token, CARRIAGE_RETURN_STATE);

        //for debugging
        if (debug)
        {
            cout << "CARRIAGE RETURN token created " << t.token_str() << endl;
        }
        return s;
    }

    //for debugging
    if (debug)
    {
        cout << "-----\nTAB STATE\n-----" << endl;
    }
    if (s.get_token(TAB_STATE, token))
    {
        t = Token(token, TAB_STATE);

        //for debugging
        if (debug)
        {
            cout << "TAB token created " << t.token_str() << endl;
        }
        return s;
    }

    //for debugging
    if (debug)
    {
        cout << "-----\nPUNCT STATE\n-----" << endl;
    }
    if (s.get_token(PUNCT_STATE, token))
    {
        t = Token(token, PUNCT_STATE);

        //for debugging
        if (debug)
        {
            cout << "PUNCT token created " << t.token_str() << endl;
        }
        return s;
    }

    else
    {
        //for debugging
        if (debug)
        {
            cout << "-----\nELSE STATE\n-----" << endl;
        }

        string str(1, s._buffer[s._pos]);  //converts one copy of buffer to string

        t = Token(str, -1);  //accounts for unknown characters

        //for debugging
        if (debug)
        {
            cout << "ELSE token created " << t.token_str() << endl;
        }
        s._pos++;
        return s;
    }
}

/**********************************************************
*
*  set_string(): STokenizer Class
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  str[] (char) :
*
*  POST-CONDITIONS
*  This function resets new character array without creating a new STokenizer
*    object
***********************************************************/
void STokenizer::set_string(char str[])
{
    int index = 0; // initialize index for traversing through char array

    //copy new character array to buffer if end of str has not been reached
    //and is still inbounds
    while (str[index] != '\0')
    {
        _buffer[index] = str[index];  //copy over item by item
        index++;  //increment index
    }
    _buffer[index] = '\0'; // set end of last index to null
    _pos = 0;  //reset position to 0
}

/**********************************************************
*
*  make_table(): STokenizer Class
*  _________________________________________________________
*  This method creates a table for all the tokens we will recognize
*     (e.g. doubles, words, etc.)
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*
*  POST-CONDITIONS
*  This function creates a table for all the tokens we will recognize
*     (e.g. doubles, words, etc.). Returns nothing.
***********************************************************/
void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
    const bool debug = false;  //for debugging

    init_table(_table); //initialize table to -1

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

    // set carriage return table
    mark_fail(_table, 14);
    mark_success(_table, 15);

    mark_cells(14, _table, CARRIAGE_RETURN, 15); // state [14] --- CARRIAGE RETURN ---> [15]
    mark_cells(15, _table, CARRIAGE_RETURN, 15); // state [15] --- CARRIAGE RETURN ---> [15]

    // set carriage return table
    mark_fail(_table, 17);
    mark_success(_table, 18);

    mark_cells(17, _table, TAB, 18); // state [17] --- TAB---> [18]
    mark_cells(18, _table, TAB, 18); // state [18] --- TAB ---> [18]

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

    //for debugging
    if (debug) {
        print_table(_table);
    }
}

/**********************************************************
*
*  get_token(): STokenizer Class
*  _________________________________________________________
*  This method checks if a token was found that was accepted by the machine
*    starting at a given state.
*  _________________________________________________________
*  PRE-CONDITIONS
*  start_state (int) : integer tracking where to start state
*  token (string)    : string of characters in a given state, passed by ref
*
*  POST-CONDITIONS
*  If a token was found, returns true. Else, returns false.
***********************************************************/
bool STokenizer::get_token(int start_state, string &token)
{
    int current_state = start_state;  //tracks current state
    int next_state = 0;               //tracks next state after current state
    int old_pos = _pos;               //tracks previous position
    const bool debug = false;         //turn on/off for debugging

    //for debugging
    if (debug) {
        cout << "START GET TOKEN" << endl;
        cout << "pos = " << _pos << endl;
    }

    while (_table[current_state][_buffer[_pos]] != -1 && _buffer[_pos] != '\0' &&
           _buffer[_pos] > -1)
    {
        //for debugging
        if (debug) {
            cout << "----" << endl
                 << endl;
            cout << "buffer: " << _buffer[_pos] << endl;
            cout << "char int: " << static_cast<int>(_buffer[_pos]) << endl;
            cout << "table: " << _table[current_state][_buffer[_pos]] << endl;
            cout << "next_state: " << next_state << endl;
        }

        //use current state and buffer character to locate next state in table
        next_state = _table[current_state][_buffer[_pos]];
        //add accepted buffer character to token
        token = token + _buffer[_pos];

        //for debugging
        if (debug) {
            cout << "pos = " << _pos << endl;
            cout << "token = " << token << endl;
        }

        current_state = next_state;  //move current state to the next state
        _pos++;                      //increment position by 1
    }

    //returns true if a token was created successfully
    if (is_success(_table, next_state))
    {
        //for debugging
        if (debug) {
            cout << "\nsuccess" << endl;
            cout << "pos: " << _pos << endl;
        }

        return true;
    }

    //resets token to empty string and position back to old position if token
    //was not successfully created, then returns false
    else
    {
        token = "";
        _pos = old_pos;
    }

    //for debugging
    if (debug) {
        cout << "\nfail" << endl;
        cout << "pos: " << _pos << endl;
        cout << "END GET TOKEN" << endl
             << endl;
    }

    return false;

}
