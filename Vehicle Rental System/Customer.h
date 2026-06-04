#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
private:
    int customerID;
    string name;
    bool activeRental;

public:
    Customer(int id=0,string name="");

    int getID() const;
    string getName() const;

    bool hasActiveRental() const;

    void setActiveRental(bool status);
};

#endif

