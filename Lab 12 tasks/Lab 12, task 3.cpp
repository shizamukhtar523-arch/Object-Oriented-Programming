#include<iostream>
#include<string>
using namespace std;
class HospitalStaff 
{
protected:
    string staffName;
public:
    HospitalStaff(string name) 
	{
        staffName = name;
    }
    virtual void performDuty() = 0; // Pure virtual function
};
class Doctor : public HospitalStaff 
{
public:
    Doctor(string name) : HospitalStaff(name) {}
    void performDuty() 
	{
        cout << staffName << " is diagnosing patients" << endl;
    }
};
class Nurse : public HospitalStaff 
{
public:
    Nurse(string name) : HospitalStaff(name) {}
    void performDuty() 
	{
        cout << staffName << " is assisting patients" << endl;
    }
};
class Receptionist : public HospitalStaff
 {
public:
    Receptionist(string name) : HospitalStaff(name) 
	{}
    void performDuty()
	 {
        cout << staffName << " is managing appointments" << endl;
    }
};
int main()
 {
    HospitalStaff* s1 = new Doctor("Doctor");
    HospitalStaff* s2 = new Nurse("Nurse");
    HospitalStaff* s3 = new Receptionist("Receptionist");
    s1->performDuty();
    s2->performDuty();
    s3->performDuty();
    delete s1;
    delete s2;
    delete s3;
    return 0;
}
