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
    Item(string nTitle = "", double nCost = 0.0);    //Input title and cost with defult cases


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
    virtual void askUser() = 0;
    
    virtual ~Item(){};
};

#endif
