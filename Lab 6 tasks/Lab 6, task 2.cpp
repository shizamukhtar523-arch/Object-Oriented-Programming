#include <iostream>
using namespace std;

class BankAccount 
{
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
       BankAccount(string accNo, string accHolder, double bal) {
        accountNumber = accNo;
        accountHolder = accHolder;
        balance = bal;
    }
    void showAccountDetails() 
	{
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
 {
    BankAccount acc1("PK0309800780100", "Muhammad Awais", 10000);
    acc1.showAccountDetails();
   return 0;
}
