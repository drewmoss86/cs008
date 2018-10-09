/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/5/2018
 *
 * Assignment: Stack and Queue
 *
 *****************************************/
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "list.h"
using namespace std;

template <class T>
class myQueue{
public:
    //default constructor: initializes head and tail
    myQueue():_head(NULL), _tail(NULL){}

    //destructor: deallocates object
    ~myQueue()
    {
        delete_all(_head);
        _tail = _head;
    }
    //copy constructor: assumes object is empty list and makes copy of other list
    myQueue(const myQueue<T>& other)
    {
        init_head(_head);
        copy_list(other._head, _head);

    }
    //assignment operator: checks whether or not object has already been assigned
    //if so, return object as is otherwise, make copy
    myQueue<T> &operator =(const myQueue& rhs)
    {
        if(this != &rhs)
        {
            init_head(_head);
            copy_list(rhs._head, _head);
        }

        return *this;
    }

    //adds node at end of list
    void push(T item)
    {
        if(empty())
        {
            insert_head(_head, item);
            _tail = _head;
        }

        else
        {
            insert_after(_head, _tail, item);
            _tail = _tail->_next;
        }
    }

    //deletes node starting at head of list
    T pop()
    {
        if(!empty())
        {
            delete_head(_head);
        }

        return 0;
    }
    //returns true if _head pointer is poiting to NULL, otherwise false
    bool empty()
    {
        if(_head == NULL)
        {
            return true;
        }

        return false;

    }
    //returns item at head of list
    T front()
    {
        if(!empty())
        {
            return _head->_item;
        }

        return 0;
    }

    friend ostream& operator <<(ostream& outs, const myQueue& q)
    {
        return print_list(q._head, outs);

    }

private:
    node<T>* _head;
    node<T>* _tail;
};


#endif // MYQUEUE_H
