#include <iostream>
#include "Calculator.h"
using namespace std;
int main()
 {
    Calculator myCalc;
    int choice;
    cout << "Enter first number: ";
    cin >> myCalc.num1;
    cout << "Enter second number: ";
    cin >> myCalc.num2;
    cout << "\nChoose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nChoice: ";
    cin >> choice;
    switch(choice) 
	{
        case 1: cout << "Result: " << myCalc.add(); break;
        case 2: cout << "Result: " << myCalc.subtract(); break;
        case 3: cout << "Result: " << myCalc.multiply(); break;
        case 4: cout << "Result: " << myCalc.divide(); break;
        default: cout << "Invalid choice.";
    }
    return 0;
}
