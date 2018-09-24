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
#include "ftokenizer.h"

/**********************************************************
*
*  FTokenizer(): FTokenizer Class
*  _________________________________________________________
*  This constructor
*  _________________________________________________________
*  PRE-CONDITIONS
*  fname (char)   : character array storing the filename to be read
*
*  POST-CONDITIONS
*  Returns nothing
***********************************************************/
FTokenizer::FTokenizer(char* fname)
{
    _more = false;       //initialize boolean value
    _pos = 0;            //initialize integer tracking file position
    _blockPos = 0;       //initialize integer tracking block position
    bool debug = false;  //for debugging

    //open file
    _f.open(fname);

    //check if file is open
    if(debug) {
        if(!_f) {
            cout << "Cannot open file!" << endl;
            exit(0);
        } else {
            cout << "File Opened!" << endl;
        }
    }

}

/**********************************************************
*
*  ~FTokenizer(): FTokenizer Class
*  _________________________________________________________
*  This destructor closes the file
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns nothing.
***********************************************************/
FTokenizer::~FTokenizer()
{
    _f.close();
}

/**********************************************************
*
*  get_new_block(): FTokenizer Class
*  _________________________________________________________
*  This method gets the new block from the file
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns true if there are still character blocks left to read, otherwise,
*    returns false
***********************************************************/
bool FTokenizer::get_new_block()
{
    bool debug = false;  //bool value for turning debugging on/off

    char * block = new char[MAX_BLOCK];

    _f.read(block,MAX_BLOCK - 1); //read data as a block
    block[_f.gcount()] = '\0';    //set end of buffer to null


    //for debugging - displays blocks
    if(debug) {
        cout << block;
        cout << endl;
    }

    //if count of characters read is greater than 0
    if(_f.gcount() > 0)
    {
        _pos += _f.gcount();    //update file position
        _stk.set_string(block); //set block into stokenizern
        delete[] block;         //deallocate character array representing block

    }

    //for debugging - prints stokenized version of block
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

    return false;

}

/**********************************************************
*
*  next_token(): FTokenizer Class
*  _________________________________________________________
*  This method gets the new block from the file
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns next token in block
***********************************************************/
Token FTokenizer::next_token()
{
    Token t;
    _stk >> t;

    //when stk is done then grab new block assign more to true
    if(!_stk.more())
    {
        _more = get_new_block();
        _stk >> t;
    }

    return t;

}

/**********************************************************
*
*  more(): FTokenizer Class
*  _________________________________________________________
*  This method returns the current value of _more
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns more as false end of stk is reached, otherwise, true
***********************************************************/
bool FTokenizer::more()
{
    //if there's more string values to be tokenize, assign true to more
    if(_stk.more())
    {
        _more = true;
    }

    return _more;

}

/**********************************************************
*
*  pos(): FTokenizer Class
*  _________________________________________________________
*  This method returns the value of _pos - current position in file
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns the value of _pos
***********************************************************/
int FTokenizer::pos()
{
    return _pos;
}

/**********************************************************
*
*  block_pos(): FTokenizer Class
*  _________________________________________________________
*  This method returns the value of _blockPos - current position in
*    the block of characters that has been read
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns the value of _blockPos
***********************************************************/
int FTokenizer::block_pos()
{
    return _blockPos;
}

/**********************************************************
*
*  operator>>(): FTokenizer Class
*  _________________________________________________________
*  This method returns the value of _blockPos - current position in
*    the block of characters that has been read
*  _________________________________________________________
*  PRE-CONDITIONS
*  f (FTokenizer) :
*  t (Token)      : Token object to be assigned the next token
*
*  POST-CONDITIONS
*  Returns the FTokenizer object
***********************************************************/
FTokenizer& operator >> (FTokenizer& f, Token& t)
{
    t = f.next_token();
    return f;
}
