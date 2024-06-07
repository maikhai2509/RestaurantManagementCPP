#include"dish.h"
using namespace std;

void Dish::SetName(string _name) {
	Name = _name;
}

string Dish::GetName() {
	return Name;
}

void Dish::SetPrice(int _price) {
	Price = _price;
}

int Dish::GetPrice() {
	return Price;
}

int Dish::getDishID() {
	return ID;
}

void Dish::SetDishID(int _ID) {
	ID = _ID;
}
