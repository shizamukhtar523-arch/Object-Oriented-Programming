#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double area()
    {
        return 0;
    }
};
class Rectangle : public Shape
{
    double length, width;
public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    double area()
    {
        return length * width;
    }
};
class Circle : public Shape
{
    double radius;
public:
    Circle(double r)
    {
        radius = r;
    }

    double area()
    {
        return 3.14 * radius * radius;
    }
};
int main()
{
    Shape *s;
    Rectangle r(5, 4);
    Circle c(3);
    s = &r;
    cout << "Rectangle Area = " << s->area() << endl;
    s = &c;
    cout << "Circle Area = " << s->area() << endl;
    return 0;
}
