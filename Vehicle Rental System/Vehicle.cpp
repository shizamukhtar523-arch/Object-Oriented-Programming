#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string model,double rate)
{
    modelName=model;
    dailyRate=rate;
    available=true;
}

Vehicle::~Vehicle(){}

double Vehicle::calculateCost(int days) const
{
    return dailyRate*days;
}

void Vehicle::display() const
{
    cout<<"Model: "<<modelName<<endl;
}

string Vehicle::getModel() const
{
    return modelName;
}

bool Vehicle::isAvailable() const
{
    return available;
}

void Vehicle::setAvailability(bool status)
{
    available=status;
}
Car::Car(string model,double rate,int seats): Vehicle(model,rate)
{
    this->seats=seats;
}

void Car::display() const
{
    cout<<"Car | " <<modelName<<" | Seats: "<<seats<<" | Rate: "<<dailyRate <<endl;
}
Motorbike::Motorbike(string model, double rate, int cc): Vehicle(model,rate)
{
    engineCC=cc;
}

double Motorbike::calculateCost(int days) const
{
    double cost=dailyRate*days;

    if(days>7)
    {
        cost*=0.90;
    }

    return cost;
}

void Motorbike::display() const
{
    cout<<"Motorbike | "<<modelName<<" | "<<engineCC<<"cc | Rate: "<<dailyRate <<endl;
}
Truck::Truck(string model,double rate,double payload): Vehicle(model,rate)
{
    payloadCapacity=payload;
}

double Truck::calculateCost(int days) const
{
    return (dailyRate*1.20)*days;
}

void Truck::display() const
{
    cout<<"Truck | "<<modelName<<" | Payload: "<<payloadCapacity<<" Tons | Rate: "<<dailyRate<<endl;
}


