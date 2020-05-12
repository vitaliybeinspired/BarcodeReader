/*
Vitaliy Stepanov
CS300A Fall 2019
Professor Dr. Fatma Cemile Serce

Product class that stores upc and description as strings
*/

#ifndef Product_H_
#define Product_H_
using namespace std;

class Product {
    private: 
        string upc;
        string description;

    public:
        Product(); // constructor
        Product(string, string); // constructor
        void setUPC(string); // sets upc data
        void setDescription(string); // sets description data
        string getUPC(); // returns upc data
        string getDescription(); // returns description data

        // displays the description
        friend ostream& operator<<(ostream& os, const Product& product) {
        os << product.description << endl;
        return os;
        }

        // compares upc less than 
        bool operator<(const Product &rhs) const {
        return this->upc < rhs.upc;
        }

        // compares upc greather than
        bool operator>(const Product &rhs) const {
        return this->upc > rhs.upc;
        }

};

// default constructor
Product::Product() {
}

// constructor
Product::Product(string _upc, string _description) {
    upc = _upc;
    description = _description;
}
void Product::setUPC(string _upc) {
    upc = _upc;
}

void Product::setDescription(string _description) {
    description = _description;
}

string Product::getUPC() {
    return upc;
}

string Product::getDescription() {
    return description;
}
#endif



