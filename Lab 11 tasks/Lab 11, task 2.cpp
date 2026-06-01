#include<iostream>
using namespace std;
class Distance
 {
private:
    int feet;
    int inches;

public:
    Distance(int f, int i) 
	{
        feet = f;
        inches = i;
    }

    friend void addDistance(Distance d1, Distance d2);
};

void addDistance(Distance d1, Distance d2)
 {
    int totalInches = d1.inches + d2.inches;
    int totalFeet = d1.feet + d2.feet + totalInches / 12;
    totalInches = totalInches % 12;
    cout << "Total Distance: " << totalFeet << " feet " << totalInches << " inches" << endl;
}
int main() 
{
    Distance d1(5, 8);
    Distance d2(3, 7);
    addDistance(d1, d2);
    return 0;
}
