#include<iostream>
#include<string>
using namespace std;
class Employee 
{
private:
    int empID;
    string empName;
    static string companyName;
public:
    Employee(int id, string name) 
	{
        empID = id;
        empName = name;
    }
    void display() 
	{
        cout << "ID: " << empID << " | Name: " << empName << endl;
    }
    static void showCompanyInfo() 
	{
        cout << "Company Name: " << companyName << endl;
    }
};
string Employee::companyName = "TechCorp Pvt Ltd";
int main() 
{
    Employee e1(101, "Ali");
    Employee e2(102, "Sara");
    e1.display();
    e2.display();
    Employee::showCompanyInfo();
    return 0;
}
