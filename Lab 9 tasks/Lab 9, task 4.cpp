#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    ofstream file("students.txt");
    file << "Ali - 101" << endl;
    file << "Ahmed - 102" << endl;
    file << "Sara - 103" << endl;
    file.close();
    ifstream readFile("students.txt");
    string line;
    cout << "Student Details:\n";
    while (getline(readFile, line)) 
	{
        cout << line << endl;
    }
    readFile.close();
    return 0;
}
