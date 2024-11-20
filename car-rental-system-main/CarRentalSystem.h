#include "File.h"
#include "Table.h"

using namespace std;

class CarRentalSystem
{
private:
    int n;
    int m;
    vector< vector<string> > matrix;
    string id;
    string car;
    string model;
    string color;
    string speed;
    string price;
    string customer;
    string mobile;

public:
    CarRentalSystem() {
    
    }

    void carRent() {
        this->carList();
    }

    void carRentList() {

        File file("data/rent-list.csv");

        cout << "CAR RENT LIST: " << endl;
        int columWidth[] = {8, 24, 15, 20, 10, 10, 10, 12};
        string heading[] = {"ID", "CUSTOMER NAME", "PHONE", "CAR NAME", "MODEL", "COLOR", "SPEED", "PRICE"};

        Table table;
        table.setColumnWidth(columWidth);
        table.setColumnSize(8);
        table.setHeading(heading);
        table.setData(file.getRecords());
        table.show();
    }
private:
    void carList() {
        File file("data/car-list.csv");

        cout << "CAR LIST AND DETAIL: " << endl;

        int columWidth[] = {8, 20, 10, 10, 10, 12};
        string heading[] = {"ID", "CAR NAME", "MODEL", "COLOR", "SPEED", "PRICE"};

        Table table;
        table.setColumnWidth(columWidth);
        table.setColumnSize(6);
        table.setHeading(heading);
        table.setData(file.getRecords());
        table.show();

        cout << "\n";

        char next;

        do {
            this->chooseCar();
            cout << "\tDO YOU WANT TO NEW RENT? [y / n]: ";
            cin >> next;
            cout << "\n";
        } while (next == 'Y' || next == 'y');
    }

    void chooseCar() {
        int chooseMenu;
        bool notFound = true;

        cout << "SELECT ID: ";
        cin >> chooseMenu;
    
        File file("data/car-list.csv");
        this->matrix = file.getRecords();

        for (this->n = 0; this->n < this->matrix.size(); n++) {
            if (chooseMenu == stoi(this->matrix[this->n][0])) {
                notFound = false;
                this->id = this->matrix[this->n][0];
                this->car = this->matrix[this->n][1];
                this->model = this->matrix[this->n][2];
                this->color = this->matrix[this->n][3];
                this->speed = this->matrix[this->n][4];
                this->price = this->matrix[this->n][5];
                break;
            }
        }

        if (notFound == true) {
            cout << "INVALID YOUR SELECTED ID" << endl;
        } else {
            cout << "CAR DETAIL & RENT PRICE" << endl;

            cout << "\tID        : " << this->id << endl;
            cout << "\tCAR NAME  : " << this->car << endl;
            cout << "\tMODEL     : " << this->model << endl;
            cout << "\tCOLOR     : " << this->color << endl;
            cout << "\tSPEED     : " << this->speed << endl;
            cout << "\tPRICE     : " << this->price << endl;
            
            this->booking();
        }
    }

    void booking() {
        
        cin.ignore();
        cout << "\n\tCUSTOMER NAME : "; getline(cin, this->customer);
        cout << "\tMOBILE NUMBER   : "; getline(cin, this->mobile);

        this->saveBooking();
    }

    string getNextId() {
        File file("data/rent-list.csv");
        this->matrix = file.getRecords();

        return to_string(this->matrix.size() + 1);
    }

    void saveBooking() {
        string record = this->getNextId() + ',' + this->customer + ',' + this->mobile + ',' + this->car + ',' + this->model + ',' + this->color + ',' + this->speed + ',' + this->price;
        File file("data/rent-list.csv");
        file.setRecord(record);

        cout << "ORDER IS COMPLETED" << endl;
    }
};