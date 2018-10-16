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
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>

using namespace std;

//character array with corresponding values representing states

//alpha state - includes alphabet upper and lower case
const char ALPHA[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//digit/number state - 0 through 9
const char DIGITS[] = "0123456789";
//punctuation state (minus '@' and '&' to test unknown)
const char PUNCT[] = "!\"$%&#\'()*+,-./:;<=>?@[\\]^_`{|}~";
//spaces state - single space
const char SPACES[] = " ";
//carriage return state - newline and carriage return
const char CARRIAGE_RETURN[] = "\n\r";
//tab state - horizontal and vertical tab
const char TAB[] = "\t\v";

#endif // CONSTANTS_H
