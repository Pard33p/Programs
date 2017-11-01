#include<iostream>
using namespace std;
class dist
{
    int m;
    int cm;
public:
    dist(){}
    dist (int a,int b)
    {
        m=a;
        cm=b;
    }
    operator int()
     {
         return (m*100+cm);}

};
int main()
{  int a;
    dist s(12,23);
    a=s;
    cout<< a;
}
