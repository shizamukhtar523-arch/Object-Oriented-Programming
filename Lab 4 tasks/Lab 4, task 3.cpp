#include <iostream>
using namespace std;
class Employee
 {
public:
    string name;
    double salary;
    void display_employee() 
	{
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Developer : public Employee
 {
public:
    string programming_language;
    void display_developer()
	 {
	 	display_employee();
        cout << "Programming Language: " << programming_language << endl;
    }
};
class Designer : public Employee
 {
public:
    string design_tool;
    void display_designer() 
	{
		display_employee();
        cout << "Design Tool: " << design_tool << endl;
    }
};
int main() 
{
    Developer d;
    cout << "Enter Developer Name: ";
    cin >> d.name;
    cout << "Enter Salary: ";
    cin >> d.salary;
    cout << "Enter Programming Language: ";
    cin >> d.programming_language;
    cout << "\nDeveloper Info\n";
    d.display_employee();
    d.display_developer();
    Designer ds;
    cout << "\nEnter Designer Name: ";
    cin >> ds.name;
    cout << "Enter Salary: ";
    cin >> ds.salary;
    cout << "Enter Design Tool: ";
    cin >> ds.design_tool;
    cout << "\nDesigner Info\n";
    ds.display_employee();
    ds.display_designer();
    return 0;
}
