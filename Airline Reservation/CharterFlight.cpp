#include "CharterFlight.h"

CharterFlight::CharterFlight()
{
    contractHolder = "";
}

CharterFlight::CharterFlight(string fn,string org,string dest,string date,int total,int available,string holder)
: Flight(fn, org, dest, date, total, available)
{
    contractHolder = holder;
}

double CharterFlight::calculateBaseFare()
{
    return 50000;
}

void CharterFlight::displayDetails()
{
    cout << "\nCharter Flight\n";
    cout << "Flight No: " << flightNumber << endl;
    cout << "Contract Holder: "
         << contractHolder << endl;
}
