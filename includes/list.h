/******************************************
 * Name: Andrew Moss
 *
 * Date: 9/5/2018
 *
 * Assignment: Stack and Queue
 *
 *****************************************/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(const T& item = T(), node<T>* next = NULL):_item(item), _next(next){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//initializes head to NULL
template <class T>
node<T>* init_head(node<T>* &head)
{
    head = NULL;
    return head;
}

//deletes all the nodes in the list
template<class T>
void delete_all(node<T>*&head)
{
    while(!empty(head))
    {
        delete_head(head);
    }
}

//true if head is NULL, false otherwise.
template <class T>
bool empty(const node<T>* head)
{
    if(head == NULL)
    {
        return true;
    }

    return false;

}

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    //initialize the copy to list
    init_head(cpy);
    //since we know this list is empty, create first node with item from head of
    //list being copied
    cpy = new node<T>(head->_item);
    //create a current pointer to traverse the copy to list
    node<T>* currentCpy = cpy;
    //create a current pointer from list being copied
    const node<T>* current = head;
    //after first node has been copied, traverse to next node
    current = current->_next;

    //before the current pointer reaches the end of the list or NULL, make copies
    //of each node
    while(current != NULL)
    {
        //point current pointer to newly created node
        currentCpy->_next = new node<T>(current->_item);
        //traverse current pointer to point to newly added node
        currentCpy = currentCpy->_next;
        //traverse current pointer from list being copied
        current = current->_next;
    }

    //when each node in list is done being copied, return the pointer to the
    //last node in copy list
    return currentCpy;
}

//insert at the beginning of the list:
template <class T>
node<T>* insert_head(node<T>* &head, T item)
{
    //create a new node pointer and new node
    node<T> *newNode = new node<T>(item);
    //point newNode to node that head pointer is pointing to
    newNode->_next = head;
    //point head pointer to new node
    head = newNode;

    //return pointer pointing to newly added node
    return head;

}

//insert_after: if head is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item)
{
    //checking to see if head is null. If so, insert at head
    if(empty(head))
    {
        //call insert_head list function
        insert_head(head, item);
        //point after to head since it's first and last node
        after = head;

        //return pointer pointing to last node added
        return after;
    }

    //condition to execute if list is not empty/contains at least one node
    else
    {
        //point last node in list to newly created node
        after->_next = new node<T>(item);
        //traverse after pointer to newly created node, which will be last node
        //in list
        after = after->_next;

        //return pointer poitnitng to last node added
        return after;
    }
}

//delete the node at the head of the list, reuturn the item:
template <class T>
T delete_head(node<T>* &head)
{
    if(!empty(head))
    {
        //create temporary pointer
        node<T> *temp = NULL;
        //point temp pointer to whatever head is pointing to
        temp = head;
        //traverse head pointer to next node
        head = head->_next;
        //return item that temp is pointing to
        return temp->_item;
    }

    return 0;
}

//print the list and return outs
template<class T>
ostream& print_list(const node<T>* head, ostream& outs=cout)
{
    while(head != NULL)
    {
        outs << "[" << head->_item << "]->";
        head = head->_next;
    }

    return outs;
}

#endif // LIST_H
