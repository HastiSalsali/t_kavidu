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
    Book(string nTitle = "", double nCost = 0.0, string nAuthor = "", string nDscrb = "");
    
    virtual double markupPercent();
    virtual void report();
    virtual void askUser();
    
    ~Book(){};
};
#endif
