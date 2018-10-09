/******************************************
 * Name: Andrew Moss
 *
 * Date: 10/8/2018
 *
 * Class: CS 008
 *
 * Assignment: AVL Tree
 *
 ******************************************/
#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <cassert>
#include "tree_node.h"

using namespace std;

template <typename T>

class avl{

public:

bool isBalanced()
{
    bool balanced = true;
    verifyBalance(root, balanced);
    return balanced;
}

avl()
{
    root = nullptr;
}
avl(const T* sorted_list, int size=-1)
{
    root = tree_from_sorted_list(sorted_list,size);
}

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

avl(const avl<T>& copy_me)
{
    assert(this != &copy_me);
    root = tree_copy(copy_me.root);
}
avl<T>& operator =(const avl<T>& rhs)
{
    assert(this != &rhs);
    tree_clear(root);
    root = tree_copy(rhs.root);
}
~avl()
{
    clear();
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//insert() : function takes in a value and inserts into tree
void insert(const T& insert_me)
{
    tree_insert(root,insert_me);
}
//erase() : function erases a single node in the tree based on a target value
void erase(const T& target)
{
    tree_erase(root,target);
}
//search() : function finds a target node and returns true if found and false if not
bool search(const T& target, tree_node<T>* & found_ptr)
{
    return tree_search(root,target,found_ptr);
}
//clear() : function clears tree
void clear()
{
    tree_clear(root);
    root = nullptr;
}
//operator<< : inseration operator outputs tree
friend ostream& operator <<(ostream& outs, const avl<T>& tree)
{
    int level = 0;
    bool debug = false;
    if(!debug) {
        tree_print(tree.root,level+1,outs);
    }
    if(debug) {
        tree_print_debug(tree.root,level+1,outs);
    }

}
//operator+= : adds a tree to existing tree
avl<T>& operator +=(const avl<T>& rhs)
{
    root = tree_add(root, rhs.root);
}


private:
tree_node<T>* root;

void verifyBalance(tree_node<T>* root, bool &balance)
{
    if(root)
    {
        verifyBalance(root->_left,balance);
        if(abs(root->balance_factor()) >= 2) balance = false;
        verifyBalance(root->_right,balance);
    }
}
};
#endif // AVL_H
