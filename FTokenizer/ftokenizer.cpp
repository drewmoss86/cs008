#include "ftokenizer.h"


FTokenizer::FTokenizer(char* fname)
{
    _more = true;
    _pos = 0;
    _blockPos = 0;
    //open file
    _f.open(fname);

    //check if file is open
    if(!_f)
    {
        cout << "Cannot open file!" << endl;
        exit(0);
    } else {
        cout << "File Opened!" << endl;
        //get length of file
        _f.seekg(0,_f.end);
        int length = _f.tellg();
        _f.seekg(0, _f.beg);

        cout << "Reading " << length << " characters... ";

        if (_f) {
          cout << "all characters read successfully." << endl;
        } else {
          cout << "error: only " << _f.gcount() << " could be read";
        }

        // ...buffer contains the entire file...
    }

}

FTokenizer::~FTokenizer()
{
    _f.close();
}

//gets the new block from the file
bool FTokenizer::get_new_block()
{
    bool debug = false;  //bool value for turning debugging on/off

    char * buffer = new char[MAX_BLOCK];
    if(!_f.eof())
    {

        // read data as a block:
        _f.read(buffer,MAX_BLOCK);

        //for debugging - grabs one block
        if(debug) {
            while(buffer[_pos+1] != '\0' && _pos <= MAX_BLOCK)
            {
                cout << buffer[_pos];
                _pos++;
            }
            cout << endl;
        }

        _stk.set_string(buffer);

        //for debugginer - prints stokenized version of block
        if(debug) {
            Token t;
            // The all too familiar golden while loop:
            _stk >> t;
            while(_stk.more())
            {
                // process token here...
                cout << setw(10) << t.type_string() << setw(10) << t << endl;

                t = Token();
                _stk >> t;
            }
        }

        return true;
    }

    return false;

}

Token FTokenizer::next_token()
{
    Token t;
    if(_stk.more() && get_new_block())
    {

       t = Token();

       _stk >> t;
    }

}

//returns the current value of _more
bool FTokenizer::more()
{
    return _more;
}

//returns the value of _pos
int FTokenizer::pos()
{
    return _pos;
}

//returns the value of _blockPos
int FTokenizer::block_pos()
{
    return _blockPos;

}
FTokenizer& operator >> (FTokenizer& f, Token& t)
{
    if(f.more())
    {
        t = Token();
        return f;
    }

}
