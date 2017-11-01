#include<iostream>
using namespace std;
class time2;
class time1
{
    int h,m,s;
public:
    time1(){}
    time1(int a,int b,int c)
    {
        h=a;m=b;s=c;
    }
 operator  time2()
        {
            time2 temp;
            temp.hrs=h;
            temp.mins=float(m+s/60);
            return temp;
        }

};

class time2
{
    int hrs;
    float mins;
   public:
       time2(){
           hrs=0;
       mins=0;
       }
       void dedata()
       {
           cout<< endl<<" hours="<<hrs<< "min="<<mins<<endl;}
};


int main()
{
    time1 t1(10,20,345);
    time2 t2;
   t2=t1;

    t2.dedata();
    return 0;



}
