#include"table.h"
#include<iomanip>

extern void handleInvalidInput();

void Table::ResetTable() {
    OrderList.clear();
    cout << "Table reset successful." << endl;
}

void Table::SetStatusTable(Status _status) {
	status = _status;
}

Status Table::GetStatusTable() {
	return status;
}

void Table::SetTableID(int _tableID) {
	TableID = _tableID;
}

int Table::GetTableID() {
	return TableID;
}

void Table::OrderDish(list<Dish> listDish) {
    Order neworder;
    bool Found = false;
    int quantity = 0;

    int ID_Input;
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;
    while ((!cin >> ID_Input)) {
        cout << endl;
        handleInvalidInput();
    }

    for (list<Dish>::iterator it = listDish.begin(); it != listDish.end(); ++it) {
        if (it->getDishID() == ID_Input) {
            cout << "Dish Found." << endl;
            neworder.dish = *it;
            cout << "Enter quantity of dish you want: ";
            cin >> quantity;
            while ((!cin >> quantity)) {
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
                cout << "Enter Your Choice: ";
                handleInvalidInput();
            }
            neworder.num = quantity;

            OrderList.push_back(neworder);
            Found = true; 
            break;
        }
    }

    if (!Found) {
        cout << "No Dish Found. Please try again." << endl;
    }
}

void Table::CancelDish() {
    int ID_Input;
    int quantity;
    int choice;
    if (OrderList.empty()) {
        cout << "Order List is empty. Press 0 to continue: ";
        cin >> choice;
        while ((!cin >> choice) || choice != 0) {
            cout << endl;
            cout << "Invalid choice. Please try again." << endl;
            cout << "Enter Your Choice: ";
            handleInvalidInput();
        }
        return;
    }
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;

    bool found = false;
    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end(); ++it) {
        if (it->dish.getDishID() == ID_Input) {
            found = true;
            cout << "Dish Found." << endl;
            cout << "Enter quantity of dish you want to cancel: ";
            cin >> quantity;
            while ((!cin >> quantity)) {
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
                cout << "Enter Your Choice: ";
                handleInvalidInput();
            }

            if (quantity >= it->num) {
                cout << "Cancelled all " << it->dish.GetName() << " from the order." << endl;
                OrderList.erase(it);
            }
            else {
                it->num -= quantity;
                cout << "Cancelled " << quantity << " " << it->dish.GetName() << " from the order." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "No Dish Found. Please try again." << endl;
    }
}

void Table::EditDish(list<Dish> &listDish) {
    int ID_Input;
    cout << "Enter ID of the dish: ";
    cin >> ID_Input;

    bool found = false;

    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end();) {
        if (it->dish.getDishID() == ID_Input) {
            found = true;
            cout << "Dish Found." << endl;

            cout << "Cancelled all " << it->dish.GetName() << " from the order." << endl;
            it = OrderList.erase(it);
        }
        else {
            ++it; // Di chuy?n con tr? d?n ph?n t? ti?p theo n?u không tìm th?y
        }
    }

    if (!found) {
        cout << "No Dish Found in the current order." << endl;
    }

    // Gi? s? danh sách menu dã du?c cung c?p t? noi khác

    cout << "Enter ID of the dish: ";
    cin >> ID_Input;
    for (list<Dish>::iterator it = listDish.begin(); it != listDish.end(); ++it) {
        if (it->getDishID() == ID_Input) {
            cout << "Dish Found." << endl;
            Order neworder;
            neworder.dish = *it;
            cout << "Enter quantity of dish you want: ";
            int quantity;
            cin >> quantity;
            neworder.num = quantity;

            OrderList.push_back(neworder);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No Dish Found in the menu. Please try again." << endl;
    }
}


void Table::GetOrderList(){
    if (OrderList.empty()) {
        cout << "The list order is empty." << endl;
        return;
    }
    cout << "List order of The Dish" << endl;
    cout << "Ordinals| ID\t\t| Dish Name\t\t| Price\t\t| Quantity\t\t" << endl;
    int stt = 1;
    for (list<Order>::iterator it = OrderList.begin(); it != OrderList.end(); ++it) {
        cout << setw(3) << left << stt++ << "\t|  ";
        cout << setw(5) << left << it->dish.getDishID() << "\t|  ";
        cout << setw(15) << left << it->dish.GetName() << "\t|  ";
        cout << setw(5) << left << it->dish.GetPrice() << "\t|  ";
        cout << setw(5) << left << it->num << "\t|  ";
        cout << endl;
    }
}

void Table::GetBill() { 
    int _TotalBill = 0;
    for (list<Order>::iterator i = OrderList.begin(); i != OrderList.end(); i++) {
        _TotalBill += i->dish.GetPrice() * i->num;
    }

    GetOrderList();
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << _TotalBill << endl;
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << 1.1 * _TotalBill << endl; 
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    int ans = 0;
    do {
        cout << "\n\n\t\t\t1. Pay away" << endl;
        cout << "\t\t\t2. Turn back" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> ans;
    } while (ans != 1);

    ResetTable();
}
