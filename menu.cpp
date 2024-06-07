#include "menu.h"
#include <limits>
#include "table.h"

list<Dish> menu;

void handleInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mainMenu(Database &database) {
    bool exit_program = false;
    int choice;

    do {
        system("cls");

        cout << "\t\t\t--------------------------------" << endl;
        cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
        cout << "\t\t\t--------------------------------" << endl;
        cout << "\t\t\t 1. Manager" << endl;
        cout << "\t\t\t 2. Staff" << endl;
        cout << "\t\t\t 3. Exit program" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";

        cin >> choice;

        if (cin.fail()) {
            handleInvalidInput();
        }
        else {
            switch (choice) {
            case 1:
                menuManager(database);
                break;

            case 2:
                menuStaff(database);
                break;

            case 3:
                exit_program = true;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (!exit_program);
}

void menuManager(Database &database) {
    int choice;
    bool exit_program = false;

    do {
        system("cls");

        cout << "\t\t\t-----------" << endl;
        cout << "\t\t\t| MANAGER |" << endl;
        cout << "\t\t\t-----------" << endl;
        cout << "\t\t\t 1. Setup Table Number" << endl;
        cout << "\t\t\t 2. New Dish" << endl;
        cout << "\t\t\t 3. Edit Dish" << endl;
        cout << "\t\t\t 4. Delete Dish" << endl;
        cout << "\t\t\t 5. Dish List" << endl;
        cout << "\t\t\t 0. Back to Main Menu" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            handleInvalidInput();
        }
        else {
            switch (choice) {
            case 1: {
                bool ContinueSetup = false;
                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------- Set up table ------------------------------------------------" << endl;
                    cout << "\t\t\tEnter quantity of table you want to set up: ";
                    cin >> database.numTable;
                    
                    while (!(cin >> database.numTable) || database.numTable <= 0) {
                        cout << endl;
                        cout << "Invalid choice. Please try again." << endl;
                        cout << "Enter Your Choice: ";
                        handleInvalidInput();
                    }
                    database.managerData.SetTableNumber(database.numTable);
                    database.staffaData.getNumTable(database.numTable);

                    cout << "\t\t\t1. Back to Set up Table" << endl;
                    cout << "\t\t\t0. Back to Manager Menu" << endl;
                    cout << "\t\t\tEnter The Choice: ";
                    
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueSetup = true;
                    }
                    else if (choice == 0) {
                        ContinueSetup = false;
                    }
   
                } while (ContinueSetup);
                break;
            }

            case 2: {
                bool ContinueAdd = false;
                do
                {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------- Adding The New Dish -------------------------------------------" << endl;
                    database.managerData.NewDish();
                    cout << "\t\t\t1. Back to Adding The New Dish" << endl;
                    cout << "\t\t\t0. Back to Manager Menu" << endl;
                    cout << "\t\t\tEnter The Choice: ";
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueAdd = true;
                    }
                    else if (choice == 0) {
                        ContinueAdd = false;
                    }
                } while (ContinueAdd);
                break;
            }
            
            case 3:
            {
                bool ContinueEdit = false;

                do
                {
                    database.managerData.editDish();
                    cout << endl;
                    cout << "\t\t\t1. Back to Edit Dish" << endl;
                    cout << "\t\t\t0. Back to Manager Menu" << endl;
                    cout << "\t\t\tEnter The Choice: ";
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueEdit = true;
                    }
                    else if (choice == 0) {
                        ContinueEdit = false;
                    }
                } while (ContinueEdit);
                break;
            }

            case 4: {
                bool ContinueDelete = false;
                do
                {
                    database.managerData.DeleteDish();
                    cout << endl;
                    cout << "\t\t\t1. Back to Delete Dish" << endl;
                    cout << "\t\t\t0. Back to Manager Menu" << endl;
                    cout << "\t\t\tEnter The Choice: ";
                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                        cout << endl;
                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        ContinueDelete = true;
                    }
                    else if (choice == 0) {
                        ContinueDelete = false;
                    }
                } while (ContinueDelete);
                break;
            }

            case 5: {
                bool ValidInput = false;
                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "--------------------------------------------- Menu ------------------------------------------------------" << endl;
                    database.managerData.showMenu();
                    cout << endl;

                    cout << "\t\t\t0. Back to Manager Menu" << endl;
                    cout << "\t\t\tEnter Your Choice: ";
                    while (!(cin >> choice) || choice != 0) {
                        cout << endl;
                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        handleInvalidInput();
                    }
                    if (choice == 0) {
                        ValidInput = false;
                    }
                } while (ValidInput);
                break;
            }

            case 0:
                exit_program = true;
                break;

            default:
                break;
            }
        }
    } while (!exit_program);
}


