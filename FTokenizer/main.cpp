/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/24/2018
 *
 * Class: CS 008
 *
 * Assignment: FTokenizer
 *
 ******************************************/
#include <iostream>
#include "ftokenizer.h"


using namespace std;
//proto
void test_f_tokenize_simple();

int main()
{
    test_f_tokenize_simple();

    return 0;
}
void test_f_tokenize_simple(){
    ofstream outFile;
    Token t;

    outFile.open("tokenOutput.txt");
    FTokenizer ftk("solitude.txt");
    ftk>>t;
    int token_count = 0;
    while (ftk.more()){
        if (t.type_string()=="ALPHA" ){
            token_count++;
            outFile <<setw(10)<<token_count
                    <<setw(3)<<left<<":"<<setw(25)<<left<<t.token_str()
                    <<t.type_string()<<endl;
        }
        ftk>>t;
    }
    cout<<"Tokens Found: "<<token_count<<endl;
    cout<<"=========="<<endl;


}
