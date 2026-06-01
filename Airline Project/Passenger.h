#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <string>

using namespace std;

// Base Passenger Class
class Passenger {
protected:
    string name, cnic;
public:
    Passenger(string n, string id) : name(n), cnic(id) {}
    virtual ~Passenger() {}
    virtual string getPassengerClass() = 0;
    virtual double getBaggageAllowance() = 0;
    
    string getName() const { return name; }
    string getCNIC() const { return cnic; }
};

// Derived Class 1: Economy
class EconomyPassenger : public Passenger {
public:
    EconomyPassenger(string n, string id) : Passenger(n, id) {}
    string getPassengerClass() override { return "Economy Class"; }
    double getBaggageAllowance() override { return 20.0; } // 20kg limit
};

// Derived Class 2: Business
class BusinessPassenger : public Passenger {
public:
    BusinessPassenger(string n, string id) : Passenger(n, id) {}
    string getPassengerClass() override { return "Business Class"; }
    double getBaggageAllowance() override { return 40.0; } // 40kg limit
};
#endif
