#include<iostream>
using namespace std;
int fun()
{
    return 1;
}
float fun()
{
    return 8.7;
}
int main()
{
   cout << (float)fun();
    cout << (int)fun();
}
