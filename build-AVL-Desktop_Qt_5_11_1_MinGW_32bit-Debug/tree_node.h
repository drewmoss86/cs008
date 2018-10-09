#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <cassert>
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
        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        return _right->_height - _left->_height;

    }

    int height()
    {
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        //node has no children

        if(_left == nullptr && _right == nullptr)
        {
//            cout << "childless:" << 1 + max(-1, -1)<<endl;
            return 1 + max(-1, -1);
        }

        //only left is null
        else if(_left == nullptr && _right != nullptr)
        {
//            cout << "null_left:" << 1 + max(-1, _right->_height)<<endl;
            return 1 + max(-1, _right->_height);
        }

        //only right is null
        else if(_left != nullptr && _right == nullptr)
        {
//            cout <<"null_right:" << 1 + max(_left->_height, -1)<<endl;
            return 1 + max(_left->_height, -1);
        }

        //two children below
        else if(_left != nullptr && _right != nullptr)
        {
//            cout << "two_children:" << 1 + max(_left->_height, _right->_height)<<endl;
            return 1 + max(_left->_height, _right->_height);
        }

    }
    int update_height()
    {
        //set the _height member variable (call height();)
        return _height = height();
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
        outs<<"|"<<t_node._item<<"|"<<"h:"<<t_node._height;
    }
};

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me)
{
    //if root is null
    if(!root)
    {
        root = new tree_node<T>(insert_me);
        root->update_height();
        return;
    }

    //insert_me item is less than root, add left
    else if(insert_me < root->_item)
    {
        tree_insert(root->_left, insert_me);
        root->update_height();
        return;
    }

    //insert_me item is less than root, add right
    else if(insert_me > root->_item)
    {
        tree_insert(root->_right, insert_me);
        root->update_height();
        return;
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
                 tree_node<T>* &found_ptr)
{
    //if not null
    if(root != nullptr)
    {
        if(target == root->_item)
        {
            found_ptr = root;
            cout << "|" << found_ptr->_item << "|" << " found!" << endl;
            return found_ptr;
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
        outs << setw(level*15) << "---->" << *root << endl;
        tree_print(root->_left, level+1, outs);
    }
}

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout)
{
//    //if null
//    if(!root)
//    {
//        outs << setw(level*15) << "---->" << "|||" << endl;
//    }

    //if not null
    if(root != nullptr)
    {
        tree_print(root->_right, level+1, outs);
        outs << setw(level*15) << "---->" << *root /*<< "h:" << root->_height */<< endl;
//        outs << "b:" << root->balance_factor() << endl;
        tree_print(root->_left, level+1, outs);
    }
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
    int max_value = 0;
    tree_node<T>* remove_ptr = NULL;
    remove_ptr = root;

    //if root is null
    if(!root)
        return false;

    else if(root->_item == target)
    {
        remove_ptr = root;
        root = root->_right;
        delete remove_ptr;
        return true;
    }

    else
    {
        //node with one or no children
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

        //node with two children
        tree_remove_max(root->_right, max_value);
        return true;
    }
}

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value)
{
    if(root->_right != nullptr)
    {
        //search to find rightmost node
        tree_remove_max(root->_right, max_value);
    }

    max_value = root->_item;  //store the item in the max_value
    delete root;       //erase rightmost node
}

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root)
{
    bool debug = false;
    if(root != nullptr)
    {
        if(debug) {
            cout << "root_item: " << root->_item << endl;
        }

        tree_node<T> *copyRoot = new tree_node<T>(root->_item);  //create new leaf

        copyRoot->_item = root->_item;  //copy root data to copyTemp item

        if(debug) {
            cout << "copyRoot_item: " << copyRoot->_item << endl;
        }

        tree_copy(root->_left);  //copy left
        tree_copy(root->_right); //copy right
    }

    return root;
}

template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size)
{

    tree_node<T>* root = nullptr;

    //base
    if(size <= 0)
        root = nullptr;

    else
    {
        cout << "size:" << size << endl;
        int mid = size / 2;

        cout << "mid:" << mid << endl;
        //make mid value root
        root = new tree_node<T>(a[mid]);

        root->_left = tree_from_sorted_list(a,mid-1);
        root->_right = tree_from_sorted_list(a,size-mid);
    }

    return root;

}

// ---------------- ROTATIONS --------------------------
template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root)
{
    if(root != nullptr)
    {

        tree_node<T> *temp = root->_right;  //temp tree_node pointer

        root->_right = temp->_left;
        temp->_left = root;

        //update height
        root->update_height();

        return temp;

    }
}

template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root)
{
    if(root != nullptr)
    {
        tree_node<T> *temp = root->_left;
        root->_left = temp->_right;
        temp->_right = root;

        //update height
        root->update_height();

        return temp;
    }
}

template <typename T>
tree_node<T>* rotate(tree_node<T>* & root) //decide which rotate is needed based on balance factor
{
    if(root != nullptr)
    {
        if(root->balance_factor() < -1)
        {
            cout << "----------ROTATE LEFT-------" << endl;
            rotate_left(root);
        }

        else if(root->balance_factor() > 1)
        {
            cout << "----------ROTATE RIGHT------" << endl;
            rotate_left(root);
        }
    }


}
#endif // TREE_NODE_H
