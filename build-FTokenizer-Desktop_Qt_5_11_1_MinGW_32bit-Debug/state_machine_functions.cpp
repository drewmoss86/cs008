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
*  init_table(): Token Class
*  _________________________________________________________
*  This method initializes the table values to -1
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*
*  POST-CONDITIONS
*  This function sets all the values in the 2D array to -1. Returns nothing.
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

/**********************************************************
*
*  mark_success(): Token Class
*  _________________________________________________________
*  This method marks the successful rows with a 1 (success)
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function mark this state (row) with a 1 (success). Returns nothing.
***********************************************************/
void mark_success(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 1;

}

//
/**********************************************************
*
*  mark_fail(): Token Class
*  _________________________________________________________
*  This method marks the fail rows with a 0 (fail)
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function mark this state (row) with a 0 (fail). Returns nothing.
***********************************************************/
void mark_fail(int _table[][MAX_COLUMNS], int state)
{
    _table[state][0] = 0;

}

/**********************************************************
*
*  is_success(): Token Class
*  _________________________________________________________
*  This method checks column 0 to find if state is success or fail
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function returns true if state is a success state, else false.
***********************************************************/
bool is_success(int _table[][MAX_COLUMNS], int state)
{
    if(_table[state][0] == 1)
    {
        return true;
    }
    return false;
}

/**********************************************************
*
*  mark_cells(): Token Class
*  _________________________________________________________
*  This method initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   : integer representing the row in the table
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  from (int)                  : integer starting column
*  to (int)                    : integer ending column
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function marks a range of cells in the array. Returns nothing.
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
*  mark_cells(): Token Class
*  _________________________________________________________
*  This constructor initializes the landing time, landing time left,
*     takeoff time, takeoff time left
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   : integer representing the row in the table
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  columns (const char)        : char array containing the values for each state
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function initializes landing time to t and takeoff time to t.
*     landing time left and takeoff time left to 0
***********************************************************/
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    int index = 0;
    while(columns[index] != '\0')
    {
        _table[row][columns[index]] = state;
        index++;

    }
}

//
/**********************************************************
*
*  mark_cell(): Token Class
*  _________________________________________________________
*  This method marks a cell with a state value
*  _________________________________________________________
*  PRE-CONDITIONS
*  row (int)                   : integer representing the row in the table
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*  column (int)                : integer representing the column in the table
*  state (int)                 : integer value representing the respective state
*
*  POST-CONDITIONS
*  This function marks this row and column (cell) with a state value. Returns
*    nothing.
***********************************************************/
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state)
{
    _table[row][column] = state;
}

/**********************************************************
*
*  print_table(): Token Class
*  _________________________________________________________
*  This method prints all the values of the 2D array (adjacency table)
*  _________________________________________________________
*  PRE-CONDITIONS
*  _table[][MAX_COLUMNS] (int) : 2D array of integers
*
*  POST-CONDITIONS
*  This function prints all the values of the 2D array (adjacency table).
*    This can realistically be used on a small table. Returns nothing.
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

/**********************************************************
*
*  show_string(): Token Class
*  _________________________________________________________
*  This method show string s and mark this position on the string
*  _________________________________________________________
*  PRE-CONDITIONS
*  s[] (char) : character array
*  _pos (int) : representing position of the character array
*
*  POST-CONDITIONS
*  This function shows string s and mark this position on the string
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
