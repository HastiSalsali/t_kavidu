
#include "Item.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Item class definitions

int Item::itemCount = 0;

Item::Item(string t = "", double c = 0.0) {
    sku = itemCount++;
    title = t;
    cost = c;
    recalcPrice();
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

static int Item::getitemCount() {
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
