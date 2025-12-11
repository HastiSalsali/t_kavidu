#include "DVD.h"
#include <iostream>
using namespace std;

//DVD class definitons

DVD:DVD(string t = "", double c = 0.0, string d = "", string l = "", double p = 0.0, string g = "") : Item(t, c) {
    director = d;
    lead = l;
    playTime = p;
    genre = g;
}

double DVD::markupPercent() {
    return 0.4;
}

void DVD::report() {
    cout << "SKU " << sku << " (DVD)" << endl;
    cout << "Number on hand:    " << quantity;
    if (quantity < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << cost << endl;
    cout << "Title: " << title << endl;
    cout << "Price:         $" << price << endl;
    cout << "Total $ value:          $" << (price * quantity) << endl;
    cout << "Director: " << director << endl;
    cout << "Lead actor: " << lead << endl;
    cout << "Playing Time: " << playTime << endl;
    cout << "Genre: " << genre << endl;
    cout << "--------------------------" << endl;
}
