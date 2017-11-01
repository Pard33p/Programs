#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class point
{
    int x,y;
public:
    point(): x(0) , y(0)
    { }
    point(int a, int b): x(a) , y(b)
    { }
    void distance();
};
void point :: distance()
{
    float d;
    d = sqrt((x*x) + (y*y));
    cout << "Distance from origin : " <<setprecision(3)<< d << endl;
}
int main()
{
    int x,y;
    cout << "Enter x and y co-ordinates : ";
    cin >> x >> y;
    point a(x,y) , *ptr;
    ptr = &a;
    ptr->distance();
}
