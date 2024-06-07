/*
* File: table.h
* Description: This file is a dish header file that program is used for storing table's information
*/

#ifndef _TABLE_H
#define _TABLE_H

#include "dish.h"
#include <list>
#include "manager.h"

using namespace std;

typedef enum  {
	Booked,
	Free
}Status;

class Table {
private:
	int TableID;
	Status status;
	list<Order> OrderList;
	int TotalBill;

public:
	Table() {
		static int _TableID = 1;
		TableID = _TableID;
		_TableID++;
		
		status = Free;
		TotalBill = 0; 
	}

	void ResetTable();

	void SetStatusTable(Status _status);
	Status GetStatusTable();

	void SetTableID(int _tableID);
	int GetTableID();

	void OrderDish(list<Dish> menu);

	void CancelDish(); 

	void EditDish(list<Dish> &menu);

	void GetOrderList();

	void GetBill();
};

#endif // !_TABLE_H
