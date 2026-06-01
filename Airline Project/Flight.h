#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base Class (Inheritance)
class Flight {
public:
    string flightID, destination, schedule;
    double price;
    int totalSeats, bookedSeats;

    Flight(string id, string dest, string time, double p) 
        : flightID(id), destination(dest), schedule(time), price(p), totalSeats(50), bookedSeats(0) {}

    virtual ~Flight() {}

    // Pure Virtual Functions (Polymorphism)
    virtual void displayInfo() = 0;
    virtual double calculateTaxedFare() = 0;
    virtual string getServiceType() = 0;
};

// Derived Class 1
class DomesticFlight : public Flight {
public:
    DomesticFlight(string id, string dest, string time, double p) : Flight(id, dest, time, p) {}

    double calculateTaxedFare() override { return price + 1200.50; } 
    string getServiceType() override { return "Domestic"; }

    void displayInfo() override {
        cout << "| " << setw(10) << flightID << " | " << setw(15) << destination << " | " 
             << setw(10) << schedule << " | " << setw(10) << calculateTaxedFare() << " | Domestic |" << endl;
    }
};

// Derived Class 2
class InternationalFlight : public Flight {
public:
    string visaProtocol;
    InternationalFlight(string id, string dest, string time, double p, string v) 
        : Flight(id, dest, time, p), visaProtocol(v) {}

    double calculateTaxedFare() override { return price + 18500.75; } 
    string getServiceType() override { return "International"; }

    void displayInfo() override {
        cout << "| " << setw(10) << flightID << " | " << setw(15) << destination << " | " 
             << setw(10) << schedule << " | " << setw(10) << calculateTaxedFare() << " | Intl     |" << endl;
    }
};
#endif
