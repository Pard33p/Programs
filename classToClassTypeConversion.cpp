#include<iostream>
using namespace std;
class T2;
class T1
{
    int hour , mins , sec ;
public:
    T1(): hour(0) , mins(0) , sec(0) {}
    T1(int h , int m , int s): hour(h) , mins(m) , sec(s) {}
    void display() { cout << hour << " : " << mins << " : "<< sec <<endl; }
     operator T2();
     friend class T2;
};
class T2
{
    int hour , mins ;
public:
    T2(): hour(0) , mins(0)  {}
    T2(int h , int m ): hour(h) , mins(m) {}
    void display() { cout << hour << " : " << mins << endl; }
    /*T2(T1 a)
    {
        hour = a.hour;
        mins = a.mins;
    }*/
    friend class T1;
    /*operator T2()
    {
        T2 x;
        x.hour = hour;
        x.mins = mins;
        return x;
    }*/
};
T1 :: operator T2()
    {
        T2 x;
        x.hour = hour;
        x.mins = mins;
        return x;
    }
int main()
{
    T1 a(12,45,33);
    a.display();
    T2 b = a;
    b.display();
}
