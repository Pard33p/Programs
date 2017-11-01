#include<iostream>
using namespace std;
class time
{
 int hours,mins,secs;
 public:
     time(): hours(0),mins(0),secs(0)
     {}
     time(int h,int m,int s): hours(h),mins(m),secs(s)
     {}
     void display()
     {
         cout<< hours << ":" << mins << ":" << secs << endl;
     }
     void sum(time t1, time t2)
     {
         secs = t1.secs + t2.secs;
         mins = 0;
         if(secs>=60)
         {
             secs-=60;
             mins++;
         }
         mins = mins + t1.mins + t2.mins;
         hours = 0;
         if(mins>=60)
         {
             mins-=60;
             hours++;
         }
         hours = hours + t1.hours + t2.hours;
     }


};
int main()
{
    time t1(8,50,55),t2(2,20,11),t3;
    cout<< "t1 : ";
    t1.display();
    cout<< "\nt2 : ";
    t2.display();
    t3.sum(t1,t2);
    cout<< "\nt1 + t2 : ";
    t3.display();
    return 0;
}
