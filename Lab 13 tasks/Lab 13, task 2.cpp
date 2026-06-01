#include <iostream>
using namespace std;
template <typename T>
T findMin(T a, T b)
 {
    return (a < b) ? a : b;
}
int main() 
{
    cout << findMin(3, 7) << endl;
    cout << findMin(2.5, 1.8) << endl;
    cout << findMin('z', 'a') << endl;
    return 0;
}
