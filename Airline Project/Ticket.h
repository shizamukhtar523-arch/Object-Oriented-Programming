#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>
#include "Flight.h"
#include "Passenger.h"

using namespace std;

class Ticket {
private:
    Flight* flightRef;
    Passenger* passengerRef;
    int seatNumber;
public:
    Ticket(Flight* f, Passenger* p, int seat) : flightRef(f), passengerRef(p), seatNumber(seat) {}

    // Operator Overloading (<<) to print the ticket beautifully
    friend ostream& operator<<(ostream& os, const Ticket& t) {
        os << "\n==========================================";
        os << "\n       BOARDING PASS: SKYLINK AIRWAYS     ";
        os << "\n==========================================";
        os << "\n PASSENGER : " << t.passengerRef->getName();
        os << "\n CLASS     : " << t.passengerRef->getPassengerClass();
        os << "\n BAGGAGE   : " << t.passengerRef->getBaggageAllowance() << " KG Max";
        os << "\n FLIGHT NO : " << t.flightRef->flightID;
        os << "\n TO        : " << t.flightRef->destination;
        os << "\n SEAT NO   : " << t.seatNumber;
        os << "\n FINAL FARE: PKR " << t.flightRef->calculateTaxedFare();
        os << "\n STATUS    : CONFIRMED & PAID";
        os << "\n==========================================\n";
        return os;
    }
};
#endif
