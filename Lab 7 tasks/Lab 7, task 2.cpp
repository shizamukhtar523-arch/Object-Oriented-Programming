#include <iostream>
#include <string>
class Calculator
 {
public:
    double add(double a, double b)
	 {
	  return a + b; 
	 }
    double multiply(double a, double b)
	 {
	  return a * b; 
	 }
};
class Student
 {
private:
    std::string name;
    Calculator* sharedCalc; 
public:
    Student(std::string n, Calculator* calc) : name(n), sharedCalc(calc) {}
    void solveMath(double x, double y) 
	{
        if (sharedCalc) 
		{
            double res = sharedCalc->add(x, y);
            std::cout << name << " solved " << x << "+" << y << " = " << res << std::endl;
        }
    }
};
int main() 
{
    Calculator teacherCalc;
    Student student1("Areeba", &teacherCalc);
    Student student2("Samia", &teacherCalc);
    student1.solveMath(12, 8);
    student2.solveMath(5, 5);

    return 0;
}
