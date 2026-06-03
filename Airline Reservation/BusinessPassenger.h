#ifndef BUSINESSPASSENGER_H
#define BUSINESSPASSENGER_H

#include "Passenger.h"

class BusinessPassenger : public Passenger
{
public:

    BusinessPassenger();

    BusinessPassenger(int id,string name,string passport);

    double getRefundPercentage();

    int getBaggageAllowance();

    void displayPassenger();
};

#endif
