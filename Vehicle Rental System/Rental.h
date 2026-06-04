#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Vehicle.h"

class Rental
{
private:
    Customer* customer;
    Vehicle* vehicle;
    int days;
    double totalCost;
    bool returned;

public:
    Rental();

    Rental(Customer* customer,Vehicle* vehicle,int days);

    Customer* getCustomer() const;
    Vehicle* getVehicle() const;

    int getDays() const;
    double getCost() const;

    bool isReturned() const;

    void closeRental();

    void display() const;
};

#endif

