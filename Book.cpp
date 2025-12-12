#include "Book.h"
#include <iostream>
using namespace std;

//Book class definitions

Book::Book(string nTitle, double nCost, string nAuthor, string nDscrb) : Item(nTitle, nCost) {
    author = nAuthor;
    description = nDscrb;
}

double Book::markupPercent() {
    return 0.25;
}

void Book::report() {
    cout << "SKU " << getSKU() << " (Book)" << endl;
    cout << "Number on hand:    " << getQuantity();
    if (getQuantity() < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << getCost() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Price:         $" << getPrice() << endl;
    cout << "Total $ value:          $" << (getPrice() * getQuantity()) << endl;
    cout << "Author: " << author << endl;
    cout << "Description: " << description << endl;
    cout << "--------------------------" << endl;
}

void Book::askUser() {
    string nTitle;
    double nCost;
    string nAuthor;
    string nDscrb;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter title:";
    getline(cin, nTitle);
    cout << endl << "Enter author: ";
    getline(cin, nAuthor);
    cout << endl  << "Enter description: ";
    getline(cin, nDscrb);
    cout << endl << "Enter cost: ";
    cin >> nCost;
    
    setTitle(nTitle);
    setCost(nCost);
    author = nAuthor;
    description = nDscrb;
    recalcPrice();
}
    
