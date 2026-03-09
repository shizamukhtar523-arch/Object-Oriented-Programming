#include <iostream>
#include "Voter.h"
int main() 
{
    Voter person;
    std::cout << "Enter voter name: ";
    std::getline(std::cin, person.name);
    std::cout << "Enter voter age: ";
    std::cin >> person.age;
    std::cout << "---------------------------" << std::endl;
    if (person.isEligible()) 
	{
        std::cout << "Result: " << person.name << " is eligible to vote!" << std::endl;
    } 
	else
	 {
        std::cout << "Result: " << person.name << " is NOT eligible to vote." << std::endl;
    }
    return 0;
}
