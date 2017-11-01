#include<iostream>
using namespace std;

class T2;
class T1
{
    int hour , minute , sec;
public:
    T1(): hour(0) , minute(0) , sec(0) { }
    T1(int h, int m, int s): hour(h) , minute(m) , sec(s) { }
    T1(T2 &);
    void display()
    {
        cout << hour << ":" << minute << ":" << sec << endl;
    }
    friend class T2;
};
class T2
{
    int hour , minute ;
public:
    T2(): hour(0) , minute(0)  { }
    T2(int h, int m): hour(h) , minute(m) { }
    T2(T1 &);
    void display()
    {
        cout << hour << ":" << minute << endl;
    }
    friend class T1;
};
T1 :: T1(T2 & t2)
{
    hour = t2.hour;
    minute = t2.minute;
    sec = 0;
}
T2 :: T2(T1 & t1)
{
    hour = t1.hour;
    minute = t1.minute;
}
int main()
{
    T1 t1(2,33,50);
    cout << "Time in class T1 : "; t1.display();
    T2 t2(t1);
    cout << "Time in class T2 : "; t2.display();
    T2 t3(5,34);
    cout << "Time in class T2 : "; t3.display();
    T1 t4 = t3;
    cout << "Time in class T1 : "; t4.display();
}
