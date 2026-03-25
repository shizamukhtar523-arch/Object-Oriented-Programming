#include <iostream>
using namespace std;
class Printer
 {
public:
    void print_document()
	 {
        cout << "Printing document..." << endl;
    }
};
class Scanner 
{
public:
    void scan_document()
	 {
        cout << "Scanning document..." << endl;
    }
};
class Photocopier : public Printer, public Scanner 
{
public:
    void photocopy() 
	{
        print_document();
        scan_document();
        cout << "Photocopy completed." << endl;
    }
};
int main()
 {
    Photocopier p;
    p.print_document();
    p.scan_document();
    p.photocopy();
    return 0;
}
