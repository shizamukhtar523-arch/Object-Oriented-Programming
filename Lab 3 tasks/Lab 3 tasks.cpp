#include <iostream>
#include <string>
using namespace std;
class Product
 {
private:
    string name;
    double price;
    int quantity;
public:
    void setName(string n)
	 {
        if (n == "") 
		{ 
		cout << "Error: Name is empty!" << endl; }
        else
		 { name = n; 
		}
    }
    void setPrice(double p) 
	{
        if (p <= 0) 
		{ 
		cout << "Error: Price must be > 0!" << endl; }
        else 
		{ price = p; }
    }
    void setQuantity(int q) 
	{
        if (q < 0) 
		{ 
		cout << "Error: Quantity can't be negative!" << endl; }
        else 
		{ quantity = q;
		 }
    }
    string getName() { return name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
};
int main()
 {
    Product p;
    p.setName(""); 
    p.setPrice(-50);
    p.setName("Laptop");
    p.setPrice(1200.50);
    p.setQuantity(5);
    cout << "Product: " << p.getName() << " | Price: $" << p.getPrice() << endl;
    return 0;
}
