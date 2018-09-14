#include <iostream>
#include <cstring>
#include <iomanip>
#include "token.h"
//#include "state_machine_functions.h"
#include "stokenizer.h"

using namespace std;

int main()
{
    char s[] = "it was the night of october 17th. pi was still 3.14.";
    STokenizer stk(s);
    Token t;


    //The all too familiar golden while loop:
    stk>>t;
    while(stk.more())
    {
     //process token here...
     cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;


     t = Token();
     stk>>t;
    }



    return 0;
}


