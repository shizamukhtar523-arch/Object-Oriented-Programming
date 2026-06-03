#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <fstream>

#include "Flight.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "CharterFlight.h"

#include "Passenger.h"
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"
#include "FirstClassPassenger.h"

#include "Ticket.h"

using namespace std;

class Airline
{
private:

    Flight* flights[50];
    Passenger* passengers[50];
    Ticket* tickets[100];

    int flightCount;
    int passengerCount;
    int ticketCount;

public:

    Airline();

    ~Airline();

    void addFlight(Flight* f);
	void addPassenger(Passenger* p);
	void listFlights();
	void listPassengers();
    void searchFlight(string flightNo);
	void showTickets();
	void bookTicket(
        int passengerIndex,int flightIndex);

    void cancelTicket(int ticketID);
	void saveData();

    void loadData();
};

#endif
