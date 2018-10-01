#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor()
    {
        //balance factor = height of the left subtree
        //                        - the height of the right subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
    }

    int height()
    {
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        _height = 1 + max(-1,-1);
    }
    int update_height()
    {
        //set the _height member variable (call height();)
        height();
    }

    tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)
    {

        //don't forget to set the _height.
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node)
    {
        outs<<"|"<<t_node._item<<"|"<<endl;
    }
};

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me)
{
    //if root is null
    if(!root)
    {
        root = new tree_node<T>(insert_me);
//        cout << "root: " << root->_item << endl;
        return;
    }

    //insert_me item is less than root, add left
    else if(insert_me < root->_item)
    {
        tree_insert(root->_left, insert_me);
        return;
    }

    //insert_me item is less than root, add right
    else(insert_me > root->_item);
    {
        tree_insert(root->_right, insert_me);
    }

}

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target)
{
    //if not null
    if(root != nullptr)
    {
        if(target == root->_item)
        {
            cout << "|" << root->_item << "|" << " found!" << endl;
            return root;
        }

        else if(target > root->_item)
        {
            tree_search(root->_right, target);
        }

        else if(target < root->_item)
        {
            tree_search(root->_left, target);
        }
    }
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);


template<typename T>
void tree_print(tree_node<T>* root, int level=0,
                                    ostream& outs=cout)
{
//    if(!root)
//        outs << setw(level*15) << "---->" << "|||";

    //if not null
    /*else*/ if(root != nullptr)
    {
        tree_print(root->_right, level+1, outs);
        outs << setw(level*15) << "---->" << *root;
        tree_print(root->_left, level+1, outs);
    }
}

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout)
{
    //if not null
    if(root != nullptr)
    {
        tree_print(root->_right, level+1, outs);
        outs << setw(level*15) << "---->" << *root;
        tree_print(root->_left, level+1, outs);
    }
    return;
}

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root)
{
    bool debug = false;
    if(root != nullptr)
    {
        tree_clear(root->_left);
        tree_clear(root->_right);

        if(debug) {
            cout << "deleting node: " << root->_item << endl;
        }

        delete root;
    }
    root = nullptr;

}

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target)
{
    tree_node<T>* remove_ptr = NULL;

    //if root is null
    if(!root)
        return false;

    if(root->_item == target)
    {
        remove_ptr = root;
        root = root->_right;
        delete remove_ptr;
        return true;
    }

    if(target < root->_item)
    {
        tree_erase(root->_left, target);
        return true;
    }

    else if(target > root->_item)
    {
        tree_erase(root->_right, target);
        return true;

    }

}

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value)
{
    //search to find rightmost node
    tree_remove_max(root->_right, max_value);

    max_value = root->_item;  //store the item in the max_value
    delete root;       //erase rightmost node
}

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root)
{

    if(root != nullptr)
    {      
        cout << "root_item: " << root->_item << endl;
        tree_node<T> *copyRoot = new tree_node<T>(root->_item);  //create new leaf

        copyRoot->_item = root->_item;  //copy root data to copyTemp item
        cout << "copyRoot_item: " << copyRoot->_item << endl;

        tree_copy(root->_left);  //copy left
        tree_copy(root->_right); //copy right
        return copyRoot;

    }

//    return root;
}

template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size);
#endif // TREE_NODE_H
