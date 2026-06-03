#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
using namespace std;
class Flight
{
protected:
    string flightNumber;
    string origin;
    string destination;
    string departureDate;
    int totalSeats;
    int availableSeats;

public:
    Flight();
    Flight(string fn, string org, string dest,
           string date, int total, int available);

    virtual ~Flight();

    string getFlightNumber() const;
    string getOrigin() const;
    string getDestination() const;
    string getDepartureDate() const;

    int getTotalSeats() const;
    int getAvailableSeats() const;

    void decreaseSeat();
    void increaseSeat();

    virtual double calculateBaseFare() = 0;
    virtual void displayDetails() = 0;
};

#endif

