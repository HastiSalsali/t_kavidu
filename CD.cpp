#include "CD.h"
#include <iostream>
using namespace std;

//CD class definitons

CD::CD(string nTitle, double nCost, string nArtist, int nTrack, double nPlayTime, string nGenre) : Item(nTitle, nCost) {
    artist = nArtist;
    tracks = nTrack;
    playTime = nPlayTime;
    genre = nGenre;
}

double CD::markupPercent() {
    return 0.3;
}

void CD::report() {
    cout << "SKU " << getSKU() << " (CD)" << endl;
    cout << "Number on hand:    " << getQuantity();
    if (getQuantity() < 10) {
        cout << "     (Low Inventory, Place Order)";
    }
    cout << endl << "Cost:      $" << getCost() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Price:         $" << getPrice() << endl;
    cout << "Total $ value:          $" << (getPrice() * getQuantity()) << endl;
    cout << "Artist Name: " << artist << endl;
    cout << "Tracks: " << tracks << endl;
    cout << "Playing Time: " << playTime << endl;
    cout << "Genre: " << genre << endl;
    cout << "--------------------------" << endl;
}

void CD::askUser() {
    string nTitle;
    double nCost;
    string nArtist;
    int nTrack;
    double nPlayTime;
    string nGenre;
    cout << "Enter title: ";
    getline(cin, nTitle);
    cout << endl << "Enter artist: ";
    getline(cin, nArtist);
    cout << endl  << "Enter number of tracks: ";
    cin >> nTrack;
    cout << endl << "Enter playing time: ";
    cin >> nPlayTime;
    cout << endl << "Enter genre: ";
    cin.ignore();
    getline(cin, nGenre);
    cout << endl << "Enter cost: ";
    cin >> nCost;
    setTitle(nTitle);
    setCost(nCost);
    artist = nArtist;
    tracks = nTrack;
    playTime = nPlayTime;
    genre = nGenre;
    recalcPrice();
}
    
    
