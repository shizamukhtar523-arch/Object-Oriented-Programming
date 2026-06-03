#include "EconomyPassenger.h"

EconomyPassenger::EconomyPassenger()
{
}

EconomyPassenger::EconomyPassenger(
        int id,
        string name,
        string passport)

: Passenger(id,name,passport)
{
}

double EconomyPassenger::getRefundPercentage()
{
    return 50.0;
}

int EconomyPassenger::getBaggageAllowance()
{
    return 20;
}

void EconomyPassenger::displayPassenger()
{
    cout << "\n===== Economy Passenger =====\n";

    cout << "ID: "
         << passengerID
         << endl;

    cout << "Name: "
         << name
         << endl;

    cout << "Passport: "
         << passportNumber
         << endl;

    cout << "Baggage Allowance: "
         << getBaggageAllowance()
         << " KG\n";
}
