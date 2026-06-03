#include "Passenger.h"

Passenger::Passenger()
{
    passengerID = 0;name = "";passportNumber = "";
}

Passenger::Passenger(int id,string n,string passport)
{
    passengerID = id;name = n;passportNumber = passport;
}

Passenger::~Passenger()
{
}

int Passenger::getPassengerID() const
{
    return passengerID;
}

string Passenger::getName() const
{
    return name;
}
string Passenger::getPassportNumber() const
{
    return passportNumber;
}
