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
	int n,i;
	cout<<"Enter number of students:";
	cin>>n;
	
	Student students[n];
	for(i=0 ; i<n ; i++)
	{
		cout<<"Enter details for student:"<<i+1<<":\n";
		cout<<"First Name: ";
		cin>>students[i].firstName;
		cout<<"Last Name:";
		cin>>students[i].lastName;
		cout<<"Roll number:";
		cin>>students[i].rollNumber;
		cout<<"Marks:";
		cin>>students[i].marks;
	}
	for(int i=0 ; i<n  ; i++)
	{
		students[i].displayStudentInfo();
		cout<<endl;
	}
	return 0;
}
