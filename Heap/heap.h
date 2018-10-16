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
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cassert>
#include <iomanip>

#include "info.h"

template <typename T>
class Heap
{
public:
    Heap()
    {
        how_many = 0;
        arr = new T[500];
    }

//    Heap(const Heap<T>& copy_me)
//    {
////        assert(copy_me != this);

//        for(size_t i = 0; i < copy_me.size(); i++)
//        {
//            copy_me.arr[i] = arr[i];
//        }
//    }

//    Heap<T>& operator =(const Heap<T>& rhs)
//    {
////        assert(rhs != this);

//        for(size_t i = 0; i < rhs.size(); i++)
//        {
//            rhs.arr[i] = arr[i];
//        }
//    }

//    ~Heap()
//    {
//        while(how_many > 0)
//        {
//            Pop();
//            how_many--;
//        }
//    }
    void insert(const T& insert_me)
    {
        bool debug = false;
        //place at 1st avail location, end of the array

        if(debug) {
            std::cout << "size: " << size() << std::endl;
        }

        //check if heap size is a qtr of total capacity, if so, increase
        if(size() == capacity())
        {
            if(debug) {
                std::cout << "size==cap" <<  std::endl;
            }
            capacity();
        }

        if(debug) {
            std::cout << "how_many: " << how_many << std::endl;
        }

        arr[how_many] = insert_me;

        if(debug) {
            std::cout << "arr[how_many]: " << arr[how_many] << std::endl;
        }

        //increase size by 1 to make room
        how_many++;
        size_t lastIndex = how_many - 1;
        //insert at end

        if(size() > 1)
        {
            if(debug) {
                std::cout << "if_size>1" << std::endl;
                std::cout << "arr[how_many]: " << arr[lastIndex] << "   ";
                std::cout << "arr[parent_index(how_many)]: " << arr[parent_index(lastIndex)]<<std::endl;
            }

            //while new node's parent is less than new node, swap
            while(arr[lastIndex] > arr[parent_index(lastIndex)])
            {
                if(debug) {
                    std::cout << "while_loop" << std::endl;
                }
                //swap inserted item with parent
                swap_with_parent(lastIndex);
                //reheapify up
                lastIndex = parent_index(lastIndex);
                if(debug) {
                    std::cout << "lastIndex: " << lastIndex << std::endl;
                }
            }
        }
    }

    T Pop()
    {
        assert(!is_empty());
        bool debug = false;
        size_t lastIndex = 0;
        size_t rootIndex = 0;
        T items;

        if(how_many >= 1) {
            lastIndex = how_many - 1;
            //hold on to root item
            items = arr[rootIndex];
            if(debug) {
                std::cout << "arr[lastIndex]: " << arr[lastIndex] << std::endl;
            }
            //assign last element index to first index
            arr[rootIndex] = arr[lastIndex];
            if(debug) {
                std::cout << "arr[rootIndex]: " << arr[0] << std::endl;
            }
        } else {
            lastIndex = 0;
        }


        //decrement size
        how_many--;

        while(!is_leaf(rootIndex))
        {
            if(debug) {
                std::cout << "how_many:" << how_many << std::endl;
                std::cout << "lastIndex: " << lastIndex << std::endl;
                std::cout << "arr[rootIndex]: " << arr[rootIndex] << std::endl;
                std::cout << "arr[left_child]: " << arr[left_child_index(rootIndex)] << std::endl;
                std::cout << "arr[right_child]: " << arr[right_child_index(rootIndex)] << std::endl;
            }

            //heapify down
            if(arr[left_child_index(rootIndex)] >= arr[right_child_index(rootIndex)])
            {
                swap_with_parent(left_child_index(rootIndex));
                rootIndex = left_child_index(rootIndex);
            } else
            {
                swap_with_parent(right_child_index(rootIndex));
                rootIndex = right_child_index(rootIndex);
            }
        }
        if(debug) {
            std::cout << "items: " << items << std::endl;
        }
        return items;
    }

    bool is_empty() const
    {
        return (size() == 0) ? true : false;
    }
    size_t size() const
    {
        return how_many;
    }
    size_t capacity() const
    {
        return (how_many+1) * 2;
    }
    friend std::ostream& operator << (std::ostream& outs, const Heap<T>& print_me)
    {
        print_me.print_tree(outs);
    }

private:
    void print_tree(std::ostream& outs = std::cout) const
    {
        print_tree(0,0,outs);
    }
    void print_tree(unsigned int root, int level = 0, std::ostream& outs = std::cout) const
    {
        if(root >= size())
        {
            return;
        } else
        {
            print_tree(right_child_index(root), level+1, outs);
            outs << std::setw(level*10) << "---->" << arr[root];
            print_tree(left_child_index(root), level+1, outs);
        }

    }

    T* arr;
    size_t how_many;

    bool is_leaf(size_t i) const
    {
        return (left_child_index(i) >= size()) ? true : false;
    }
    size_t parent_index(size_t i) const
    {
        return (i - 1) / 2;
    }
    size_t left_child_index(size_t i)const
    {
//        assert(!is_leaf(i));
        return 2*i + 1;
    }
    size_t right_child_index(size_t i) const
    {
//        assert(!is_leaf(i));
        return 2*i + 2;
    }
    size_t big_child_index(size_t i) const
    {
        return (left_child_index(i) > right_child_index(i)) ?
                    left_child_index(i) : right_child_index(i);

    }
    void swap_with_parent(size_t i)
    {
        bool debug = false;
        if(debug) {
            std::cout << "swapping" << std::endl;
        }
        T temp = arr[parent_index(i)];
        arr[parent_index(i)] = arr[i];
        if(debug) {
            std::cout << "arr[parent_index]: " << arr[parent_index(i)] << std::endl;
        }
        arr[i] = temp;
        if(debug) {
            std::cout << "arr[i]: " << arr[i] << std::endl;
        }

    }

};

template <typename T>
class PQueue
{
public:
    PQueue()
    {
        _heap;
    }

//    PQueue(const PQueue<T>& copy_me)
//    {
//        assert(copy_me != this);

//        for(size_t i = 0; i < copy_me.size(); i++)
//        {
//            copy_me[i] = _hea;
//        }
//    }

//    PQueue<T> operator =(const PQueue<T>& rhs)
//    {
//        assert(rhs != this);

//        for(size_t i = 0; i < rhs.size(); i++)
//        {
//            ;
//        }
//    }

    ~PQueue()
    {
        while(!_heap.is_empty())
        {
            _heap.Pop();
        }
    }

    void insert(const T& value, int p)
    {
        _heap.insert(info<T>(value, p));
    }
    T Pop()
    {
        return _heap.Pop().item;
    }

    T Pop_debug()
    {

    }

    bool is_empty() const
    {
        return (_heap.size() == 0) ? true : false;
    }
    int size() const
    {
        return _heap.size();
    }
    void print_tree() const
    {
        std::cout << _heap;
    }

    //call tree_print from bst.functions

    friend std::ostream& operator <<(std::ostream& outs, const PQueue<T>& print_me)
    {
        outs << print_me._heap;
        return outs;
    }

private:
    Heap<info<T> > _heap;

};

#endif // HEAP_H
