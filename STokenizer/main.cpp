#include <iostream>
#include <cstring>
//#include "token.h"
#include "state_machine_functions.h"
#include "constants.h"
//#include "stokenizer.h"

using namespace std;
//const int SIZE = 100;

//bool get_token(char block[], int _table[][MAX_COLUMNS], int &pos, string &token, int start_state);
int main()
{
//    char cSentence[SIZE];
//    string sentence = "3.14";
//    strcpy(cSentence, sentence.c_str());
//    int n = 0;

    int state_table[MAX_ROWS][MAX_COLUMNS];

    init_table(state_table);

    //doubles
    mark_fail(state_table,0);
    mark_success(state_table,1);
    mark_fail(state_table, 2);
    mark_success(state_table,3);

    mark_cells(0, state_table, DIGITS, 1);


    print_table(state_table);

//    get_token(cSentence, table, n, sentence, 0);

    return 0;
}


//bool get_token(char block[], int _table[][MAX_COLUMNS], int &pos, string &token, int start_state)
//{
//    if(start_state != -1)
//    {
//        char ch;
//        while(block[pos] != '\0')
//        {

//            ch = block[pos];
//            cout << "Char: " << ch << ' ' << _table[start_state][ch] << endl;
//            token = token + ch;

//            pos++;
//            start_state++;
//        }

//        return true;

//    }

//    return false;

//}
