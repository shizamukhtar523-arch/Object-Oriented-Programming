#include <iostream>
#include "Temp.h"
using namespace std;
float Temperature::convert()
{
    return (celsius * 9/5) + 32;
}
void Temperature::display()
{
    cout<<"Temperature in Fahrenheit: "<<convert()<<endl;
}
