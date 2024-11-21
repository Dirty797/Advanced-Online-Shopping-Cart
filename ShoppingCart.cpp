#include "ShoppingCart.h"
#include <iostream>

using namespace std;

// Constructor
ShoppingCart::ShoppingCart(string customerName, string date)
    : customerName(customerName), currentDate(date) {}

string ShoppingCart::GetCustomerName() const { return customerName; }
string ShoppingCart::GetDate() const { return currentDate; }

void ShoppingCart::AddItem(const ItemToPurchase& item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string itemName) {
    bool item_found = false;
    for (auto it = cartItems.begin(); it != cartItems.end(); ++it) {
        if (it->GetName() == itemName) {
            cartItems.erase(it);
            item_found = true;
            break;
        }
    }
    if (!item_found) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
    for (auto& cartItem : cartItems) {
        if (cartItem.GetName() == item.GetName()) {
            if (!item.GetDescription().empty()) {
                cartItem.SetDescription(item.GetDescription());
            }
            if (item.GetPrice() != 0) {
                cartItem.SetPrice(item.GetPrice());
            }
            if (item.GetQuantity() != 0) {
                cartItem.SetQuantity(item.GetQuantity());
            }
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() const {
    int total_quantity = 0;
    for (const auto& item : cartItems) {
        total_quantity += item.GetQuantity();
    }
    return total_quantity;
}

int ShoppingCart::GetCostOfCart() const {
    int total_cost = 0;
    for (const auto& item : cartItems) {
        total_cost += item.GetQuantity() * item.GetPrice();
    }
    return total_cost;
}

void ShoppingCart::PrintTotal() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;

    int numItems = GetNumItemsInCart();
    cout << "Number of Items: " << numItems << endl;
    cout << "\n";

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    } else {
        for (const auto& item : cartItems) {
            item.PrintItemCost();
        }
    }

    cout << "\nTotal: $" << GetCostOfCart() << endl;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << "\n" << endl;
    cout << "Item Descriptions" << endl;
    for (const auto& item : cartItems) {
        item.PrintItemDescription();
    }
}
