#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H
#include "Flight.h"
class DomesticFlight : public Flight
{
private:
    double taxRate;
public:
    DomesticFlight();

    DomesticFlight(string fn, string org,  string dest, string date, int total, int available,    double tax);

    double calculateBaseFare();

    void displayDetails();
};

#endif

