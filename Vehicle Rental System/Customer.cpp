#include "Customer.h"

Customer::Customer(int id,string name)
{
    customerID=id;
    this->name=name;
    activeRental=false;
}

int Customer::getID() const
{
    return customerID;
}

string Customer::getName() const
{
    return name;
}

bool Customer::hasActiveRental() const
{
    return activeRental;
}

void Customer::setActiveRental(bool status)
{
    activeRental=status;
}
