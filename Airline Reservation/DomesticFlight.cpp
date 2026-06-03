#include "DomesticFlight.h"

DomesticFlight::DomesticFlight()
{
    taxRate = 0;
}

DomesticFlight::DomesticFlight( string fn,string org, string dest, string date, int total, int available,  double tax)

: Flight(fn, org, dest, date, total, available)
{
    taxRate = tax;
}

double DomesticFlight::calculateBaseFare()
{
    return 5000 + taxRate;
}

void DomesticFlight::displayDetails()
{
    cout << "\nDomestic Flight\n";
    cout << "Flight No: " << flightNumber << endl;
    cout << "From: " << origin << endl;
    cout << "To: " << destination << endl;
    cout << "Date: " << departureDate << endl;
    cout << "Available Seats: " << availableSeats << endl;
}


