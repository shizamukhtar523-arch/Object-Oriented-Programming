#include <iostream>
using namespace std;

class Rectangle 
{
private:
    float length;
    float width;

public:
    Rectangle()
	 {
        length = 1.0;
        width = 1.0;
    }
    Rectangle(float l, float w)
	 {
        length = l;
        width = w;
    }
    Rectangle(float side)
	 {
        length = side;
        width = side;
    }
    float area() 
	{
        return length * width;
    }
    void display()
	 {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "-------------------" << endl;
    }
};

int main()
 {
    Rectangle r1;
    Rectangle r2(5.0, 3.0);
    Rectangle r3(4.0);
    cout << "Rectangle 1 (Default):" << endl;
    r1.display();
    cout << "Rectangle 2 (Length & Width):" << endl;
    r2.display();
    cout << "Rectangle 3 (Square):" << endl;
    r3.display();
    return 0;
}
