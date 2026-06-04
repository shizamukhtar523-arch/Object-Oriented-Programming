#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"
#include "RentalSystem.h"

using namespace std;

int main()
{
    RentalSystem system;

    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << " VEHICLE RENTAL SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Add Vehicle\n";
        cout << "2. Register Customer\n";
        cout << "3. Rent Vehicle\n";
        cout << "4. Return Vehicle\n";
        cout << "5. Display Vehicles\n";
        cout << "6. Display Customers\n";
        cout << "7. Print Summary\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');

            cout << "Invalid Input!" << endl;
            continue;
        }

        switch(choice)
        {
        	case 1:
{
    int type;
    string model;
    double rate;

    cout << "\n===== ADD VEHICLE =====\n";
    cout << "1. Car\n";
    cout << "2. Motorbike\n";
    cout << "3. Truck\n";

    cout << "Select Vehicle Type: ";
    cin >> type;

    if(type == 1)
    {
        int choice;
        int seats;

        cout << "\nSelect Car Model\n";
        cout << "1. Toyota Corolla\n";
        cout << "2. Honda Civic\n";
        cout << "3. Suzuki Alto\n";
        cout << "4. Kia Sportage\n";

        cout << "Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            model = "Toyota Corolla";
            rate = 5000 ;
            seats = 5;
        }
        else if(choice == 2)
        {
            model = "Honda Civic";
            rate = 6000;
            seats = 5;
        }
        else if(choice == 3)
        {
            model = "Suzuki Alto";
            rate = 3000;
            seats = 4;
        }
        else if(choice == 4)
        {
            model = "Kia Sportage";
            rate = 8000;
            seats = 7;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            break;
        }

        system.addVehicle(new Car(model,rate,seats));
    }

    else if(type == 2)
    {
        int choice;
        int cc;

        cout << "\nSelect Motorbike Model\n";
        cout << "1. Honda CD 70\n";
        cout << "2. Honda 125\n";
        cout << "3. Yamaha YBR 125\n";
        cout << "4. Suzuki GS 150\n";

        cout << "Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            model = "Honda CD 70 ";
            rate = 800;
            cc = 70;
        }
        else if(choice == 2)
        {
            model = "Honda 125";
            rate = 1200;
            cc = 125;
        }
        else if(choice == 3)
        {
            model = "Yamaha YBR 125";
            rate = 1500;
            cc = 125;
        }
        else if(choice == 4)
        {
            model = "Suzuki GS 150";
            rate = 1800;
            cc = 150;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            break;
        }

        system.addVehicle(new Motorbike(model,rate,cc));
    }

    else if(type == 3)
    {
        int choice;
        double payload;

        cout << "\nSelect Truck Model\n";
        cout << "1. Hino Truck\n";
        cout << "2. Mazda Truck\n";
        cout << "3. Isuzu Truck\n";
        cout << "4. Nissan Diesel\n";

        cout << "Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            model = "Hino Truck";
            rate = 12000;
            payload = 10;
        }
        else if(choice == 2)
        {
            model = "Mazda Truck";
            rate = 10000;
            payload = 5;
        }
        else if(choice == 3)
        {
            model = "Isuzu Truck";
            rate = 15000;
            payload = 15;
        }
        else if(choice == 4)
        {
            model = "Nissan Diesel";
            rate = 18000;
            payload = 20;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
            break;
        }

        system.addVehicle(new Truck(model,rate,payload));
    }

    else
    {
        cout << "Invalid Vehicle Type!"
             << endl;
    }

    break;
}
       
        case 2:
        {
            int id;
            string name;

            cout << "Enter Customer ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, name);

            system.registerCustomer(id,name);

            break;
        }

        case 3:
        {
            int id;
            int days;
            string model;

            cout << "Enter Customer ID: ";
            cin >> id;

            cout << "Enter Vehicle Model: ";
            cin.ignore();
            getline(cin, model);

            cout << "Enter Rental Days: ";
            cin >> days;

            system.rentVehicle(id,model,days);

            break;
        }

        case 4:
        {
            int id;

            cout << "Enter Customer ID: ";
            cin >> id;

            system.returnVehicle(id);

            break;
        }

        case 5:
            system.displayVehicles();
            break;

        case 6:
            system.displayCustomers();
            break;

        case 7:
            system.printSummary();
            break;

        case 8:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "Invalid Choice!"
                 << endl;
        }

    }
    while(choice != 8);

    return 0;
}

 
