#include<iostream>
using namespace std;

class Distance
{
    int km , m ;
public:
    Distance() : km(0) , m(0) { }
    Distance(int k , int me) : km(k) , m(me) { }
    Distance(Distance & a)
    {
        km = a.km;
        m = a.m;
    }
    void display()
    {
        cout << km << "." << m <<" km"<< endl;
    }
     operator int()
    {
        int result;
        result = km;
        return result;
    }
};
int main()
{
    Distance d1 , d2(2 ,3) , d3(d2);
    d1.display();
    d2.display();
    d3.display();

    int d = d2;
    cout << "d is " << d <<" km"<< endl;
}
