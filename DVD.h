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
    DVD(string nTitle = "", double nCost = 0.0, string nDirec = "", string nLead = "", double nPlayTime = 0.0, string nGenre = "");

    virtual double markupPercent();
    virtual void report();
    virtual void askUser();
    
    ~DVD(){};
};
#endif
