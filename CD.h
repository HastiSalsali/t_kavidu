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
