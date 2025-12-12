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
    CD (string nTitle = "N/A" , double nCost = 0.0, string nArtist = "N/A", int nTrack = 0, double nPlayTime = 0.0, string nGenre = "N/A");
    
    virtual double markupPercent();
    virtual void report();
    virtual void askUser();
    
    ~CD(){};
};
#endif
