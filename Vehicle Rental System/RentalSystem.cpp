#include "RentalSystem.h"
#include <iostream>

using namespace std;

RentalSystem::RentalSystem()
{
    vehicleCount = 0;
    customerCount = 0;
    rentalCount = 0;
}

void RentalSystem::addVehicle(Vehicle* vehicle)
{
    if(vehicleCount >= 50)
    {
        cout << "Fleet Full!" << endl;
        return;
    }

    fleet[vehicleCount] = vehicle;
    vehicleCount++;

    cout << "Vehicle Added Successfully!" << endl;
}

void RentalSystem::registerCustomer(int id, string name)
{
    int i;

    for(i=0; i<customerCount; i++)
    {
        if(customers[i].getID() == id)
        {
            cout << "Customer ID Already Exists!" << endl;
            return;
        }
    }

    customers[customerCount] = Customer(id, name);
    customerCount++;

    cout << "Customer Registered Successfully!" << endl;
}

Customer* RentalSystem::findCustomer(int id)
{
    int i;

    for(i=0; i<customerCount; i++)
    {
        if(customers[i].getID() == id)
        {
            return &customers[i];
        }
    }

    return NULL;
}

Vehicle* RentalSystem::findVehicle(string model)
{
    int i;

    for(i=0; i<vehicleCount; i++)
    {
        if(fleet[i]->getModel() == model)
        {
            return fleet[i];
        }
    }

    return NULL;
}

void RentalSystem::rentVehicle(int customerID, string vehicleModel, int days)
{
    if(days <= 0)
    {
        cout << "Invalid Number Of Days!" << endl;
        return;
    }

    Customer* customer = findCustomer(customerID);
    Vehicle* vehicle = findVehicle(vehicleModel);

    if(customer == NULL)
    {
        cout << "Customer Not Found!" << endl;
        return;
    }

    if(vehicle == NULL)
    {
        cout << "Vehicle Not Found!" << endl;
        return;
    }

    if(customer->hasActiveRental())
    {
        cout << "Customer Already Has Rental!" << endl;
        return;
    }

    if(!vehicle->isAvailable())
    {
        cout << "Vehicle Already Rented!" << endl;
        return;
    }

    rentals[rentalCount] = Rental(customer, vehicle, days);
    rentalCount++;

    customer->setActiveRental(true);
    vehicle->setAvailability(false);

    double originalAmount = vehicle->calculateCost(days); 
    double finalAmount = originalAmount;
    double discountAmount = 0.0;
    string reason = "No eligible discount applied (Standard Rate).";

    string m = vehicle->getModel();
    if ((m == "Honda 125" || m == "CD 70" || m == "Suzuki 150" || m == "Yamaha YBR") && days > 7)
    {
        discountAmount = originalAmount * 0.10; // 10% Discount
        finalAmount = originalAmount - discountAmount;
        reason = "Special Promo! Motorbike rented for more than 7 days (10% Discount Applied).";
    }
    
    cout << "\n=============================================" << endl;
    cout << "         RENTAL PROCESS RECEIPT              " << endl;
    cout << "=============================================" << endl;
    cout << " Rental Status    : Processed Successfully!" << endl;
    cout << " Customer ID      : " << customerID << endl;
    cout << " Vehicle Model    : " << vehicleModel << endl;
    cout << " Rental Duration  : " << days << " Days" << endl;
    cout << "---------------------------------------------" << endl;
    cout << " Original Amount  : PKR " << originalAmount << endl;
    cout << " Discount Allowed : PKR " << discountAmount << endl;
    cout << " Final Amount     : PKR " << finalAmount << endl;
    cout << " Reason           : " << reason << endl;
    cout << "=============================================\n" << endl;
}

void RentalSystem::returnVehicle(int customerID)
{
    int i;

    for(i=0; i<rentalCount; i++)
    {
        if(rentals[i].getCustomer()->getID() == customerID && !rentals[i].isReturned())
        {
            rentals[i].closeRental();
            rentals[i].getVehicle()->setAvailability(true);
            rentals[i].getCustomer()->setActiveRental(false);

            cout << "Vehicle Returned Successfully!" << endl;
            return;
        }
    }

    cout << "No Active Rental Found!" << endl;
}

void RentalSystem::displayVehicles()
{
    int i;

    cout << "\n===== VEHICLES =====\n";

    for(i=0; i<vehicleCount; i++)
    {
        fleet[i]->display();
        cout << "Availability: " << (fleet[i]->isAvailable() ? "Available" : "Rented") << endl;
    }
}

void RentalSystem::displayCustomers()
{
    int i;

    cout << "\n===== CUSTOMERS =====\n";

    for(i=0; i<customerCount; i++)
    {
        cout << "ID: " << customers[i].getID() << " Name: " << customers[i].getName() << endl;
    }
}

void RentalSystem::printSummary()
{
    int i;

    cout << "\n===== ACTIVE RENTALS =====\n";

    for(i=0; i<rentalCount; i++)
    {
        if(!rentals[i].isReturned())
        {
            rentals[i].display();
        }
    }

    int available = 0;
    int rented = 0;

    for(i=0; i<vehicleCount; i++)
    {
        if(fleet[i]->isAvailable())
        {
            available++;
        }
        else
        {
            rented++;
        }
    }

    cout << "\nAvailable Vehicles: " << available << endl;
    cout << "Rented Vehicles: " << rented << endl;

    cout << "\n===== ALL RENTAL RECORDS =====\n";

    for(i=0; i<rentalCount; i++)
    {
        rentals[i].display();
    }
}

RentalSystem::~RentalSystem()
{
    int i;

    for(i=0; i<vehicleCount; i++)
    {
        delete fleet[i];
    }
}

