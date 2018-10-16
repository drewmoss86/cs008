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

        //right is not null, then right_height, else -1 minus if left is not null, then left height, else -1
        return (((_right) ? _right->_height : -1) -
                ((_left) ? _left->_height : -1));

    }

    int height()
    {
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        //node has no children

        return 1 + max(((_right) ? _right->_height : -1),
                       ((_left) ? _left->_height : -1));

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
        update_height();
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node)
    {
        outs<<"|"<<t_node._item<<"|";
    }
};

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me)
{
    //if root is null
    if(!root)
    {
        root = new tree_node<T>(insert_me);
    }

    //insert_me item is less than root, add left
    else if(insert_me < root->_item)
    {
        tree_insert(root->_left, insert_me);
    }

    //insert_me item is less than root, add right
    else if(insert_me > root->_item)
    {
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
    rotate(root);
}

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target)
{
    bool debug = false;

    if(!root)
        return nullptr;

    //if not null
    if(root)
    {
        if(target == root->_item)
        {
            return root;
        }

        else if(target > root->_item)
        {
            if(debug) {
                cout <<"search right"<<endl;
            }
            return tree_search(root->_right, target);

            if(debug) {
                cout <<"back from search right"<<endl;
            }
        }

        else if(target < root->_item)
        {
            if(debug) {
                cout <<"search left"<<endl;
            }
            return tree_search(root->_left, target);

            if(debug) {
                cout <<"back from search left"<<endl;
            }
        }

    }

    return root;

}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr)
{
    bool debug = false;

    if(!root)
    {
        if(debug) {
            cout << "root=NULL"<< endl;
        }

        return false;
    }

    //if not null
    else
    {
        //when target is found, set found_ptr to root
        if(target == root->_item)
        {
            if(debug) {
                cout <<"target found"<<endl;
            }
            found_ptr = root;
            return true;
        }

        //when target is not found and is larger than root, go right
        else if(target > root->_item)
        {
            if(debug) {
                cout << "target > root->_item"<<endl;
                cout<<"search right"<<endl;
            }
            return tree_search(root->_right, target, found_ptr);

            if(debug) {
                cout <<"back from search right"<<endl;
            }
        }

        //when target is not found and is less than root, go left
        else if(target < root->_item)
        {
            if(debug) {
                cout << "target < root->_item"<<endl;
                cout<<"search left"<<endl;
            }
            return tree_search(root->_left, target, found_ptr);

            if(debug) {
                cout<<"back from search left"<<endl;
            }
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
    if(root != nullptr)
    {
        tree_print(root->_right, level+1, outs);
        outs << setw(level*10) << "---->" << *root << endl;
        tree_print(root->_left, level+1, outs);
    }
}

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout)
{
//    static int counter = 0;
//    counter++;
//    cout<<counter<<endl;
    //if not null
    if(root != nullptr)
    {
        tree_print_debug(root->_right, level+1, outs);
        outs << setw(level*15) << "---->" << *root;
        outs << "h:" << root->_height << "|";
        outs << "b:" << root->balance_factor() << "|" << endl;
        tree_print_debug(root->_left, level+1, outs);
    }
}

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root)
{
    bool debug = false;

    if(!root)
        return;

    else
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
//    static int counter = 0;
//    counter++;
//    cout<<counter<<endl;

    T max_value = 0;
    tree_node<T>* remove_ptr = NULL;
    bool toErase = true;

    //if root is null
    if(!root)
        return false;

    //if target is found
    else if(root->_item == target)
    {
        //no left child
        if(root->_left == nullptr)
        {
            remove_ptr = root;
            root = root->_right;

            delete remove_ptr;
        }

        //left child
        else
        {
//            cout << "remove_max_in_erase"<<endl;
            tree_remove_max(root->_left, max_value);
            //when max_value is found, assign to the current root item
            root->_item = max_value;
        }

        if(root)
        {
            root->update_height();
            rotate(root);
        }

        return true;

    }

    //target not found - less than root
    else if(target < root->_item)
    {
        toErase = tree_erase(root->_left, target);
        //if traversing left toErase is true, then update height and rotate
        if(toErase) {

            root->update_height();
            rotate(root);
        }

        return toErase;
    }

    //target not found - greater than root
    else if(target > root->_item)
    {
        //returns true/false based on whether or not target was found
        toErase = tree_erase(root->_right, target);
        //if traversing right toErase is true, then update height and rotate
        if(toErase) {

            root->update_height();
            rotate(root);
        }

        return toErase;
    }


}

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value)
{
    if(!root)
    {
        return;
    }
    else if(root->_right != nullptr)
    {
        //search to find rightmost node
        tree_remove_max(root->_right, max_value);
        root->update_height();
        rotate(root);
    }

    else
    {
        max_value = root->_item;  //store the item in the max_value

        //root has a left-child
        if(root->_left != nullptr)
        {
            tree_node<T> *temp;
            temp = root;
            root = root->_left;

            delete temp;
        }
        else
        {
//            cout << "remove_mx_leftnotNULL"<<endl;
            delete root;       //erase rightmost node
            root = nullptr;
        }

    }

}

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root)
{
    bool debug = false;

    return (root) ? new tree_node<T>(root->_item, tree_copy(root->_left),
                                     tree_copy(root->_right)) : nullptr;
}

