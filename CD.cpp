#include "CD.h"
#include <iostream>
using namespace std;

//CD class definitons

CD:CD(string t = "", double c = 0.0, string a = "", int t = 0, double p = 0.0, string g = "") : Item(t, c) {
    artist = a;
    tracks = t;
    playTime = p;
    genre = g;
}

double CD::markupPercent() {
    return 0.3;
}

void CD::report() {
    cout << "SKU " << sku << " (CD)" << endl;
    cout << "Number on hand:    " << quantity;
    if (quantity < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << cost << endl;
    cout << "Title: " << title << endl;
    cout << "Price:         $" << price << endl;
    cout << "Total $ value:          $" << (price * quantity) << endl;
    cout << "Artist Name: " << artist << endl;
    cout << "Tracks: " << tracks << endl;
    cout << "Playing Time: " << playTime << endl;
    cout << "Genre: " << genre << endl;
    cout << "--------------------------" << endl;
}
