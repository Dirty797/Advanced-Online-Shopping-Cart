#include "ShoppingCart.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void PrintMenu();
void ExecuteMenu(char option, ShoppingCart& cart);

int main() {
    string customerName, date;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);

    cout << "Enter today's date:\n" << endl;
    getline(cin, date);

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;

    ShoppingCart myCart(customerName, date);

    string input;
    char option = ' ';
    PrintMenu(); // Print menu at the start
    while (option != 'q') {
        getline(cin, input);

        if (input.length() == 0) {
            cout << "Choose an option:" << endl;
            continue;
        }

        option = input[0];

        // Only execute the menu if the input is a valid option
        if (option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o' || option == 'q') {
            ExecuteMenu(option, myCart);
            if (option != 'q') {
                PrintMenu(); // Only print menu after a valid action
            }
        } else {
            cout << "Choose an option:" << endl;
        }
    }

    return 0;
}

void PrintMenu() {
    cout << endl << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << "\n" << endl;
    cout << "Choose an option:" << endl;
}

void ExecuteMenu(char option, ShoppingCart& cart) {
    switch(option) {
        case 'a': {
            string name, description;
            int price, quantity;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            cin >> price;
            cout << "Enter the item quantity:" << endl;
            cin >> quantity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ItemToPurchase newItem(name, description, price, quantity);
            cart.AddItem(newItem);
            break;
        }
        case 'd': {
            string name;
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, name);
            cart.RemoveItem(name);
            break;
        }
        case 'c': {
            string name;
            int quantity;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            cout << "Enter the new quantity:" << endl;
            cin >> quantity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            ItemToPurchase modifiedItem(name, "", 0, quantity);
            cart.ModifyItem(modifiedItem);
            break;
        }
        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.PrintDescriptions();
            break;
        case 'o':
            cout << "OUTPUT SHOPPING CART" << endl;
            cart.PrintTotal();
            break;
        case 'q':
            break;
        default:
            cout << "Invalid option. Please choose again." << endl;
            break;
    }
}