template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src)
{
    if(!src)
    {
        return;
    }
    else
    {
        tree_insert(dest, src->_item);
        //preorder traversal
        tree_add(dest, src->_left);
        tree_add(dest->_right, src->_right);
    }

}


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size)
{

    tree_node<T>* root = nullptr;

    //base
    if(size <= 0)
        root = nullptr;

    else
    {
        int mid = size / 2;

        //make mid value root

        if(size % 2 == 0) {
            root = new tree_node<T>(a[mid], tree_from_sorted_list(a, mid),
                                    tree_from_sorted_list(a+mid+1, mid-1) );
        }
        else {
            root = new tree_node<T>(a[mid], tree_from_sorted_list(a,mid),
                                    tree_from_sorted_list(a + mid + 1,mid));
        }

    }

    return root;

}

// ---------------- ROTATIONS --------------------------
template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root)
{
    //temp1 pointer to save orig root
    tree_node<T>* temp1 = root;
    //temp2 to point to right's left
    tree_node<T>* temp2 = root->_right->_left;
    //change root to root's right
    root = root->_right;
    //root left = orig root/temp1
    root->_left = temp1;
    //root left right is temp2
    root->_left->_right = temp2;

    //update height
    root->_left->update_height();
    root->update_height();
    return root;


}

template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root)
{
    //temp1 pointer to save orig root
    tree_node<T>* temp1 = root;
    //temp2 to point to right's left
    tree_node<T>* temp2 = root->_left->_right;
    //change root to root's right
    root = root->_left;
    //root left = orig root/temp1
    root->_right = temp1;
    //root left right is temp2
    root->_right->_left = temp2;

    //update height
    root->_right->update_height();
    root->update_height();
    return root;


}

template <typename T>
tree_node<T>* rotate(tree_node<T>* & root) //decide which rotate is needed based on balance factor
{
    bool debug = false;
    if(root != nullptr)
    {
        //
        if(root->balance_factor() == 2 && root->_right != nullptr && root->_right->balance_factor() == 1)
        {
            if(debug) {
                cout << "----------ROTATE LEFT-------" << endl;
            }
            root = rotate_left(root);
        }

        else if(root->balance_factor() == -2 && root->_left != nullptr && root->_left->balance_factor() == -1)
        {
            if(debug) {
                cout << "----------ROTATE RIGHT------" << endl;
            }
            root = rotate_right(root);
        }

        else if(root->balance_factor() == -2 && root->_left != nullptr && root->_left->balance_factor() == 1)
        {
            if(debug) {
                cout << "----------ROTATE LEFT-RIGHT------" << endl;
            }
            root->_left = rotate_left(root->_left);
            root = rotate_right(root);
        }
        else if(root->balance_factor() == 2 && root->_right != nullptr && root->_right->balance_factor() == -1)
        {
            if(debug) {
                cout << "----------ROTATE RIGHT-LEFT------" << endl;
            }
            root->_right = rotate_right(root->_right);
            root = rotate_left(root);
        }

        return root;
    }

}
#endif // TREE_NODE_H
