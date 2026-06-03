#ifndef FIRSTCLASSPASSENGER_H
#define FIRSTCLASSPASSENGER_H

#include "Passenger.h"

class FirstClassPassenger : public Passenger
{
public:

    FirstClassPassenger();

    FirstClassPassenger(
        int id,
        string name,
        string passport);

    double getRefundPercentage();

    int getBaggageAllowance();

    void displayPassenger();
};

#endif

