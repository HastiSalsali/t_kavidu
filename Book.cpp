#include "Book.h"
#include <iostream>
using namespace std;

//Book class definitions

Book::Book(string t = "", double c = 0.0, string a = "", string d = "") : Item(t, c) {
    author = a;
    description = d;
}

double Book::markupPercent() {
    return 0.25;
}

void Book::report() {
    cout << "SKU " << sku << " (Book)" << endl;
    cout << "Number on hand:    " << quantity;
    if (quantity < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << cost << endl;
    cout << "Title: " << title << endl;
    cout << "Price:         $" << price << endl;
    cout << "Total $ value:          $" << (price * quantity) << endl;
    cout << "Author: " << author << endl;
    cout << "Description: " << description << endl;
    cout << "--------------------------" << endl;
}
