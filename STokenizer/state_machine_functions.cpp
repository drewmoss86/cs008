#include "state_machine_functions.h"

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
void mark_success(int _table[][MAX_COLUMNS], int state)
{
//    for(unsigned j = 0; j < MAX_COLUMNS; j++)
//    {
        _table[state][0] = 1;
//    }
}

//Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state)
{
//    for(unsigned j = 0; j < MAX_COLUMNS; j++)
//    {
        _table[state][0] = 0;
//    }
}

//true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state)
{
//    cout << "state: " << state << endl;
//    cout << _table[state][0] << endl;
    if(_table[state][0] == 1)
    {
//        cout << "true" << endl;
        return true;
    }
//    cout << "false" << endl;
    return false;
}

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state)
{
    for(int i = from; i <= to; i++)
    {
        _table[row][i] = state;
    }

}

//Mark columns represented by the string columns[] for this row
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
    string token;
    while(s[_pos] != '\0')
    {
        token = token + s[_pos];
        _pos++;
    }
    cout << token << " " << "pos: " << _pos << endl;
}
