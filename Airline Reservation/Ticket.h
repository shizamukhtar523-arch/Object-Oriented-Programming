#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Passenger.h"
#include "Flight.h"

using namespace std;

class Ticket
{
private:

    int ticketID;
    Passenger* passenger;
    Flight* flight;

    int seatNumber;

    double farePaid;

    bool bookingStatus;

public:

    Ticket();

    Ticket(
        int id,
        Passenger* p,
        Flight* f,
        int seat,
        double fare);

    int getTicketID() const;

    Passenger* getPassenger() const;

    Flight* getFlight() const;

    double getFarePaid() const;

    bool getBookingStatus() const;

    bool operator==(const Ticket& t);

    friend ostream& operator<<(ostream& out,const Ticket& t);
};

#endif

