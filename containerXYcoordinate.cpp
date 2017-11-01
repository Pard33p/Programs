#include<iostream>
#include<cmath>
using namespace std;

class coordinate
{
    int x , y;
public:
    coordinate() { }
    coordinate(int X , int Y) : x(X) , y(Y)
    { }
    double distance(coordinate b)
    {
        double dist;
        dist = sqrt( ( (x - b.x) * (x - b.x) ) + ( (y - b.y) * (y - b.y) )   );
        return dist;
    }
};
class rectangle
{
    double Area;
    coordinate a , b, c , d;
public:
    rectangle(int a1 , int a2 , int b1 , int b2  , int c1 , int c2 , int d1 , int d2) :
        a(a1 , a2) , b(b1 , b2) , c(c1 , c2) , d(d1 , d2)
        {
         Area = a.distance(b) * a.distance(d);
        }
        void show()
        {
            cout << "Area of rectangle is : " << Area << "\n";
        }
};
class triangle
{
    double Area;
    coordinate a , b, c ;
public:
    triangle(int a1 , int a2 , int b1 , int b2  , int c1 ,int  c2) :
        a(a1 , a2) , b(b1 , b2) , c(c1 , c2)
        {
         double s = ( a.distance(b) + a.distance(c) + b.distance(c) ) / 2;
         Area = sqrt( s * (s - a.distance(b)) * (s - a.distance(c)) * (s - b.distance(c)));
        }
        void show()
        {
            cout << "Area of triangle is : " << Area << "\n";
        }
};
int main()
{
    rectangle R(0 , 0 , 3 , 2 , 3 , 4 , 1 , 2);
    R.show();
    triangle T(1 ,1 , 1 , 3 , 4 , 1);
    T.show();
}
