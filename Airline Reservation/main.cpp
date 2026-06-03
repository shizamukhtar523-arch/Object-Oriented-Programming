#include <iostream>
#include <limits>

#include "Airline.h"
#include "Exceptions.h"

using namespace std;

int validateInteger(string prompt,int min,int max)
{
    int value;

    while(true)
    {
        cout << prompt;

        if(cin >> value &&value >= min &&value <= max)
        {
            return value;
        }

        cout
        << "\nInvalid Input!\n";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

int main()
{
    Airline airline;

    int choice;

    airline.loadData();

    do
    {
        cout << "\n==============================";
        cout << "\n SKYLINK AIRWAYS SYSTEM";
        cout << "\n==============================";

        cout << "\n1. Add Domestic Flight";
        cout << "\n2. Add International Flight";
        cout << "\n3. Add Charter Flight";

        cout << "\n4. Add Economy Passenger";
        cout << "\n5. Add Business Passenger";
        cout << "\n6. Add First Class Passenger";

        cout << "\n7. List Flights";
        cout << "\n8. List Passengers";

        cout << "\n9. Book Ticket";
        cout << "\n10. Cancel Ticket";

        cout << "\n11. Show Tickets";

        cout << "\n12. Save Data";

        cout << "\n0. Exit";

        cout << "\n\n";

        choice =validateInteger("Enter Choice: ",0,12);

        try {

        switch(choice)
        {

        case 1:
        {
            airline.addFlight(new DomesticFlight("PK101","Lahore","Karachi","10-06-2026",100,100,500));
			cout<< "\nDomestic Flight Added!\n";
			break;
        }

        case 2:
        { airline.addFlight(new InternationalFlight( "PK500","Lahore","Dubai","12-06-2026",150,150,true));
		cout<< "\nInternational Flight Added!\n";
		 break;
        }

        case 3:
        {
        airline.addFlight( new CharterFlight("CH700","Islamabad","Skardu","15-06-2026",50,50,"Army Contract"));
		cout<< "\nCharter Flight Added!\n";
		break;
        }

        case 4:
        {
            airline.addPassenger(new EconomyPassenger(1,"Ali","PK12345"));
			cout<< "\nEconomy Passenger Added!\n";
			break;
        }

        case 5:
        {
            airline.addPassenger(new BusinessPassenger(2,"Ahmed","PK54321"));
            cout<< "\nBusiness Passenger Added!\n";
			 break;
        }

        case 6:
        {
            airline.addPassenger(new FirstClassPassenger( 3,"Sara","PK98765"));
			cout<< "\nFirst Class Passenger Added!\n";
			break;
        }

        case 7:

            airline.listFlights();
            break;

        case 8:

            airline.listPassengers();
            break;

        case 9:
        {
            int passengerIndex; int flightIndex;passengerIndex =validateInteger("Passenger Index: ",0,49);

            flightIndex =validateInteger("Flight Index: ",0,49);airline.bookTicket(passengerIndex,flightIndex);

            break;
        }

        case 10:
        {
            int ticketID; ticketID =validateInteger("Ticket ID: ",1,1000);airline.cancelTicket(ticketID);

            break;
        }

        case 11:

            airline.showTickets();
            break;

        case 12:

            airline.saveData();
            break;

        case 0:

            airline.saveData();
       cout<< "\nProgram Closed!\n";

            break;
        }

        }
        catch(FlightFullException& e)
        {
            cout<< "\nError: "<< e.what()<< endl;
        }

        catch(InvalidCancellationException& e)
        {
            cout<< "\nError: " << e.what() << endl;
        }

        }
        while(choice != 0);

    return 0;
}
