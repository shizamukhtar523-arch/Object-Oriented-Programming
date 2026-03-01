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
		cout<<"Full Name:" <<firstName<<" "<<lastName<<endl;
		cout<<"Marks: "<<marks<<endl;
	}
};
int main()
{
	Student *s=new Student;
	cout<<"Enter first Name:"; 
	cin>>s->firstName;
	cout<<"Last Name:";
	cin>>s->lastName;
	cout<<"Enter roll number:";
	cin>>s->rollNumber;
	cout<<"Enter marks:";
	cin>>s->marks;
	
	s->displayStudentInfo();
	delete s;
	return 0;
	
}
