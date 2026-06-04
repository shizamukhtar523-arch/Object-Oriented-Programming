#include "Rental.h"
#include <iostream>

using namespace std;

Rental::Rental()
{
    customer = NULL;
    vehicle = NULL;
    days = 0;
    totalCost = 0;
    returned = false;
}

Rental::Rental(Customer* customer,Vehicle* vehicle,int days)
{
    this->customer = customer;
    this->vehicle = vehicle;
    this->days = days;

    totalCost = vehicle->calculateCost(days);

    returned = false;
}

Customer* Rental::getCustomer() const
{
    return customer;
}

Vehicle* Rental::getVehicle() const
{
    return vehicle;
}

int Rental::getDays() const
{
    return days;
}

double Rental::getCost() const
{
    return totalCost;
}

bool Rental::isReturned() const
{
    return returned;
}

void Rental::closeRental()
{
    returned = true;
}

void Rental::display() const
{
cout << "Customer: "<< customer->getName()<< " | Vehicle: "<< vehicle->getModel()<< " | Days: "<< days
         << " | Cost: "<< totalCost<< " | Status: "<< (returned ? "Closed" : "Active")<< endl;
}

