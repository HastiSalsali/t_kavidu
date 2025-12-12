
#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Item class definitions

int Item::itemCount = 0;

Item::Item(string nTitle, double nCost) {
    sku = itemCount++;
    title = nTitle;
    cost = nCost;
    price = 0;
}

int Item::getSKU() {
    return sku;
}

int Item::getQuantity() {
    return quantity;
}

double Item::getCost() {
    return cost;
}

double Item::getPrice() {
    return price;
}

string Item::getTitle() {
    return title;
}

int Item::getitemCount() {
    return itemCount;
}

void Item::setCost(double c) {
    cost = c;
}

void Item::setTitle(string t) {
    title = t;
}

void Item::enterOrder(int q, double c) {
    if (q >= 0) {
        quantity += q;
    }
    if (c > 0.0) {
        setCost(c);
        recalcPrice();
    }
}

void Item::recalcPrice() {
    price = cost + cost * markupPercent();
}
