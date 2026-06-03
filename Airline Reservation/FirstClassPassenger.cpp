#include "FirstClassPassenger.h"

FirstClassPassenger::FirstClassPassenger()
{
}

FirstClassPassenger::FirstClassPassenger(int id,string name,string passport): Passenger(id,name,passport)
{
}

double FirstClassPassenger::getRefundPercentage()
{
    return 90.0;
}

int FirstClassPassenger::getBaggageAllowance()
{
    return 50;
}

void FirstClassPassenger::displayPassenger()
{
    cout << "\n===== First Class Passenger =====\n";
	cout << "ID: "<< passengerID<< endl;
	cout << "Name: "<< name<< endl;
	cout << "Passport: "<< passportNumber<< endl;
	cout << "Baggage Allowance: "<< getBaggageAllowance()<< " KG\n";
}

