//
// Created by musa on 3/14/21.
//

#ifndef CPTS_223_CMAKE_EXAMPLE_AVLTREE_H
#define CPTS_223_CMAKE_EXAMPLE_AVLTREE_H
#include <iostream>
#include "AVLNode.h"
using namespace std;

template <class T>
class AVLTree {

private:
    AVLNode<T>* root;

    bool validateHelper(AVLNode<T>* node)
    {
        if(node == NULL)
            return false;
        if(heightHelper(node->left) - heightHelper(node->right) < 2)
            return true;
    }

    AVLNode<T> * insertHelper(int value, AVLNode<T> *node)
    {
        if(node == nullptr)
        {
            node = new AVLNode<T>;
            node->data = value;
            node->right = NULL;
            node->left = NULL;
            node->height = 0;
        }
        else if(value < node->data)
        {
            node->left = insertHelper(value, node->left);
            if(heightHelper(node->left) - heightHelper(node->right) == 2)
            {
                if(value < node->left->data)
                    node = rightRotate(node);
                else
                    node = doubleRightRotate(node);
            }

        }
        else if(value > node->data)
        {
            node->right = insertHelper(value, node->right);
            if(heightHelper(node->right) - heightHelper(node->left) == 2)
            {
                if(value > node->right->data)
                    node = leftRotate(node);
                else
                    node = doubleLeftRotate(node);
            }
        }

        node->height = max(heightHelper(node->left), heightHelper(node->right)) + 1;
        return node;



    }

    AVLNode<T>* leftRotate(AVLNode<T>* & x)
    {
        AVLNode<T>* y = x->right;


        x->right = y->left;
        y->left = x;


        x->height = max(heightHelper(x->left), heightHelper(x->right)) + 1;
        y->height = max(heightHelper(y->left), heightHelper(y->right)) + 1;

        return y;
    }
    AVLNode<T> *rightRotate(AVLNode<T>* & x)
    {
        AVLNode<T>* y = x->left;

        x->left = y->right;
        y->right= x;

        x->height = max(heightHelper(x->left), heightHelper(x->right)) + 1;
        y->height = max(heightHelper(y->left), heightHelper(y->right)) + 1;

        return y;
    }

    AVLNode<T>* doubleLeftRotate(AVLNode<T>*& x)
    {
        x->right = rightRotate(x->right);
        return leftRotate(x);
    }

    AVLNode<T>* doubleRightRotate(AVLNode<T>*& x)
    {
        x->left = leftRotate(x->left);
        return rightRotate(x);
    }

    void printPreOrder(AVLNode<T>* node)
    {
        if(node == NULL)
            return;

        cout << node->data << ' ';
        printPreOrder(node->left);

        printPreOrder(node->right);


    }

    int heightHelper(AVLNode<T>* node)
    {
        if(node == NULL)
            return 0;
        return node->height;
    }
public:
    AVLTree()
    {
        root = NULL;
    }
    ~AVLTree();




    void height()
    {
        cout << heightHelper(root) << endl;
    }
    void validate()
    {
        cout << "Validation: " << validateHelper(root) << endl;
    }


    void insert(int value)
    {
        root = insertHelper(value, root);
    }



    void print()
    {
        printPreOrder(root);
        cout << endl;
    }


};



#endif //CPTS_223_CMAKE_EXAMPLE_AVLTREE_H
