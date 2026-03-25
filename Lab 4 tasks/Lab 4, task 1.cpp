#include <iostream>
using namespace std;
class Person
 {
public:
    string name;
    int age;
    void display_person_info()
	 {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Student : public Person
 {
public:
    int student_id;
    void display_student_info()
	 {
        cout << "Student ID: " << student_id << endl;
    }
};
int main() 
{
    Student s;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Student ID: ";
    cin >> s.student_id;
    cout << "\nStudent Information\n";
    s.display_person_info();
    s.display_student_info();
    return 0;
}
