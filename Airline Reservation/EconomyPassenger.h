#ifndef ECONOMYPASSENGER_H
#define ECONOMYPASSENGER_H

#include "Passenger.h"

class EconomyPassenger : public Passenger
{
public:
 EconomyPassenger();

    EconomyPassenger(int id,string name,string passport);
	double getRefundPercentage(); int getBaggageAllowance();
	void displayPassenger();
};

#end
if
