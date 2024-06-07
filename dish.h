/*
* File: dish.h
* Description: This file is a dish header file that program is used for storing dish's information
*/

#ifndef _DISH_H
#define _DISH_H
#include<iostream>
#include<string>

using namespace std;

class Dish {
private:
	string Name;
	int Price;
	int ID;

public:
	Dish() : Name(""), Price(0), ID() {
		static int _ID = 101;
		ID = _ID;
		_ID++;
	}

	void SetName(string _name);
	string GetName();

	void SetPrice(int _price);
	int GetPrice();

	int getDishID();
	void SetDishID(int _ID);

};

typedef struct {
	int num;
	Dish dish;
} Order;

#endif
