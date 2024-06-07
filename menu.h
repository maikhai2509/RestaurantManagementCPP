#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include "manager.h"
#include "staff.h"

using namespace std;

enum Title {
    managerWork,
    staffWork
};

typedef struct {
    int numTable;
    Manager managerData;
    Staff staffaData;
}Database;

void mainMenu(Database &database);

void menuManager(Database &database);

void menuStaff(Database &database);

void handleInvalidInput();

#endif
