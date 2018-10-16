#ifndef BST_H
#define BST_H

#include "tree_node.h"
#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class BST{

public:
 BST<T>()
 {
     root = NULL;
 }
 BST<T>(const T* sorted_list, int size=-1);

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

 BST(const BST<T>& copy_me)
 {
     assert(this != &copy_me);
     root = tree_copy(copy_me.root);
 }

 BST<T>& operator =(const BST<T>& rhs)
 {
     //check if it has already been assigned
     assert(this != &rhs);
     root = tree_copy(rhs.root);
 }

 ~BST()
 {
     root = nullptr;
     tree_clear(root);
 }

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

 void insert(const T& insert_me)
 {
     tree_insert(root, insert_me);
 }
 void erase(const T& target)
 {
     tree_erase(root, target);
 }
 bool search(const T& target, tree_node<T>* & found_ptr)
 {
     return tree_search(root, target, found_ptr);
 }

 friend ostream& operator <<(ostream& outs, const BST<T>& tree)
 {
     int level = 0;
     tree_print(tree.root,level+1,outs);
 }
 BST<T>& operator +=(const BST<T>& rhs);

private:
 tree_node<T>* root;

};

#endif // BST_H