void menuStaff(Database& database) {
    int choice;
    bool exit_program = false;
    do
    {
        bool cc = false;
        do
        {

            cout << "\t\t\t-----------" << endl;
            cout << "\t\t\t|  STAFF  |" << endl;
            cout << "\t\t\t-----------" << endl;
            cout << "\t\t\t 1. Table Status" << endl;
            cout << "\t\t\t 2. Service for Table" << endl;
            cout << "\t\t\t 0. Back to Main Menu" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (cin.fail()) {
                handleInvalidInput();
            }
            else {
                switch (choice) {
                case 1: {
                    system("cls");

                    database.staffaData.displayTable();
                    cout << endl;

                    if (database.staffaData.isFull()) {
                        cout << "\t\t\tSorry. There are no tables available." << endl;
                        cout << "\t\t\t0. Back to Main Menu" << endl;
                        cout << "\t\t\tEnter Your Choice: ";
                        while (!(cin >> choice) || choice != 0) {
                            cout << endl;
                            cout << "\t\t\tInvalid choice. Please try again." << endl;
                            cout << "\t\t\tEnter Your Choice: ";
                            handleInvalidInput();
                        }
                        return mainMenu(database);
                    }
                    else {
                        int _tableID;
                        bool ValidBook = false;
                        do
                        {
                            cout << "\t\t\tPlease choose one of these Table ID: ";
                            while (!(cin >> _tableID)) {
                                cout << endl;
                                cout << "\t\t\tInvalid choice. Please try again." << endl;
                                cout << "\t\t\tEnter Your Choice: ";
                                handleInvalidInput();
                            }
                            if (database.staffaData.chooseTable(_tableID)) {
                                cout << "\t\t\tTable " << _tableID << " has been successfully booked." << endl;
                                ValidBook = true;
                            }
                            else {
                                cout << "\t\t\tFailed to book Table " << _tableID << ". Please choose another table." << endl;
                                ValidBook = true;
                            }
                        } while (!ValidBook);

                    }
                    break;
                }

                case 2: {
                    int _tableID;
                    bool ValidBook = false;
                    if (database.staffaData.tableList.empty()) {
                        return mainMenu(database);
                    }
                    else
                    {
                        database.staffaData.displayTable();
                        cout << endl;
                        cout << "\t\t\tPlease choose one of these Table ID: ";
                        while (!(cin >> _tableID) || _tableID > database.numTable || _tableID == 0) {
                            cout << endl;
                            cout << "\t\t\tInvalid choice. Please try again." << endl;
                            cout << "\t\t\tEnter Your Choice: ";
                            handleInvalidInput();
                        }
                        cout << "\t\t\t-----------" << endl;
                        cout << "\t\t\t|  STAFF  |" << endl;
                        cout << "\t\t\t-----------" << endl;
                        cout << "\t\t\t 1. Order Dish" << endl;
                        cout << "\t\t\t 2. Cancel Dish" << endl;
                        cout << "\t\t\t 3. Change Dish" << endl;
                        cout << "\t\t\t 4. Dish list was ordered" << endl;
                        cout << "\t\t\t 5. Payment" << endl;
                        cout << "\t\t\t 0. Back to Staff Menu" << endl;
                        cout << "\t\t\t............................" << endl;
                        cout << "\t\t\tPlease Enter Your Choice: ";
                        cin >> choice;
                        if (cin.fail()) {
                            handleInvalidInput();
                        }
                        else {
                            switch (choice) {
                            case 1: {
                                bool ContinueOrder = false;
                                do
                                {
                                    cout << "--------------------------------------------- Menu ----------------------------------------------------"<< endl;
                                    database.managerData.showMenu();
                                    cout << endl << endl;
                                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                                    cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
                                    database.staffaData.getTableInfo(_tableID, 1, database.managerData.getMenu());
                                    cout << "\t\t\t1. Back to Add dish" << endl;
                                    cout << "\t\t\t0. Back to Staff Menu" << endl;
                                    cout << "\t\t\tEnter The Choice: ";
                                    /*cin >> choice;*/
                                    while (!(cin >> choice) || choice != 0 && choice != 1) {
                                        cout << endl;
                                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                                        cout << "\t\t\tEnter Your Choice: ";
                                        handleInvalidInput();
                                    }

                                    if (choice == 1) {
                                        ContinueOrder = true;
                                    }
                                    else if (choice == 0) {
                                        ContinueOrder = false;
                                    }
                                } while (ContinueOrder);
                                break;
                            }

                            case 2: {
                                bool ContinueCancel = false;
                                do
                                {
                                    database.staffaData.getTableInfo(_tableID, 4, database.managerData.getMenu());
                                    database.staffaData.getTableInfo(_tableID, 2, database.managerData.getMenu());
                                    cout << "\t\t\t1. Back to Cancel dish" << endl;
                                    cout << "\t\t\t0. Back to Staff Menu" << endl;
                                    cout << "\t\t\tEnter The Choice: ";
                                   /* cin >> choice;*/
                                    while ((!cin >> choice) || (choice != 1 && choice != 0)) {
                                        cout << endl;
                                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                                        cout << "\t\t\tEnter Your Choice: ";
                                        handleInvalidInput();
                                    }
                                    if (choice == 1) {
                                        ContinueCancel = true;
                                    }
                                    else if(choice == 0)
                                    {
                                        ContinueCancel = false;
                                    }
                                } while (ContinueCancel);
                                break;
                            }

                            case 3: {
                                bool ContinueChange = false;
                                do
                                {
                                    database.staffaData.getTableInfo(_tableID, 3, database.managerData.getMenu());
                                    cout << "\t\t\t1. Back to Cancel dish" << endl;
                                    cout << "\t\t\t0. Back to Staff Menu" << endl;
                                    cout << "\t\t\tEnter The Choice: ";
                                    while ((!cin >> choice) || (choice != 0 && choice != 1)) {
                                        cout << endl;
                                        cout << "\t\t\tInvalid choice. Please try again." << endl;
                                        cout << "\t\t\tEnter Your Choice: ";
                                        handleInvalidInput();
                                    }
                                    if (choice == 1) {
                                        ContinueChange = true;
                                    }
                                    else if (choice == 0)
                                    {
                                        ContinueChange = false;
                                    }
                                } while (ContinueChange);
                                break;
                            }

                            case 4: {
                                database.staffaData.getTableInfo(_tableID, 4, database.managerData.getMenu());
                                cout << endl;
                                cout << "\t\t\t0. Back to Staff Menu" << endl;
                                cout << "\t\t\tEnter The Choice: ";
                                cin >> choice;
                                break;
                            }

                            case 5: {
                                database.staffaData.getTableInfo(_tableID, 5, database.managerData.getMenu());
                                cout << endl;
                                cout << "\t\t\t0. Back to Staff Menu" << endl;
                                cout << "\t\t\tEnter The Choice: ";
                                cin >> choice;
                                break;
                            }

                            case 0:
                                cc = true;
                                break;

                            default:
                                break;
                            }
                        
                        }
                    }
                    break;
                }
                case 0:
                    return mainMenu(database);
                    break;

                default:
                    break;
                }
            }
        } while (cc);
        } while (!exit_program);
}
