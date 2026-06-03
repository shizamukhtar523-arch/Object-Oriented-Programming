#include "Flight.h"
Flight::Flight()
{
    flightNumber = "";
    origin = "";
    destination = "";
    departureDate = "";
    totalSeats = 0;
    availableSeats = 0;
}

Flight::Flight(string fn, string org, string dest,  string date, int total, int available)
{
    flightNumber = fn;
    origin = org;
    destination = dest;
    departureDate = date;
    totalSeats = total;
    availableSeats = available;
}

Flight::~Flight()
{
}
string Flight::getFlightNumber() const
{
    return flightNumber;
}

string Flight::getOrigin() const
{
    return origin;
}

string Flight::getDestination() const
{
    return destination;
}

string Flight::getDepartureDate() const
{
    return departureDate;
}

int Flight::getTotalSeats() const
{
    return totalSeats;
}

int Flight::getAvailableSeats() const
{
    return availableSeats;
}

void Flight::decreaseSeat()
{
    if (availableSeats > 0) availableSeats--;
}

void Flight::increaseSeat()
{
    if (availableSeats < totalSeats)availableSeats++;
}

