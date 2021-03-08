#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <vector>
using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}
    bool containsHelp(Node<T> *root, T value)
    {

        if(root != NULL) {
            if (root->value == value)
            {
                return true;
            }

            else if (value < root->value)
            {
                containsHelp(root->left, value);
            }

            else if (value > root->value)
            {
                containsHelp(root->right, value);
            }

            else {
                return false;
            }

        }

    }

    void printLevelOrderHelper(Node<T> * node, int bstLevel)
    {

	    if(node != NULL) {
            if (bstLevel == 1)
                cout << node->value << " ";
            else {
                printLevelOrderHelper(node->left, bstLevel - 1);
                printLevelOrderHelper(node->right, bstLevel - 1);
            }


        }
    }
    vector<int> printMaxPathHelper(Node<T> * node)
    {
        if(node == NULL) //if node is empty return an empty node
        {
            vector<int> emptyNode = {};
            return emptyNode;
        }

        vector<int> right = printMaxPathHelper(node->right); // recursively traverse the right side of the bst and save nodes in right vector
        vector<int> left = printMaxPathHelper(node->left); // recursively traverse the left side of the bst and save the nodes in left vector

        if(left.size() > right.size()) // if the left vector is greater than the right then put all the values of the left path into the left vector
        {
            left.push_back(node->value);
        }

        else // does opposite for line 178
        {
            right.push_back(node->value);
        }

        return(left.size() > right.size() ? left : right); // this will return the correct vector depending on which is bigger, this return does a comparision and returns the bigger vector


    }
	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST()
	{

	    destroyTree(_root);
	}

	void destroyTree(Node<T>* node)
    {
	    if(node)
        {
	        destroyTree(node->left);
	        destroyTree(node->right);
	        delete node;
        }
    }


	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	/**
	 * Print the nodes level by level, starting from the root
	 * TODO: Implement printLevelOrder
	 */
	void printLevelOrder() {

		int h = height();
		int i = 1;
		if(_root == NULL)
		    cout << "Nothing in Tree" << endl;
		for(i; i <= h; i++)
        {

		    printLevelOrderHelper(_root, i);

		    cout << endl;
        }

		printLevelOrderHelper(_root, i);
        cout << endl;


	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath() {

        if (_root == NULL)
        {
        cout << "The tree is empty" << endl;
        return;
        }

       vector<int> maxPath = printMaxPathHelper(_root);

        for(int i = maxPath.size(); i >= 0; i--)
        {
            if(maxPath[i] == 0)
                continue;
            cout << " " << maxPath[i];
        }

        cout << endl;

	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) {

        if(containsHelp(_root, value) == true) {
            return true;
        }
        else {
            //return numeric_limits<T>::min(); // help
            return false;
        }


	}


};

#endif

