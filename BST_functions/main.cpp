#include <iostream>
#include <iomanip>
#include <array>
#include "tree_node.h"
#include "bst.h"

using namespace std;

const int SIZE = 15;
//
void test_tree_print();

void test_tree_insert(int array[], tree_node<int> *r);
void test_tree_erase(int array[], tree_node<int> *r);
void test_tree_clear(int array[], tree_node<int> *r);
void test_tree_copy(int array[], tree_node<int> *r);
void test_tree_search(int array[], tree_node<int> *r);
void test_tree_from_sorted_list(int array[], tree_node<int> *r, int size);
void test_tree_rotate();


int main()
{

    tree_node<int> *root = nullptr;

//    int array[SIZE] = {rand()%100+1, rand()%100+1, rand()%100+1, rand()%100+1,
//                       rand()%100+1, rand()%100+1, rand()%100+1, rand()%100+1,
//                       rand()%100+1, rand()%100+1, rand()%100+1, rand()%100+1,
//                       rand()%100+1, rand()%100+1, rand()%100+1};
    int array[SIZE] = {50, 75, 25, 30, 45,
                       100, 60, 10, 20, 95,
                       80, 85, 70, 55, 43};
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7};

    int sortedArraySize = sizeof(sortedArray)/sizeof(*sortedArray);


//    int max_value;


//    BST<int> bst;

//    cout << "------------INSERT FUNCTION------------" << endl;
//    int insert_me_value = 0;

//    cout << "Insert value: ";
//    cin >> insert_me_value;

//    bst.insert(insert_me_value);

//    cout << bst;

//    for(unsigned i = 0; i < SIZE; i++)
//    {
//        bst.insert(array[i]);
//    }
//    cout << bst;

//    cout << "------------COPY CONSTRUCTOR------------" << endl;
//    BST<int> copyBST(bst);
//    cout << copyBST;

//    cout << "------------ASSIGNMENT OPERATOR------------" << endl;
//    BST<int> assignBST;
//    assignBST = copyBST;

//    cout << assignBST;



//    test_tree_print();
//    test_tree_insert(array, root);
//    test_tree_search(array, root);
//    test_tree_erase(array, root);
//    test_tree_copy(array, root);
//    test_tree_clear(array, root);
    test_tree_from_sorted_list(sortedArray,root,sortedArraySize);
//    test_tree_rotate();



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
    tree_print_debug(root, level, cout);

    cout << "-----TEST ONE VALUE-----" << endl;
    tree_insert(root, 50);
//    cout << "h:" << root->_height;
    tree_print_debug(root, level, cout);

    cout << "-----TEST THREE VALUEs-----" << endl;
    tree_insert(root, 75);
//    cout << "h:" << root->height();
    tree_insert(root, 25);
//    cout << "h:" << root->height();
    tree_print_debug(root, level, cout);

    cout << "-----TEST MULTIPLE VALUEs-----" << endl;

    for(int i = 0; i < 50; i++)
    {
        tree_insert(root, rand()%100+i);
    }
    tree_print_debug(root, level, cout);
}

void test_tree_insert(int array[], tree_node<int> *r)
{
    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    //print tree_node
    tree_print_debug(r, 0, cout);
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
    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    cout << "------------ORIGINAL------------" << endl;
    tree_print_debug(r, 0, cout);
    cout << "------------ERASE FUNCTION------------" << endl;
    cout << "------ONE CHILD------" << endl;
    tree_erase(r, 30);
    tree_print_debug(r, 0, cout);
    cout << "------TWO CHILDREN------" << endl;
    tree_erase(r, 60);
    tree_print_debug(r, 0, cout);
    cout << endl << endl;

}

void test_tree_clear(int array[], tree_node<int> *r)
{
    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    cout << "------------ORIGINAL------------" << endl;
    tree_print_debug(r, 0, cout);

    cout << "------------CLEAR FUNCTION------------" << endl;
    tree_clear(r);
    tree_print_debug(r, 0, cout);
    cout << endl << endl;

}

void test_tree_copy(int array[], tree_node<int> *r)
{
    for(unsigned i = 0; i < SIZE; i++)
    {
        tree_insert(r, array[i]);
    }

    //copy and print
    cout << "------------ORIGINAL------------" << endl;
    tree_print_debug(r, 0, cout);
    cout << "------------COPY FUNCTION------------" << endl;
    r = tree_copy(r);
    tree_print_debug(r, 0, cout);
    cout << endl << endl;

}

void test_tree_from_sorted_list(int array[], tree_node<int> *r, int size)
{
    r=tree_from_sorted_list(array, size);

    tree_print_debug(r,0,cout);
}

void test_tree_rotate()
{
    cout << "------------UNBALANCED TREE--RIGHT----------" << endl;
    tree_node<int> *unbal_rt_root = nullptr;
    tree_insert(unbal_rt_root, 50);
    tree_insert(unbal_rt_root, 80);
    tree_insert(unbal_rt_root, 90);
    tree_insert(unbal_rt_root, 100);
    tree_print_debug(unbal_rt_root,0,cout);

    cout << "------------TEST ROTATE RIGHT------------" << endl;
    unbal_rt_root = rotate_right(unbal_rt_root);
    tree_print_debug(unbal_rt_root,0,cout);

    cout << "------------UNBALANCED TREE--LEFT----------" << endl;
    tree_node<int> *unbal_lft_root = nullptr;
    tree_insert(unbal_lft_root, 50);
    tree_insert(unbal_lft_root, 25);
    tree_insert(unbal_lft_root, 20);
    tree_insert(unbal_lft_root, 15);
    tree_print_debug(unbal_lft_root,0,cout);

    cout << "------------TEST ROTATE LEFT------------" << endl;
    unbal_lft_root = rotate_left(unbal_lft_root);
    tree_print_debug(unbal_lft_root,0,cout);

    cout << "------------UNBALANCED TREE--LEFT/RIGHT----------" << endl;
    tree_node<int> *unbal_root = nullptr;
    tree_insert(unbal_root, 50);
    tree_insert(unbal_root, 25);
    tree_insert(unbal_root, 75);
    tree_insert(unbal_root, 80);
    tree_insert(unbal_root, 90);


    tree_print_debug(unbal_root,0,cout);

    cout << "------------ROTATE------------" << endl;
    unbal_root = rotate(unbal_root);
    tree_print_debug(unbal_root,0,cout);

}
