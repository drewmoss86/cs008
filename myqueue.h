#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "list.h"
using namespace std;

template <class T>
class myQueue{
public:
    myQueue():_head(NULL), _tail(NULL){}

    ~myQueue()
    {
        delete_all(_head);
        _tail = _head;
    }
    //copy constructor: assumes object is empty list
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

//        else
//        {
//            node<T>* newNode = new node<T>(item);
//            _tail->_next = newNode;
//            _tail = _tail->_next;
//        }

        else
        {
            insert_after(_head, _tail, item);
            _tail = _tail->_next;
        }
    }
    //deletes node starting at head of list
    T pop()
    {
        delete_head(_head);
    }
    //returns true if _head pointer is poiting to NULL, otherwise false
    bool empty()
    {
        if(_head == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }

    }
    //returns item at head of list
    T front()
    {
        return _head->_item;
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
