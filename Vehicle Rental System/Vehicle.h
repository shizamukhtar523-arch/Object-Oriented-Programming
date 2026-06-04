#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
protected:
    string modelName;
    double dailyRate;
    bool available;

public:
    Vehicle(string model="", double rate=0);
    virtual ~Vehicle();

    virtual double calculateCost(int days) const;
    virtual void display() const;

    string getModel() const;
    bool isAvailable() const;
    void setAvailability(bool status);
};
class Car : public Vehicle
{
private:
    int seats;

public:
    Car(string model="", double rate=0, int seats=0);
	void display() const;
};
class Motorbike : public Vehicle
{
private:
    int engineCC;
public:
    Motorbike(string model="", double rate=0, int cc=0);

    double calculateCost(int days) const;
    void display() const;
};
class Truck : public Vehicle
{
private:
    double payloadCapacity;

public:
    Truck(string model="", double rate=0,
          double payload=0);

    double calculateCost(int days) const;
    void display() const;
};

#endif

