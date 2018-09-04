#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "list.h"

using namespace std;

template <class T>
class Stack
{
public:
    Stack():_top(NULL){}

    ~Stack()
    {
        //deletes all nodes
        delete_all(_top);
    }
    Stack(const Stack<T>& other)
    {
        //initialize _top of new list
        init_head(_top);
        //deep copy of each node
        copy_list(other._top, _top);

    }
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

    void push(T item)
    {
        //insert node at head
        insert_head(_top, item);
    }
    T top()
    {
        return _top->_item;
    }

    T pop()
    {
        //delete each node starting at the head
        delete_head(_top);
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
