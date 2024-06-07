/*
* File: staff.h
* Description: This file is a table header file that program is used for storing staff's information
*/

#ifndef _STAFF_H
#define _STAFF_H

#include <vector>
#include "table.h"

using namespace std;

class Staff {
public:
    vector<Table> tableList;

    Staff() {}

    void getNumTable(int _numTable);

    void displayTable(); // hi?n th? t?t c? table dc set up 
    bool isFull(); // ki?m tra có full bàn không 

    //void chooseTable(int _tableID); // hi?n ra nh?ng bàn còn tr?ng, s? dc l?a id bàn
    bool chooseTable(int _tableID);
    void getTableInfo(int _tableID, int type, list <Dish> menu);
};

#endif
