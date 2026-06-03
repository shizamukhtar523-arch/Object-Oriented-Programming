#include "Ticket.h"

Ticket::Ticket()
{
    ticketID = 0;
    passenger = NULL;
    flight = NULL;
    seatNumber = 0;
    farePaid = 0;
    bookingStatus = false;
}

Ticket::Ticket(
        int id,
        Passenger* p,
        Flight* f,
        int seat,
        double fare)
{
    ticketID = id;
    passenger = p;
    flight = f;
    seatNumber = seat;
    farePaid = fare;
    bookingStatus = true;
}

int Ticket::getTicketID() const
{
    return ticketID;
}

Passenger* Ticket::getPassenger() const
{
    return passenger;
}

Flight* Ticket::getFlight() const
{
    return flight;
}

double Ticket::getFarePaid() const
{
    return farePaid;
}

bool Ticket::getBookingStatus() const
{
    return bookingStatus;
}

bool Ticket::operator==(const Ticket& t)
{
    return ticketID == t.ticketID;
}

ostream& operator<<(ostream& out,
                    const Ticket& t)
{
    out << "\n===== Ticket =====\n";

    out << "Ticket ID: "
        << t.ticketID
        << endl;

    out << "Passenger: "
        << t.passenger->getName()
        << endl;

    out << "Flight Number: "
        << t.flight->getFlightNumber()
        << endl;

    out << "Seat Number: "
        << t.seatNumber
        << endl;

    out << "Fare Paid: "
        << t.farePaid
        << endl;

    return out;
}
