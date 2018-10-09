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
#include <iostream>
#include "avl.h"

//prototype
void avlMenu();
using namespace std;

int main()
{
    avlMenu();

    return 0;
}
/**********************************************************
*
*  avlMenu
*  _________________________________________________________
*  This function tests the avl functions based on user input
*  _________________________________________________________
*  PRE-CONDITIONS
*  none
*
*  POST-CONDITIONS
*  Returns nothing
***********************************************************/
void avlMenu()
{
    char selection = ' ';

    avl<int> a;
    tree_node<int> *found_ptr = nullptr;
    bool isFound = false;
    int insert_me_value = 0;
    int search_value = 0;
    int nodeCounter = 0;

    while(selection != 'x' && selection != 'X')
    {
        //counts number of nodes in the tree
        cout<< nodeCounter << " node(s) in tree" << endl;
        cout << "[R]andom  [I]nsert  [C]lear  [S]earch  [E]rase  e[X]it: ";
        cin >> selection;

        if(selection == 'r' || selection == 'R'){
            insert_me_value = rand()%100;
            cout << "-- Inserting " << insert_me_value << endl;
            a.insert(insert_me_value);
            nodeCounter++;
            //            cout << a;
        } else if(selection == 'i' || selection == 'I') {
            cout << "Input value to insert: ";
            cin >> insert_me_value;
            a.insert(insert_me_value);
            nodeCounter++;
            //            cout << a;
        } else if(selection == 'c' || selection == 'C') {
            a.clear();
            nodeCounter = 0;
        } else if(selection == 's' || selection == 'S') {
            cout << "Input value to search: ";
            cin >> search_value;

            isFound = a.search(search_value, found_ptr);
            if(isFound) {
                cout << "Item is found " /*<< found_ptr->_item */<< endl;
            }    else {
                cout << "Item not found." << endl;
            }

        } else if(selection == 'e' || selection == 'E') {
            cout << "Input value to delete: ";
            cin >> search_value;
            if(a.search(search_value,found_ptr)) {
                cout << insert_me_value << " deleted" << endl;

                a.erase(search_value);
                nodeCounter--;
            } else {
                cout << "Item not found. No deletion occurred." << endl;
            }
        }

        cout << a;
    }

    cout << "Exiting..." << endl;
}
