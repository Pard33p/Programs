#include<iostream>
using namespace std;

//class T2;

class T1
{
    int hour , mins , sec;
public:
    T1(): hour(0) , mins(0) , sec(0) { }
    T1(int h , int m , int s): hour(h) , mins(m) , sec(s) { }
    void display()
    {
        cout << hour << ":" << mins << ":" << sec << endl;
    }

};
class T2
{
    int hour , mins;
public:
    T2(): hour(0) , mins(0) { }
    T2(int h , int m): hour(h) , mins(m) { }
    void display()
    {
        cout << hour << ":" << mins << endl;
    }
    operator T1()
    {
        return T1(hour , mins , 0);
    }

};
int main()
{
    T2 t2(12,34);
    t2.display();
     T1 t1 = t2;
     t1.display();
}
