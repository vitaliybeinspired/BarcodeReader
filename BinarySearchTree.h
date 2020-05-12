/*
Vitaliy Stepanov
CS300A Assignment 3
Professor Dr. Fatma Cemile Serce

Generic Binary Search Tree Data Structure. Keeps greater values on the left and smaller values
on the right. Inserts, searches, and removes items.
*/

#ifndef BinarySearchTree_H_
#define BinarySearchTree_H_
using namespace std;

// Binary search tree data structure
template <class T>
struct node {
    T data; 
    node<T> *left;
    node<T> *right;
};

template <class T>
class BinarySearchTree {
    private:
        node<T> *root;
        void insertNode(node<T>*&, T&);
        void searchItem(node<T>*&, T&);
        void printInOrder(node<T>*);
        void printPreOrder(node<T>*);
        void printPostOrder(node<T>*);
        void removeNode(node<T>*&, T&);

 public:
        BinarySearchTree(); // constructor
        void insert(T&); // inserts by keeping order
        void search(T&); // searches recursively for item
        void printInOrder(); // prints data in inorder
        void printPostOrder(); // prints data in postorder
        void printPreOrder(); // prints data in preorder
        void remove(T&); // removes item 
};

// constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = NULL;
}

// call to insert an item
template <class T>
void BinarySearchTree<T>::insert(T& item) {
    insertNode(root, item);
}

// recursively looks to inserts an item at the right place
template <class T>
void BinarySearchTree<T>::insertNode(node<T> *&p, T& item) {
    if(p == NULL) {
        p = new node<T>; 
        p->data = item;
        p->left = NULL;
        p->right = NULL;
    } else if (item < p->data) { // if item is less than parent, go left in tree
         insertNode(p->left, item);
     } else if (item > p->data) { // if item is greather than parent, go right in tree
         insertNode(p->right, item);
    } // duplicate items are not allowed in binary tree
}

// calls to search for an item
template <class T>
void BinarySearchTree<T>::search(T& item) {
     searchItem(root, item);
}

// recursively looks for item
template <class T>
void BinarySearchTree<T>::searchItem(node<T> *&p, T& item) {
    if (p == NULL) {
        cout << "Not found" << endl; // 
    } else if (item < p->data) { // if item is less than data
        searchItem(p->left, item);
    } else if (item > p->data) { // if item is greater than data
        searchItem(p->right, item);
    } else { // item is found
        cout << p->data; 
    }
}

template <class T>
void BinarySearchTree<T>::printInOrder() {
    printInOrder(root);
}

// prints data of tree inorder
template <class T>
void BinarySearchTree<T>::printInOrder(node<T>* p) {
    if (p != NULL) {
        printInOrder(p->left);
        cout << p->data;
        printInOrder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::printPreOrder() {
    printPreOrder(root);
}

// prints data of tree in preorder
template <class T>
void BinarySearchTree<T>::printPreOrder(node<T>* p) {
    if (p != NULL) {
        cout << p->data;
        printInOrder(p->left);
        printInOrder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::printPostOrder() {
    printPostOrder(root);
}

// prints data of tree in postorder
template <class T>
void BinarySearchTree<T>::printPostOrder(node<T>* p) {
    if (p != NULL) {
        printInOrder(p->left);
        printInOrder(p->right);
        cout << p->data;
    }
}

// calls to remove item
template <class T>
void BinarySearchTree<T>::remove(T& item) {
    removeNode(root, item);
}

// recursive calls to remove item
template <class T>
void BinarySearchTree<T>::removeNode(node<T>*& p, T& item) {    
    if (p == NULL) {
        return;
    } else if ( item < p->data) { // if item is less than data
        removeNode(p->left, item);
    } else if (item > p->data) { // if item is greater than data
        removeNode(p->right, item);
    } else { // item is found
        if (p->left == NULL && p->right == NULL) { // leaf node
            delete p;
            p = NULL;
        } else { // only one child
            node<T> *old = p;
            if (p->left != NULL) {
                p = p->left;
            }
            if (p->right != NULL) {
                p = p->right;
            }
            delete old;
        }
    }
}
#endif
