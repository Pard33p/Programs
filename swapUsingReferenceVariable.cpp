#include<iostream>
using namespace std;
void swapR(int & x,int & y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

int main()
{
    int a,b;
    cout << "Enter a and b : ";
    cin >> a >> b;
    swapR(a,b);
    cout << "a = "<< a << endl << "b = "<< b << endl;
    return 0;

}
