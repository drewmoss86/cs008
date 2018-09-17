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
#include "state_machine_functions.h"

/**********************************************************
*
*  init_table(): Token Runway
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
void init_table(int _table[][MAX_COLUMNS])
{
    for(unsigned i = 0; i < MAX_ROWS; i++)
    {
        for(unsigned j = 0; j < MAX_COLUMNS; j++)
        {
            _table[i][j] = -1;
        }
    }
}

//Mark this state (row) with a 1 (success)
/**********************************************************
*
*  mark_success(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_success(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 1;

}

//Mark this state (row) with a 0 (fail)
/**********************************************************
*
*  mark_fail(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_fail(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 0;

}

//true if state is a success state
/**********************************************************
*
*  is_success(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
bool is_success(int _table[][MAX_COLUMNS], int state)
{
    if(_table[state][0] == 1)
    {
        return true;
    }
    return false;
}

//Mark a range of cells in the array.
/**********************************************************
*
*  mark_cells(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   :
*  _table[][MAX_COLUMNS] (int) :
*  from (int)                  :
*  to (int)                    :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state)
{
    for(int i = from; i <= to; i++)
    {
        _table[row][i] = state;
    }

}

//Mark columns represented by the string columns[] for this row
/**********************************************************
*
*  mark_cells(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   :
*  _table[][MAX_COLUMNS] (int) :
*  columns (char)              :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    int index = 0;
    char ch = ' ';
    while(columns[index] != '\0')
    {
        ch = columns[index];
        _table[row][ch] = state;
        index++;

    }
}

//Mark this row and column
/**********************************************************
*
*  mark_cell(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   :
*  _table[][MAX_COLUMNS] (int) :
*  column (int)                :
*  state (int)                 :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state)
{
    _table[row][column] = state;
}

//This can realistically be used on a small table
/**********************************************************
*
*  print_table(): Token Runway
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
void print_table(int _table[][MAX_COLUMNS])
{
    for(unsigned i = 0; i < MAX_ROWS; i++)
    {
        for(unsigned j = 0; j < MAX_COLUMNS; j++)
        {
            cout << setw(5) << _table[i][j];
        }
        cout << endl;
    }
}

//show string s and mark this position on the string:
//hello world   pos: 7
//      ^
/**********************************************************
*
*  show_string(): Token Runway
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  s[] (int)  :
*  _pos (int) :
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void show_string(char s[], int _pos)
{
    string token;
    while(s[_pos] != '\0')
    {
        token = token + s[_pos];
        _pos++;
    }
    cout << token << " " << "pos: " << _pos << endl;
}
