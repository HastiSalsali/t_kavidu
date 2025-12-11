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
