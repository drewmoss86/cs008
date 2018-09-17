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
#include <iomanip>
#include <iostream>
#include "stokenizer.h"

int main() {
    char s[] = "it was the night of october 17th. pi was still 3.14.";
//    char e[] = "";
    STokenizer stk(s);
    Token t;
    // The all too familiar golden while loop:
    stk >> t;
    while(stk.more()) {
        // process token here...
        cout << setw(10) << t.type_string() << setw(10) << t << endl;

        t = Token();
        stk >> t;
    }

    return 0;
}
