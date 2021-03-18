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


    /*
    AVLNode(T& newData, AVLNode<T>* lt, AVLNode<T> rt, int h = 0)
    {
        data = newData;
        left = lt;
        right = rt;
        height = h;
    }

    ~AVLNode();
     */


};


#endif //CPTS_223_CMAKE_EXAMPLE_AVLNODE_H
