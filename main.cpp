/*
 item
 book
 cd
 dvd
 inventory
 main
 */
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;


//Item class decleration

class Item {
private:
    static int itemCount;   //keeps track of number of items for SKU creation
    double cost;            //item cost
    double price;            //item price
    string title;            //item title
    int sku;                //item sku number
    int quantity;            //item stock quantity


public:
    Item(string t = "", double c = 0.0);    //Input title and cost with defult cases


    int getSKU();            //to return info about the item instance
    int getQuantity();
    double getCost();
    double getPrice();
    string getTitle();
    static int getitemCount();

    void setCost(double c);   //To accpet
    void setTitle(string t);  //To change the title cuase its one of the varibles all the derived classes have

    void enterOrder(int q, double c);  //Function for arriving orders, inputs of quantity and cost
    void recalcPrice();     //If an order arrives with a new cost, function will change the price to match

    virtual double markupPercent() = 0;    //pure virtual function to return the markup percent for each type of function
    virtual void report() = 0;  //function for outputting report
};

#endif

//--------------------------------

#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Item class definitions

int Item::itemCount = 0;

Item::Item(string t = "", double c = 0.0) {
    sku = itemCount++;
    title = t;
    cost = c;
    recalcPrice();
}

int Item::getSKU() {
    return sku;
}

int Item::getQuantity() {
    return quantity;
}

double Item::getCost() {
    return cost;
}

double Item::getPrice() {
    return price;
}

string Item::getTitle() {
    return title;
}

static int Item::getitemCount() {
    return itemCount;
}

void Item::setCost(double c) {
    cost = c;
}

void Item::setTitle(string t) {
    title = t;
}

void Item::enterOrder(int q, double c) {
    if (q >= 0) {
        quantity += q;
    }
    if (c > 0.0) {
        setCost(c);
        recalcPrice();
    }
}

void Item::recalcPrice() {
    price = cost + cost * markupPercent();
}

//-----------------------------

#ifndef BOOK_H
#define BOOK_H
#include "Item.h"
#include <string>
using namespace std;

//Book class decleration


class Book : public Item {
private:
    string author;
    string description;
public:
    Book(string t = "", double c = 0.0, string a = "", string d = "");

    virtual double markupPercent();
    virtual void report();
};
#endif

//---------------------------

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

//-------------------------------

#ifndef CD_H
#define CD_H
#include "Item.h"
#include <string>
using namespace std;

//CD class delceration

class CD : public Item {
private:
    string artist;
    int tracks;
    double playTime;
    string genre;
public:
    CD(string t = "", double c = 0.0, string a = "", int t = 0, double p = 0.0, string g = "");

    virtual double markupPercent();
    virtual void report();

};
#endif

//---------------------------

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

//------------------------------

#ifndef DVD_H
#define DVD_H
#include "Item.h"
#include <string>
using namespace std;

//DVD class delceration

class DVD : public Item {
private:
    string director;
    string lead;
    double playTime;
    string genre;
public:
    DVD(string t = "", double c = 0.0, string d = "", string l = "", double p = 0.0, string g = "");

    virtual double markupPercent();
    virtual void report();
};
#endif

//-------------------------

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

//---------------------------

#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <string>
using namespace std;

//Inventory class header

class Inventory {
private:
    static const int MAX_ITEMS = 30;     //The max number of items
    Item* unit[MAX_ITEMS];
    

public:
    Inventory();

    int skuFinder(int s);         //Given an sku value, finds the item with that value in the inventory array

    void mainMenu();              //Outputs the main menu of the program
    void newItem();                  //Outputs menu for adding new item to inventory
    void newOrder();              //Menu for a new order
    void sale();                  //Menu for a sale
    void fullReport();            //Menu for a full report of inventory
    

};
#endif

//----------------------------

#include "Inventory.h"
#include "Book.h"
#include "CD.h"
#include "DVD.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Inventory class definitons

Inventory::Inventory() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        unit[i] = nullptr;
    }
}

Inventory::skuFinder(int s) {
    for (int i = 0; i < Item::getitemCount(); i++) {
        if (unit[i]->getSKU() == s) {
            return i;
        }
    }
    return -1;
}

void Inventory::mainMenu() {
    int choice;
    do {
        cout << "PUT THIS LATER"; //PUT STUFF HERE
        cin >> choice;

        switch (choice) {
        case 1: {
            newItem();
        }
              break;
        case 2: {
            newOrder();
        }
              break;
        case 3: {
            sale();
        }
              break;
        case 4: {
            fullReport();
        }
              break;
        case 5: {
            cout << "Exiting program..." < endl;
        }
              break;
        default: {
            cout << "Invalid input, retry" << endl;
        }

        }
    } while (choice != 5);

}

void Inventory::newItem() {
    char type;
    bool flag = false;

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (unit[i] == nullptr) {
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "No item slots available, expand inventory." << endl;
        mainMenu();
    }

    do {
        cout << "PUT THIS LATER"; //PUT STUFF HERE
        cin >> type;
        switch (type) {
        case 'B': {
            //fix: string name, title, authrer...
            //ask
            //
            //unit[Item::getitemCount()] = new Book( , , , );
            //NEW BOOK
        }
                break;
        case 'C': {
            //NEW CD
        }
                break;
        case 'D': {
            //NEW DVD
        }
                break;
        case 'M': {
            mainMenu();
        }
                break;
        default: {
            cout << "Invalid input, retry" << endl;
        }
        
        }
    } while (type != 'M');
    
}

void Inventory::newOrder() {
    bool valid = false;
    int identifer;
    int qty;
    double c;
    do {
        cout << "Enter SKU for new order: " << endl;
        cin >> identifer;
        cout << "Enter quantity recieved: " << endl;
        cin >> qty;
        cout << "Enter cost: " << endl;
        cin >> c;
        identifier = skuFinder(identifer);
        if (identifer == -1) {
            cout << "Invalid SKU entered, try again" << endl;
        }
        else {
            valid = true;
        }
    } while (valid != true);
    unit[identifer]->enterOrder(qty, c);
    mainMenu();
}

void Inventory::sale() {
    Item soldItems[20];//fix: make a constant
    int soldCount = 0;
    
//    do {
//        
//    }while
    //DO LATER
}

void Inventory::fullReport() {
    char cc = 'n';
    for (int i = 0; i < Item::getitemCount(); i++) {
        unit[i]->report();
    }
    
    do {
        cout << "Enter R to return to main menu\n";
        cin >> cc;
    } while (cc != 'r' || cc != 'R');
    //PUT SOMETHING TO RETURN TO MAIN MENU WHEN USER INPUTS SOMETHING
}


