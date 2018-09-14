#ifndef STATE_MACHINES_H
#define STATE_MACHINES_H

#include <iostream>
#include "state_machine_functions.h"
#include "constants.h"

using namespace std;

void doubleStateMachine(int _table[][MAX_COLUMNS], int state)
{
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
}
#endif // STATE_MACHINES_H
