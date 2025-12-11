
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

int Inventory::skuFinder(int s) {
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
            case 1:
                newItem();
                break;
                
            case 2:
                newOrder();
                break;
                
            case 3:
                sale();
                break;
                
            case 4:
                fullReport();
                break;
                
            case 5:
                cout << "Exiting program..." << endl;
                break;
                
            default:
                cout << "Invalid input, retry" << endl;
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
        identifer = skuFinder(identifer);
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
    Item* soldItems[20];//fix: make a constant
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


