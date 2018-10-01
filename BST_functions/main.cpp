#include <iostream>
#include "tree_node.h"
#include "bst.h"

using namespace std;

const int SIZE = 10;
//
void test_tree_print();

void test_tree_insert(int array[], tree_node<int> *r);
void test_tree_erase(int array[], tree_node<int> *r);
void test_tree_clear(int array[], tree_node<int> *r);
void test_tree_copy(int array[], tree_node<int> *r);
void test_tree_search(int array[], tree_node<int> *r);

int main()
{


    tree_node<int> *root = nullptr;

    int array[SIZE] = {50, 75, 25, 30, 80, 90, 70, 100, 65, 20};
    int max_value;


//    BST<int> bst;

//    cout << "------------INSERT FUNCTION------------" << endl;

//    for(unsigned i = 0; i < SIZE; i++)
//    {
//        bst.insert(array[i]);
//    }
//    cout << bst;

//    cout << "------------COPY CONSTRUCTOR------------" << endl;
//    BST<int> copyBST(bst);
//    cout << copyBST;




//    test_tree_print();
//    test_tree_insert(array, root);
    test_tree_search(array, root);
//    test_tree_erase(array, root);
//    test_tree_copy(array, root);
//    test_tree_clear(array, root);

    //remove_max
//    cout << "---REMOVE_MAX FUNCTION---" << endl;
//    tree_remove_max(root,max_value);
//    tree_print(root, 0, cout);
//    cout << endl;




    return 0;
}
void test_tree_print()
{
    int level = 0;
    tree_node<int> *root = nullptr;
    cout << "------------PRINT FUNCTION------------" << endl;

    cout << "-----TEST NULL-----" << endl;
    tree_print(root, level, cout);

    cout << "-----TEST ONE VALUE-----" << endl;
    tree_insert(root, 50);
    tree_print(root, level, cout);

    cout << "-----TEST THREE VALUEs-----" << endl;
    tree_insert(root, 75);
    tree_insert(root, 25);
    tree_print(root, level, cout);

}

void test_tree_insert(int array[], tree_node<int> *r)
{
    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    //print tree_node
    tree_print(r, 0, cout);
    cout << endl << endl;

}

void test_tree_search(int array[], tree_node<int> *r)
{
//    tree_node<int> *found_ptr = nullptr;

    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    //print tree_node
    cout << "------------SEARCH FUNCTION------------" << endl;
    tree_search(r, 30);
    cout << endl << endl;

}

void test_tree_erase(int array[], tree_node<int> *r)
{
    test_tree_insert(array, r);

    cout << "------------ERASE FUNCTION------------" << endl;
    tree_erase(r, 30);
    tree_print(r, 0, cout);
    cout << endl << endl;

}

void test_tree_clear(int array[], tree_node<int> *r)
{
    test_tree_insert(array, r);

    cout << "------------CLEAR FUNCTION------------" << endl;
    tree_clear(r);
    tree_print(r, 0, cout);
    cout << endl << endl;

}

void test_tree_copy(int array[], tree_node<int> *r)
{
    test_tree_insert(array, r);

    //copy and print
    cout << "------------COPY FUNCTION------------" << endl;
    tree_copy(r);
    tree_print(r, 0, cout);
    cout << endl << endl;

}
