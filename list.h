#ifndef LIST_H
#define LIST_H

#include <iostream>
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
    while(head != NULL)
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
    else
    {
        return false;
    }
}

//makes a copy of the list, returns a pointer to the last node:
template <class T>
node<T>* copy_list(const node<T>* head, node<T>* & cpy)
{
    init_head(cpy);
    cpy = new node<T>(head->_item);
    node<T>* currentCpy = cpy;
    const node<T>* current = head;
    current = current->_next;

    while(current != NULL)
    {
        currentCpy->_next = new node<T>(current->_item);
        currentCpy = currentCpy->_next;
        current = current->_next;
    }

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

    return head;

}

//insert_after: if head is NULL, inserts at head
template <class T>
node<T>* insert_after(node<T>* &head, node<T>* after, const T& item)
{
    if(head == NULL)
    {
        insert_head(head, item);
        after = head;

        return after;
    }

    else
    {
        cout << "after: " << after->_item << endl;
//        node<T>* newNode = new node<T>(item);
//        after = newNode;
//        after = after->_next;

        return after;
    }
}

//delete the node at the head of the list, reuturn the item:
template <class T>
T delete_head(node<T>* &head)
{
    if(head != NULL)
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
