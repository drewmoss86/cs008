#include <iostream>
#include "stokenizer.h"


using namespace std;

STokenizer::STokenizer()
{
    _pos = 0;

}

STokenizer::STokenizer(char str[]){}

bool STokenizer::done(){}            //true: there are no more tokens
bool STokenizer::more(){}            //true: there are more tokens
//-- big three --

//---------------
//extract one token (very similar to the way cin >> works)
//friend STokenizer::STokenizer& operator >> (STokenizer& s, Token& t);

//set a new string as the input string
void set_string(char str[]);

//create table for all the tokens we will recognize
//                      (e.g. doubles, words, etc.)
void make_table(int _table[][MAX_COLUMNS])
{
    for(unsigned int i = 0; i < MAX_ROWS; i++)
    {
        for(unsigned int j = 0; j < MAX_COLUMNS; j++)
        {
//            _table[i][j] = ;
        }
    }
}

//return true if a token was found that was accepted by the machine starting at given state
bool STokenizer::get_token(int start_state, string& token)
{
    //return true if a token was found, false otherwise
//    if()
    //pos will point to the next char to be processed if returning true
    //pos will be unchanged if returning false
    //if a succcess state was encountered while transitioning from state-to-state, determining pos and token
}
