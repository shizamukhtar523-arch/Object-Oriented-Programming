#include "Calculator.h"
#include <iostream>
float Calculator::add() 
{ 
    return num1 + num2; 
}
float Calculator::subtract() 
{ 
    return num1 - num2; 
}
float Calculator::multiply() 
{ 
    return num1 * num2; 
}
float Calculator::divide() 
{
    if (num2 != 0) {
        return num1 / num2;
    } 
	else 
	{
        return 0;
    }
}
