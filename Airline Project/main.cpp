#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
using namespace std;
int validateInteger(string prompt, int min, int max) 
{
    int value;
    while (true) 
	{
        cout << prompt;
        if (cin >> value && value >= min && value <= max) 
		{
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "!!! INVALID OPTION: Please choose a valid number (" << min << "-" << max << ") !!!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string validateString(string prompt, int minLength) 
{
    string str;
    while (true)
	 {
        cout << prompt;
        getline(cin, str);
        
        bool hasNumber = false;
        for(char c : str) if(isdigit(c)) hasNumber = true;

        if (str.length() >= minLength && !hasNumber) 
		{
            return str;
        } 
		else 
		{
            cout << "!!! INVALID INPUT: Must be at least " << minLength << " letters. Numbers/Single letters not allowed! !!!" << endl;
        }
    }
}

class SkyLinkAirways
 {
private:
    vector<Flight*> flightInventory;
    vector<Ticket*> ticketLedger;
    const string masterKey = "admin123";

public:
    void adminPortal()
	 {
        string key;
        cout << "ENTER ADMIN ACCESS KEY: ";
        cin >> key;
        cin.ignore();
        if (key != masterKey) 
		{
            cout << "!!! ACCESS DENIED: Invalid Key !!!" << endl;
            return;
        }
        
        int subChoice = 0;
        while (subChoice != 3) 
		{
            cout << "\n--- FLIGHT MANAGEMENT PANEL ---\n1. Register Domestic Flight\n2. Register International Flight\n3. Return to Main Menu\nSelect: ";
            subChoice = validateInteger("", 1, 3);
            if (subChoice == 3) break;

            string id = "SL-" + to_string(100 + rand() % 900);
            string dest = validateString("Enter Destination City: ", 3);
            string time = "10:30 PM";
            double fare = (subChoice == 1) ? 9500.0 : 65000.0;

            if (subChoice == 1) 
			{
                flightInventory.push_back(new DomesticFlight(id, dest, time, fare));
            } else 
			{
                string visa = validateString("Enter Visa Requirement (e.g. Tourist/Work): ", 4);
                flightInventory.push_back(new InternationalFlight(id, dest, time, fare, visa));
            }
            cout << ">> Flight successfully scheduled with ID: " << id << endl;
            saveState();
        }
    }
    void saveState() 
	{
        ofstream db("airline_records.txt", ios::app);
        if(db.is_open() && !flightInventory.empty()) 
		{
            Flight* f = flightInventory.back();
            db << f->flightID << " to " << f->destination << " [" << f->getServiceType() << "]\n";
            db.close();
        }
    }
    void showSchedule() 
	{
        if (flightInventory.empty()) 
		{
            cout << "\n[!] No active flights scheduled in the system right now.\n";
            return;
        }
        cout << "\n" << string(75, '=') << endl;
        cout << "| " << setw(10) << "FLIGHT ID" << " | " << setw(15) << "DESTINATION" << " | " 
             << setw(10) << "TIME" << " | " << setw(10) << "FARE(PKR)" << " | " << "TYPE     |" << endl;
        cout << string(75, '=') << endl;
        for (auto f : flightInventory) f->displayInfo();
        cout << string(75, '=') << endl;
    }

    void processBooking()
	 {
        if (flightInventory.empty()) 
		{
            cout << "\n!!! Error: No active flights available for booking. !!!" << endl;
            return;
        }
        showSchedule();
        int idx = validateInteger("Select Flight Serial Number (1-" + to_string(flightInventory.size()) + "): ", 1, flightInventory.size()) - 1;
        
        if (flightInventory[idx]->bookedSeats >= flightInventory[idx]->totalSeats) 
		{
            cout << "!!! Error: This flight is already completely Full !!!" << endl;
            return;
        }

        string pName = validateString("Enter Passenger Full Name: ", 3);
        string id = validateString("Enter CNIC / Passport Code: ", 5);
        
        cout << "\nSelect Ticket Class:\n1. Economy Class\n2. Business Class\nChoice: ";
        int classChoice = validateInteger("", 1, 2);

        Passenger* passengerObj = nullptr;
        if(classChoice == 1) 
		{
            passengerObj = new EconomyPassenger(pName, id);
        } 
		else
		 {
            passengerObj = new BusinessPassenger(pName, id);
        }

        flightInventory[idx]->bookedSeats++;
        
        Ticket* newTicket = new Ticket(flightInventory[idx], passengerObj, flightInventory[idx]->bookedSeats);
        ticketLedger.push_back(newTicket);
        
        cout << *newTicket; 
    }

    ~SkyLinkAirways() 
	{
        for (auto f : flightInventory) delete f;
        for (auto t : ticketLedger) delete t;
    }
};

int main() 
{
    SkyLinkAirways system;
    int mChoice = 0;

    while (mChoice != 4) 
	{
    	
        cout << "\n==========================================";
        cout << "\n     SKYLINK AIRWAYS ENTERPRISE SYSTEM     ";
        cout << "\n==========================================";
        cout << "\n1. Admin Dashboard (Add Flights)";
        cout << "\n2. Display Flight Schedule Board";
        cout << "\n3. Book Passenger Ticket (With Class Options)";
        cout << "\n4. Shut Down Application";
        mChoice = validateInteger("\nEXECUTE COMMAND (1-4): ", 1, 4);

        switch (mChoice)
		 {
            case 1: system.adminPortal(); break;
            case 2: system.showSchedule(); break;
            case 3: system.processBooking(); break;
            case 4: cout << "\nSystem securely closed. Database backup successfully verified.\n"; break;
        }
    }
    return 0;
}
