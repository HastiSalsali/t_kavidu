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
