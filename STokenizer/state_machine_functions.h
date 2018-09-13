#ifndef STATE_MACHINE_FUNCTIONS_H
#define STATE_MACHINE_FUNCTIONS_H
#include <iostream>

using namespace std;

//Global
const int MAX_ROWS = 30;
const int MAX_COLUMNS = 256;

//Fill all cells of the array with -1
void init_table(int _table[][MAX_COLUMNS])
{
    for(unsigned int i = 0; i < MAX_ROWS; i++)
    {
        for(unsigned int j = 0; j < MAX_COLUMNS; j++)
        {
            _table[i][j] = -1;
        }
    }
}

//Mark this state (row) with a 1 (success)
void mark_success(int _table[][MAX_COLUMNS], int state)
{
    for(unsigned int j = 0; j < MAX_COLUMNS; j++)
    {
        _table[state][j] = 1;
    }
}

//Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state)
{
    for(unsigned int j = 0; j < MAX_COLUMNS; j++)
    {
        _table[state][j] = 0;
    }

}

//true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state)
{
    if(_table[state][0] == 1)
    {
        return true;
    }

    if(_table[state][0] == 0)
    {
        return false;
    }

}

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state)
{
    for(int i = from; i < to; i++)
    {
        _table[row][i] = state;
    }

}

//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state)
{
    int pos = 0;
    int ch = 0;
    while(columns[pos] != '\0')
    {
        ch = columns[pos];
        _table[row][ch] = state;
        pos++;

    }
}

//Mark this row and column
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state)
{
    _table[row][column] = state;
}

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS])
{
    for(unsigned i = 0; i < MAX_ROWS; i++)
    {
        for(unsigned j = 0; j < MAX_COLUMNS; j++)
        {
            cout << _table[i][j] << " ";
        }
        cout << endl;
    }
}

//show string s and mark this position on the string:
//hello world   pos: 7
//      ^
void show_string(char s[], int _pos)
{
    for(int i = _pos; i != ' '; i++)
    {
        cout << s[i] << endl;
    }
}

#endif // STATE_MACHINE_FUNCTIONS_H
