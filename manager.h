/*
* File: Manager.h
* Description: This file is a manager header file that program is used for storing manager's information
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include<list>
#include<string>
#include"dish.h"

using namespace std;

/*
* Class: Manager
* Description: This class contains basic properties and methods of a Manager object
*/
class Manager {
private:
	int number_table;
	list<Dish> menu;

public:
	Manager() : number_table(0) {}

	Manager(int& number_table, list<Dish>& menu) : number_table(number_table), menu(menu) {}

	void SetTableNumber(int number); // Number of table that can be served

	void NewDish(); 

	void editDish();

	void DeleteDish();

	void showMenu();

	list <Dish>getMenu();
};

#endif 
