#include "Airline.h"
#include "Exceptions.h"

Airline::Airline()
{
    flightCount = 0;   passengerCount = 0;    ticketCount = 0;
}
Airline::~Airline()
{
    int i;

    for(i=0;i<flightCount;i++)
    {
        delete flights[i];
    }

    for(i=0;i<passengerCount;i++)
    {
        delete passengers[i];
    }

    for(i=0;i<ticketCount;i++)
    {
        delete tickets[i];
    }
}void Airline::addFlight(
        Flight* f)
{
    if(flightCount < 50)
    {
        flights[flightCount] = f;

        flightCount++;

        cout
        << "\nFlight Added\n";
    }
}void Airline::addPassenger(
        Passenger* p)
{
    if(passengerCount < 50)
    {
        passengers[passengerCount]   = p;  passengerCount++;

        cout << "\nPassenger Added\n";
    }
}void Airline::listFlights()
{
	cout<<"\nTotal Flights="<<flightCount<<endl;
   

    for(int i=0;i<flightCount;i++)
    {
        cout<< "\nFlight Index:"<< i << endl;

     flights[i] ->displayDetails();
    }
}void Airline::listPassengers()
{
    int i;

    for(i=0;i<passengerCount;i++)
    {
        passengers[i]  ->displayPassenger();
    }
}void Airline::showTickets()
{
	cout<<"Total Tickets="<<ticketCount<<endl;
    
int i;
    for(i=0;i<ticketCount;i++)
    {
    	cout<<"Ticket ID="<<tickets[i]->getTicketID()<<endl;
       cout<<"Fare="<<tickets[i]->getFarePaid()<<endl;
    }
}void Airline::bookTicket(int passengerIndex, int flightIndex)
{
 cout<<"Passenger Index="<< passengerIndex<<endl;
	cout<<"Flight Index="<<flightIndex<<endl;
	
    if(flightIndex < 0 ||   flightIndex >= flightCount)
    {
        cout << "\nInvalid Flight!\n";
        return;
    }

    if(passengerIndex < 0 || passengerIndex >= passengerCount)
    {
        cout << "\nInvalid Passenger!\n";
        return;
    }

    if(flights[flightIndex]->getAvailableSeats() <= 0)
    {
        throw FlightFullException();
    }

    int i;

    for(i=0;i<ticketCount;i++)
    {
    if( tickets[i]->getPassenger() == passengers[passengerIndex]&&tickets[i]->getFlight()== flights[flightIndex] )
        {
            cout
            << "\nPassenger already booked on this flight!\n";

            return;
        }
    }

    int seatNumber;

    seatNumber =flights[flightIndex]->getTotalSeats() -flights[flightIndex]->getAvailableSeats()+ 1;
Ticket* t =new Ticket( ticketCount + 1, passengers[passengerIndex],flights[flightIndex],seatNumber, flights[flightIndex]
        ->calculateBaseFare()
    );

    tickets[ticketCount] = t;

    ticketCount++;

    flights[flightIndex]->decreaseSeat();

    cout    << "\nTicket Booked Successfully!\n";
    cout<<"Reached End of booking function";
}void Airline::cancelTicket(
        int ticketID)
{
    int i;

    for(i=0;i<ticketCount;i++)
    {
        if(tickets[i]->getTicketID()==ticketID)
        {
            double refund;

            refund = tickets[i] ->getFarePaid()*tickets[i]->getPassenger()->getRefundPercentage() /100.0;

            cout<< "\nRefund Amount: " << refund<< endl;tickets[i]->getFlight()->increaseSeat();

            delete tickets[i];

            tickets[i]= tickets[ticketCount-1];ticketCount--;

            cout<< "\nTicket Cancelled!\n";

            return;
        }
    }

    throw InvalidCancellationException();
}void Airline::saveData()
{
    ofstream fout("data.txt");

    if(!fout)
    {
        cout
        << "\nFile Error!\n";

        return;
    }

    fout << flightCount<< endl;

    fout<< passengerCount<< endl;

    fout<< ticketCount<< endl;

    fout.close();

    cout<< "\nData Saved Successfully!\n";
}void Airline::loadData()
{
    ifstream fin("data.txt");

    if(!fin)
    {
        return;
    }

    fin>> flightCount;

    fin>> passengerCount;

    fin>> ticketCount;

    fin.close();
}
void Airline::searchFlight(string flightNo)
{
    int i;for(i=0;i<flightCount;i++)
    {
        if(flights[i]->getFlightNumber()==flightNo)
        {
            flights[i] ->displayDetails();

            return;
        }
    }

    cout
    << "\nFlight Not Found!\n";
}
