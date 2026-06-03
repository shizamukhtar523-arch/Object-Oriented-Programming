#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"

class InternationalFlight : public Flight
{
private:
    bool visaRequired;

public:
    InternationalFlight();

   InternationalFlight(string fn,  string org, string dest, string date, int total, int available,  bool visa);

    double calculateBaseFare();

    void displayDetails();
};

#endif
