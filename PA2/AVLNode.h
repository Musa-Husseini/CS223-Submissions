//
// Created by musa on 3/14/21.
//

#ifndef CPTS_223_CMAKE_EXAMPLE_AVLNODE_H
#define CPTS_223_CMAKE_EXAMPLE_AVLNODE_H
#include <iostream>
using namespace std;

template <class T>
class AVLNode{

public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;


    AVLNode()
    {
        left = nullptr;
        right = nullptr;
        height = 0;
    }
   ~AVLNode()
   {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
   }



};


#endif //CPTS_223_CMAKE_EXAMPLE_AVLNODE_H
