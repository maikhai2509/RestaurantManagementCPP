/*
* File: manager.cpp
* Description: This file contains all the functions/methods to store manager's information
*/

#include "manager.h"
#include <iomanip>
#include <iostream>
#include <limits>

list<Dish> Manager::getMenu() {
    return menu;
}

/*
* Function: SetTable
* Description: This function is used for setting the table
* Input:   number
* Output:  return: none
*/
void Manager::SetTableNumber(int number) {
    number_table = number;
}

/*
* Function: NewDish
* Description: This function is used for creating a new dish
* Input:   dish
* Output:  return: none
*/
void Manager::NewDish() {
    Dish newdish;
    cout << "\t\t\tEnter the new dish name: ";
    string name_;
	
	cin.ignore();
    getline(cin, name_);
    newdish.SetName(name_);

    int price_;
    bool ValidInput = false;
    do
    {
        cout << "\t\t\tEnter the new price: ";
        cin >> price_;
        if (cin.fail()) {
            cout << "Invalid input! Please enter again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (price_ < 0 || price_ > 100000000) {
            cout << "Invalid choice! Price must be between 0 and 100000000." << endl;
        }
        else {
            ValidInput = true;
        }
    } while (!ValidInput);
    newdish.SetPrice(price_);

    menu.push_back(newdish);
}

/*
* Function: showmenu
* Description: This function is used for Display list of dishes
* Input:	menu
* Output:	none
*/

void Manager::showMenu() {
    int count = 0;
    if (menu.empty()) {
        cout << endl;
        cout << "The menu is empty." << endl;
        return;
    }
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tMENU" << endl << endl;
    cout << "No" << "\t\tID" << "\t\tName" << "\t\tPrice" << endl;
    
    for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
        count++;
        cout << count << "\t\t" << it->getDishID() << "\t\t" << it->GetName() << "\t\t" << it->GetPrice() << endl;
    }
}

/*
* Function: EditDish
* Description: This function is used for Edit a dish
* Input:   dish
* Output:  return: none
*/
    void Manager::editDish() {
        showMenu();
        int ID_Input;
        cout << "\t\t\tEnter the ID of the dish you want to modify: ";
        while (!(cin >> ID_Input)) {
            cout << endl;
            cout << "\t\t\tInvalid choice. Please try again." << endl;
            cout << "\t\t\tEnter ID from Menu: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
            if (it->getDishID() == ID_Input) {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\tData is founded " << endl << endl;
                cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
                cout << it->getDishID() << "\t\t\t" << it->GetName() << "\t\t\t" << it->GetPrice();
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

                cout << "\n\t\t\tPlease enter Price of dish you want to change: ";
                int _price = 0; 
                cin >> _price;
                while (cin.fail() ||_price < 0 || _price > 100000000) {
                    cout << "Invalid choice! Please try again" << endl;
                    cout << "Please enter Price of dish you want to change: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> _price;
                }
                it->SetPrice(_price);
                cout << "The price updated successfully!" << endl;
                cout << endl;
                return;
            }
        }

        cout << "\t\t\tNo Dish Found in the Menu !!" << endl;
    }

/*
* Function: DeleteDish
* Description: This function is used for Delete a dish
* Input:   dish
* Output:  return: none
*/
    void Manager::DeleteDish() {
        int ID_input;
        cout << "Enter the ID of the dish you want to delete: ";
        while (!(cin >> ID_input)) {
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
            cout << "Enter ID from Menu: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (list<Dish>::iterator it = menu.begin(); it != menu.end(); ++it) {
            if (it->getDishID() == ID_input) {
                menu.erase(it);
                cout << "Dish ID " << ID_input << " has been deleted sucessfully" << endl;
                return;
            }
        }

        cout << "No Dish with ID " << ID_input << " found in the database" << endl;
    }
