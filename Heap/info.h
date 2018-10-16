/******************************************
 * Name: Andrew Moss
 *
 * Date: 10/15/2018
 *
 * Class: CS 008
 *
 * Assignment: Priority Queue
 *
 ******************************************/
#ifndef INFO_H
#define INFO_H
#include <iostream>

template <typename T>
struct info{
    T item;
    int priority;

    info()
    {
        T item{};
        priority = 0;
    }
    info(T i, int p)
    {
        item = i;
        priority = p;
    }

    friend std::ostream& operator <<(std::ostream& outs, const info<T>& print_me)
    {
        outs << "item: " << "|" << print_me.item << "|" << "pr: " << print_me.priority << std::endl;

        return outs;
    }

    friend bool operator <=(const info<T>& lhs, const info<T>& rhs)
    {
        return lhs.priority <= rhs.priority;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs)
    {
        return lhs.priority < rhs.priority;
    }
    friend bool operator >=(const info<T>& lhs, const info<T>& rhs)
    {
        return lhs.priority >= rhs.priority;
    }
    friend bool operator >(const info<T>& lhs, const info<T>& rhs)
    {
        return lhs.priority > rhs.priority;
    }

};
#endif // INFO_H
