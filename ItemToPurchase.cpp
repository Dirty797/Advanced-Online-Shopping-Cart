#include "ItemToPurchase.h"
#include <iostream>

using namespace std;

// Parameterized constructor
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity)
    : itemName(name), itemDescription(description), itemPrice(price), itemQuantity(quantity) {}

void ItemToPurchase::SetName(string name) { itemName = name; }
string ItemToPurchase::GetName() const { return itemName; }

void ItemToPurchase::SetDescription(string description) { itemDescription = description; }
string ItemToPurchase::GetDescription() const { return itemDescription; }

void ItemToPurchase::SetPrice(int price) { itemPrice = price; }
int ItemToPurchase::GetPrice() const { return itemPrice; }

void ItemToPurchase::SetQuantity(int quantity) { itemQuantity = quantity; }
int ItemToPurchase::GetQuantity() const { return itemQuantity; }

void ItemToPurchase::PrintItemCost() const {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice
         << " = $" << (itemPrice * itemQuantity) << endl; 
    
}

void ItemToPurchase::PrintItemDescription() const {
    cout << itemName << ": " << itemDescription << endl;
}
