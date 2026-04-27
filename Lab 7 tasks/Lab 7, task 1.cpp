#include <iostream>
class Display 
{
private:
    double lastValue;
public:
    Display() : lastValue(0.0) {}
    void show(double value)
	 {
        lastValue = value;
        std::cout << "Displaying Result: " << lastValue << std::endl;
    }
    double getLastValue() const
	 {
        return lastValue;
    }
};
class Calculator
 {
private:
    Display screen; 

public:
    void add(double a, double b) 
	{
        double result = a + b;
        screen.show(result);
    }
    void multiply(double a, double b)
	 {
        double result = a * b;
        screen.show(result);
    }
    void showPreviousResult() const 
	{
        std::cout << "Last stored result was: " << screen.getLastValue() << std::endl;
    }
};
int main() 
{
    Calculator myCalc;
    myCalc.add(10.5, 5.5);
    myCalc.multiply(4, 5);
    myCalc.showPreviousResult();
    
    return 0;
}
