#include "Item.h"
#include "Book.h"
#include "CD.h"
#include "DVD.h"
#include "Inventory.h"

int main() {
    Inventory storeInventory;
    storeInventory.mainMenu();
    return 0;
}
    


//fix:
/*
 - fix int or double values being entered -> error checking
 - fix cin for getline -> use cin.ignore()
 - fix memory leaks -> delete items in inventory destructor
 -add lower case for switch sratement
 
 
 
 note: "fixed << setprecision(2) " makes the decimal places 2 for dollar amounts - i added one in the cd report function, make sure to add to others
 */
