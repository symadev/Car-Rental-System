#include <iostream>2
#include "CarRentalSystem.h"

using namespace std;

CarRentalSystem carRentalSystem;

int main()
{
    cout << ":::::::::::::::::: WELCOME TO CAR RENTAL SYSTEM ::::::::::::::::::" << endl;

    int chooseMenu = 0;

    cout << "1. RENT A CAR" << endl;
    cout << "2. CAR RENT LIST" << endl;
    cout << "3. LOGOUT" << endl;

    while (true) {
    
        cout << "\nCHOOSE MENU: ";
        cin >> chooseMenu;

        switch(chooseMenu) {
            case 1: 
                carRentalSystem.carRent();
            break;

            case 2:
                carRentalSystem.carRentList();
            break;

            case 3:
            cout << "LOGOUT..." << endl;
            return 0;
            break;

            default:
            cout << "CHOOSE MENU IS INVALID" << endl;
        }
    }

    return 0;
}