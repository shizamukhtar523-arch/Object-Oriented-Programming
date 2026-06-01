#include<iostream>
#include<string>
using namespace std;
class BankAccount 
{
private:
    string holderName;
    double balance;
    static int totalAccounts;
public:
    BankAccount(string name, double bal) 
	{
        holderName = name;
        balance = bal;
        totalAccounts++;
    }
    void display() 
	{
        cout << "Account Holder: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
    static void showTotalAccounts()
	 {
        cout << "Total Accounts Created: " << totalAccounts << endl;
    }
};
int BankAccount::totalAccounts = 0;
int main()
 {
    BankAccount a1("Ali", 5000);
    BankAccount a2("Sara", 8000);
    BankAccount a3("Ahmed", 12000);
    a1.display();
    a2.display();
    a3.display();
    BankAccount::showTotalAccounts();
    return 0;
}
