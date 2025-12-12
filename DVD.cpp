#include "DVD.h"
#include <iostream>
using namespace std;

//DVD class definitons

DVD::DVD(string nTitle, double nCost, string nDirec, string nLead, double nPlayTime, string nGenre) : Item(nTitle, nCost) {
    director = nDirec;
    lead = nLead;
    playTime = nPlayTime;
    genre = nGenre;
}

double DVD::markupPercent() {
    return 0.4;
}

void DVD::report() {
    cout << "SKU " << getSKU() << " (DVD)" << endl;
    cout << "Number on hand:    " << getQuantity();
    if (getQuantity() < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << getCost() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Price:         $" << getPrice() << endl;
    cout << "Total $ value:          $" << (getPrice() * getQuantity()) << endl;
    cout << "Director: " << director << endl;
    cout << "Lead actor: " << lead << endl;
    cout << "Playing Time: " << playTime << endl;
    cout << "Genre: " << genre << endl;
    cout << "--------------------------" << endl;
}

void DVD::askUser() {
    string nTitle;
    double nCost;
    string nDirec;
    string nLead;
    double nPlayTime;
    string nGenre;
    cout << "Enter title: ";
    getline(cin, nTitle);
    cout << endl << "Enter director: ";
    getline(cin, nDirec);
    cout << endl  << "Enter lead actor: ";
    getline(cin, nLead);
    cout << endl << "Enter playing time: ";
    cin >> nPlayTime;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "Invalid input\n Enter playing time: ";
        cin >> nPlayTime;
    };
    cout << endl << "Enter genre: ";
    cin.ignore();
    getline(cin, nGenre);
    cout << endl << "Enter cost: ";
    cin >> nCost;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "Invalid input\n Enter cost: ";
        cin >> nCost;
    };
    
    setTitle(nTitle);
    setCost(nCost);
    director = nDirec;
    lead = nLead;
    playTime = nPlayTime;
    genre = nGenre;
    recalcPrice();
}
