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
    myQueue(const myQueue<T>& other)
    {
        init_head(_head);
        copy_list(other._head, _head);

    }
    myQueue<T> &operator =(const myQueue& rhs)
    {
        if(this != &rhs)
        {
            init_head(_head);
            copy_list(rhs._head, _head);
        }

        return *this;

    }

    void push(T item)
    {
//        if(_head == NULL)
//        {
//            insert_head(_head, item);
//            _tail = _head;
//        }

//        else
//        {
//            node<T>* newNode = new node<T>(item);
//            _tail->_next = newNode;
//            _tail = _tail->_next;
//        }

        insert_after(_head, _tail, item);
    }
    T pop()
    {
        delete_head(_head);
    }
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
