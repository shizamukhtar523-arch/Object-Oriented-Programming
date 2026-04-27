 #include<iostream>
using namespace std;
struct Student
{
	string firstName;
	string lastName;
	int rollNumber;
	float marks;
	
	void displayStudentInfo()
	{
		cout<<"Full Name: "<<firstName<<" "<< lastName<<endl;
		cout<<"Marks: "<< marks<<endl;
	}
};
int main()
{
	Student s1;
	s1.firstName="Ayesha";
	s1.lastName="Haider";
	s1.rollNumber=101;
	s1.marks=90;
	
	s1.displayStudentInfo();
	return 0;
}
