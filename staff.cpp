/*
* File: staff.cpp
* Description: This file contains all the functions/methods to store staff's information
*/
#include "staff.h"
using namespace std;

void Staff::getNumTable(int _numTable) {
    for (int i = 0; i < (_numTable); i++) {
        Table newTable;
        tableList.push_back(newTable);
    }
}

void Staff::displayTable() {
    cout << "Table ID" << "\t\t";
    for (int i = 0; i < tableList.size(); i++) {
        cout << i + 1 << "\t";
    }

    cout << "\n Status " << "\t\t";
    for (vector<Table>::iterator it = Staff::tableList.begin(); it != Staff::tableList.end(); ++it) {
        if (it->GetStatusTable() == Free) {
            cout << "O" << "\t";
        }
        else cout << "X" << "\t";
    }

    cout << "\n\nX means booked";
    cout << "\nO means free";
}

bool Staff::isFull() {
    for (vector<Table>::iterator it = Staff::tableList.begin(); it != Staff::tableList.end(); ++it) {
        if (it->GetStatusTable() == Free) return false;
    }
    return true;
}

bool Staff::chooseTable(int _tableID) {
    for (vector<Table>::iterator i = Staff::tableList.begin(); i != Staff::tableList.end(); ++i) {
        if (i->GetTableID() == _tableID && i->GetStatusTable() == Free) {
            i->SetStatusTable(Booked);
            return true;
        }
    }
    return false;
}



void Staff::getTableInfo(int _tableID, int type, list <Dish> menu) {
    for (vector<Table>::iterator i = Staff::tableList.begin(); i != Staff::tableList.end(); ++i) {
        if (i->GetTableID() == _tableID) {
            switch (type) {
            case 1: // g?i
                i->OrderDish(menu);
                break;
            case 2: // h?y
                i->CancelDish();
                break;
            case 3: // thay d?i
                i->EditDish(menu);
                break;
            case 4: // in ra danh sách 
                i->GetOrderList();
                break;
            case 5:
                i->GetBill();
                break;
            default:
                break;
            }
        }
    }
}
