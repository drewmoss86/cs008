#ifndef AVL_H
#define AVL_H
#include "bst_functions.h"

template <typename T>
class AVL
{

public:

    bool isBalanced()
    {
        bool balanced = true;
        verifyBalance(root, balanced);
        return balanced;
    }


private:
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
