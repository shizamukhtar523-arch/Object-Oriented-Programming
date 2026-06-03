#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>

using namespace std;

class Passenger
{
protected:
    int passengerID;
    string name;
    string passportNumber;

public:

    Passenger();

    Passenger(int id,
              string n,
              string passport);

    virtual ~Passenger();

    int getPassengerID() const;

    string getName() const;

    string getPassportNumber() const;

    virtual double getRefundPercentage() = 0;

    virtual int getBaggageAllowance() = 0;

    virtual void displayPassenger() = 0;
};

#endif

