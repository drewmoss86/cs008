/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/5/2018
 *
 * Assignment: Stack and Queue
 *
 *****************************************/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "list.h"

using namespace std;

template <class T>
class Stack
{
public:
    //default constructor: initializes top
    Stack():_top(NULL){}

    //destructor: deallocates object
    ~Stack()
    {
        //deletes all nodes
        delete_all(_top);
    }
    //copy constructor: assumes object is empty list
    Stack(const Stack<T>& other)
    {
        //initialize _top of new list
        init_head(_top);
        //deep copy of each node
        copy_list(other._top, _top);

    }
    //assignment operator: checks whether or not object has already been assigned
    //if so, return object as is otherwise, make copy
    Stack<T>& operator =(const Stack<T>& rhs)
    {
        if(this != &rhs)
        {
            //initialize _top of new list
            init_head(_top);
            //deep copy of each node
            copy_list(rhs._top, _top);
        }

        return *this;
    }

    //add node to list from the head or top of list
    void push(T item)
    {
        insert_head(_top, item);
    }
    //return item at top of list
    T top()
    {
        if(!empty())
        {
            return _top->_item;
        }
    }

    //delete each node starting at the head
    T pop()
    {
        if(!empty())
        {
            delete_head(_top);
        }
    }
    bool empty()
    {
        if(_top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator << (ostream& outs, const Stack& s)
    {
        return print_list(s._top, outs);
    }
private:
    node<T>* _top;
};
#endif // STACK_H
