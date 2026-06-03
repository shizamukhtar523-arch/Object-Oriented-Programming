#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

class FlightFullException   : public exception
{
public:

    const char* what() const throw()
    {
        return "Flight is Full!";
    }
};

class InvalidCancellationException: public exception
{
public:

    const char* what() const throw()
    {
        return "Invalid Cancellation!";
    }
};

#endif

