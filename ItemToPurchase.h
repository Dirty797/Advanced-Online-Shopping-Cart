#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
#include <iostream>

using namespace std;

class ItemToPurchase {
public:
    // Parameterized constructor with default values
    ItemToPurchase(string name = "none", string description = "none", int price = 0, int quantity = 0);

    // Setters
    void SetName(string name);
    void SetDescription(string description);
    void SetPrice(int price);
    void SetQuantity(int quantity);

    // Getters
    string GetName() const;
    string GetDescription() const;
    int GetPrice() const;
    int GetQuantity() const;

    // Print functions
    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif
