#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H

#include "Flight.h"

class CharterFlight : public Flight
{
private:
    string contractHolder;

public:
CharterFlight();CharterFlight(string fn,string org,string dest,string date,int total,int available, string holder);

    double calculateBaseFare();

    void displayDetails();
};

#endif

