#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("notes.txt");
    file << "This is line 1." << endl;
    file << "This is line 2." << endl;
    file << "This is line 3." << endl;
    file.close();
    ifstream readFile("notes.txt");
    string line;
    cout << "File Contents:\n";
    while (getline(readFile, line))
	 {
        cout << line << endl;
    }
    readFile.close();
    ofstream appendFile("notes.txt", ios::app);
    appendFile << "Name: Shiza" << endl;
    appendFile << "Roll No: 123" << endl;
    appendFile.close();
    cout << "\nName and Roll Number appended successfully.";
    return 0;
}

