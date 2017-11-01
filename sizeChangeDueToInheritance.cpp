#include<iostream>
using namespace std;

class A
{
    int a , b  , c;
 protected:
     int p , q;
 public:
    int k ,l;
 /*public:
     void get()
       {
         //cin  >> a >> b >> c;
       }*/
};
class B : public A
{
    int x , y;
 /*public:
     void get()
        {cin  >> x >> y ;}*/
};
class C : public B
{
    int n,m;
};
int main()
{
    cout << sizeof(C);
}
