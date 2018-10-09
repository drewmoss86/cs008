#ifndef BALANCE_TEST_H
#define BALANCE_TEST_H

#include <cstring>
#include <unordered_set>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>
#include "avl.h"

using namespace std;


//preconditions: none
//postconditions: 1000 randomly sized AVLs will be created. For each tree,
// a random number of items will be inserted, after all items have been inserted, they will be erased.
// After each insertion or removal the balance factor will verified.
void randomBalanceTests()
{
    srand(time(0));
    const unsigned ATTEMPTS = 1000;
    const unsigned MAX_TREE_SIZE =100;
    bool balanceSuccess = true;

    cout << endl << "Creating: " << ATTEMPTS << " randomly sized AVLs, 0 <= size < " << MAX_TREE_SIZE << endl
         << "For each tree, a random number of items will be inserted, \nafter each insertion, the balance factor will be verified." << endl
         << "Then the items will be deleted from the tree, \nafter each deletion the balance factor will verified."<< endl
         << "If at any point, the balance factor is found to be: \n>= 2 or, <= -2, an error will be printed" << endl << string(50,'=') << endl;

    for(unsigned i = 0; i < ATTEMPTS; i++)
    {
        unsigned treeSize = rand() % MAX_TREE_SIZE;
        unsigned maxValue = treeSize * 10;
        unordered_set<int> dataSet1;
        AVL<int> theTree;

        //insert MAX_TREE_SIZE random, unique values into the data set.
        while(dataSet1.size() < treeSize)
            dataSet1.insert(rand() % maxValue);

        //insert each item in the set into the AVL.
        for(unordered_set<int>::iterator it = dataSet1.begin(); it != dataSet1.end(); it++)
        {
            theTree.insert(*it);

            //check that the avl remains balanced after each insertion.
            if(!theTree.isBalanced())
            {
                cout << "AVL #: " << i << endl << string(50,'-') << endl
                     << "Error: AVL is not balanced." << " after inserting: " << *it
                     << endl << string(50,'-') << endl << theTree << endl << string(50,'-') << endl;
                balanceSuccess = false;
            }
        }

        //remove each item from the AVL.
        for(unordered_set<int>::iterator it = dataSet1.begin(); it != dataSet1.end(); it++)
        {
            theTree.erase(*it);

            //check that the avl remains balanced after each deletion.
            if(!theTree.isBalanced())
            {
                cout << "AVL #: " << i << endl << string(50,'-') << endl
                     << "Error: AVL is not balanced." << " after removing: " << *it
                     << endl << string(50,'-') << endl << theTree << endl << string(50,'-') << endl;
                balanceSuccess = false;

            }
        }
    }

    if(balanceSuccess)
        cout << "Success: All balance tests passed." << endl;
    else
        cout << "Error: At least one balance test failed." << endl;
    cout << string(50,'=') << endl << endl;
}

#endif // BALANCE_TEST_H
