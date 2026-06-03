#include "BusinessPassenger.h"

BusinessPassenger::BusinessPassenger()
{
}

BusinessPassenger::BusinessPassenger(
        int id,
        string name,
        string passport)

: Passenger(id,name,passport)
{
}

double BusinessPassenger::getRefundPercentage()
{
    return 75.0;
}

int BusinessPassenger::getBaggageAllowance()
{
    return 35;
}

void BusinessPassenger::displayPassenger()
{
    cout << "\n===== Business Passenger =====\n";

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

