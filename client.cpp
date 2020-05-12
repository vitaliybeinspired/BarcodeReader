/*
Vitaliy Stepanov
CS300A Assignment 3
Professor Dr. Fatma Cemile Serce

This program reads a file and stores it into a binary search tree as a product object.
The user can then look up the description of a product by entering a barcode.
*/

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Product.h"
using namespace std;

int main() {
    BinarySearchTree<Product> bst;
    string upc, description;
    ifstream file;  
    file.open("grocery_upc_database.csv");

    if(!file) {
        cout << "File not found" << endl;
        return 0;
    }   
    
    // extracts upc from file and stores it in variable upc and 
    // extracts description from file and stores it in variable description
    while(getline(file, upc, ',') && getline(file, description)){   
        Product product(upc, description); // constructs a product object and stores upc and description
        bst.insert(product); // adds product to bst
    }

    cout << "UPC Code (q to quit): ";
    string input;
    clock_t t;
    cin >> input; // fencepost algorithm to prevent "q" from being searched
    while (input != "q") {
        Product product(input, input);
        t = clock();
        bst.search(product);
        t = clock() - t;
        cout << "Lookup time: " << t << " milliseconds" << endl << endl;
        cout << "UPC Code: ";
        cin >> input; 
    }  
    return 0;
}