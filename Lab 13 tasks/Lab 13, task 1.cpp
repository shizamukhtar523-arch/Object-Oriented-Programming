#include <iostream>
using namespace std;
template <typename T>
void printTwice(T val) 
{
    cout << val << endl;
    cout << val << endl;
}
int main() 
{
    printTwice(42);
    printTwice(3.14);
    printTwice("Hello");
    return 0;
}
