#include "InternationalFlight.h"

InternationalFlight::InternationalFlight()
{
    visaRequired = true;
}

InternationalFlight::InternationalFlight(string fn,string org,string dest,string date,int total,int available,
bool visa): Flight(fn, org, dest, date, total, available)
{
    visaRequired = visa;
}

double InternationalFlight::calculateBaseFare()
{
    return 25000;
}

void InternationalFlight::displayDetails()
{
    cout << "\nInternational Flight\n";
    cout << "Flight No: " << flightNumber << endl;
    cout << "From: " << origin << endl;
    cout << "To: " << destination << endl;
    cout << "Visa Required: ";

    if(visaRequired)
        cout << "Yes\n";
    else
        cout << "No\n";
} 
