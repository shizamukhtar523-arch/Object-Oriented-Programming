#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"

class RentalSystem
{
private:
    Vehicle* fleet[50];
    Customer customers[50];
    Rental rentals[100];

    int vehicleCount;
    int customerCount;
    int rentalCount;

public:
    RentalSystem();

    void addVehicle(Vehicle* vehicle);

    void registerCustomer(int id,string name);

    Customer* findCustomer(int id);

    Vehicle* findVehicle(string model);

    void rentVehicle(int customerID,string vehicleModel,int days);

    void returnVehicle(int customerID);

    void displayVehicles();

    void displayCustomers();

    void printSummary();

    ~RentalSystem();
};

#endif

