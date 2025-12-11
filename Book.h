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
