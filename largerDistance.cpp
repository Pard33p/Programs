#include<iostream>
using namespace std;

class Distance
{
    int feet;
    int inches;
public:
    Distance(): feet(0) , inches(0)
    { }
    Distance(int f, int i): feet(f) , inches(i)
    { }
    friend void MAX(Distance ,Distance);
};
void MAX(Distance a, Distance b)
{
    if(a.feet > b.feet)
    {
        cout << a.feet << "\' " << a.inches << "\" is larger\n";
    }
    else if(a.feet == b.feet)
    {
        if(a.inches == b.inches)
            cout << "Both are equal \n";
        else if(a.inches > b.inches)
             cout << a.feet << "\' " << a.inches << "\" is larger\n";
        else
             cout << b.feet << "\' " << b.inches << "\" is larger\n";
    }
    else
         cout << b.feet << "\' " << b.inches << "\" is larger\n";

}
int main()
{
    int x,y;
    cout << "Enter the first distance : ";
    cin >> x >> y;
    Distance a(x,y);
    cout << "Enter the 2nd distance : ";
    cin >> x >> y;
    Distance b(x,y);
    MAX(a,b);
}
