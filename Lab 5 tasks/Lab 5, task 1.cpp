#include <iostream>
using namespace std;
class Product
{
protected:
    string name;
    float price;
public:
    Product(string n, float p)   
    {
        name = n;
        price = p;
    }
};
class Electronics : public Product
{
private:
    int warrantyYears;
public:
    Electronics(string n, float p, int w) : Product(n, p)   
    {
        warrantyYears = w;
    }
    void display()
    {
        cout << "Product Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Warranty: " << warrantyYears << " years" << endl;
    }
};
int main()
{
    Electronics e("Laptop", 80000, 2);
    e.display();
}
