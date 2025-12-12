
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

int Inventory::skuFinder(int fSKU) {
    for (int i = 0; i < Item::getitemCount(); i++) {
        if (unit[i]->getSKU() == fSKU) {
            return i;
        }
    }
    return -1;
}

void Inventory::mainMenu() {
    int choice;
    do {
        cout << "\n\n1)  To enter new item, enter 1\n"  <<
        "2)  To enter an order, enter 2\n" <<
        "3)  For Sale, enter 3\n" <<
        "4)  For a complete report, enter 4\n" <<
        "5)  To quit, enter 5\n"; //fix: PUT STUFF HERE
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
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 5);

}

void Inventory::newItem() {
    char type;
    int itemIndex = Item::getitemCount();
   
    if (itemIndex >= MAX_ITEMS) {
        cout << "No item slots available, expand inventory." << endl;
    }
    else {
        do {
            itemIndex = Item::getitemCount();
            cout << "B) To add a new Book, enter B\n" <<
            "C) To add a new CD, enter C\n" <<
            "D) To add a new DVD, enter D\n" <<
            "M) To return to main menu, enter M\n"; //fix: PUT STUFF HERE
            cin >> type;
            switch (type) {
                case 'B': {
                    
                    unit[itemIndex] = new Book();
                    unit[itemIndex]->askUser();
                    //I would do input gathering as a seperate function in the Book class so this doesnt get messy
                }
                    break;
                case 'C': {
                    unit[itemIndex] = new CD();
                    unit[itemIndex]->askUser();
                }
                    break;
                case 'D': {
                    unit[itemIndex] = new DVD();
                    unit[itemIndex]->askUser();
                }
                    break;
                case 'M': {}
                    break;
                default: {
                    cout << "Invalid input, retry" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        } while (type != 'M');
    }
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
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            valid = true;
        }
    } while (valid != true);
    unit[identifer]->enterOrder(qty, c);
}

void Inventory::sale() {
    int SKUnum [20], qtySold [20];
    char flag = ' ';
    int numOrders = 0;
    double total = 0;
    do {
        if (numOrders >= 20) {
            cout << "Maximum number of different items per sale reached." <<endl;
            flag = 't';
        }
        else {
            cout << "SKU: " << endl;
            cin >> SKUnum[numOrders];
            cout << "Quantity: " << endl;
            cin >> qtySold[numOrders];
            numOrders++;
            cout << "Enter t to go to receipt, any other key to continue: " << endl;
            cin >> flag;
        }
    } while (flag != 't' && flag != 'T');
    
    for (int i = 0; i < numOrders; i++) {
        cout << SKUnum[i];
        flag = 'y';
        if (qtySold[i] > unit[skuFinder(SKUnum[i])]->getQuantity()) {
            qtySold[i] = unit[skuFinder(SKUnum[i])]->getQuantity();
            flag = 'n';
        }
        cout << "   " << qtySold[i] << "   $"  << unit[skuFinder(SKUnum[i])]->getPrice() << "   $" << qtySold[i] * unit[skuFinder(SKUnum[i])]->getPrice();
        if (flag == 'n') {cout << "Selling all available stock" << endl;}
        else {cout << endl;}
        total += qtySold[i] * unit[skuFinder(SKUnum[i])]->getPrice();
    }
    cout << "Total:      $" << total << endl;
    cout << "Tax:    $" << total * 0.0925 << endl;
    cout << "Subtotal:   $" << total + total * 0.0925 << endl;
}
void Inventory::fullReport() {
    char cc = 'n';
    for (int i = 0; i < Item::getitemCount(); i++) {
        unit[i]->report();
    }
    
    do {
        cout << "Enter R to return to main menu\n";
        cin >> cc;
    } while (cc != 'r' && cc != 'R');
}


Inventory::~Inventory()
{
    for (int i = 0; i < Item::getitemCount(); i++) {
        delete unit[i];
        unit[i] = nullptr;
    }
};
