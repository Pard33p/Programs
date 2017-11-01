#include<iostream>
using namespace std;
class data
{

public:
    int x;
    friend void print(data);
};
void print(data a)
{
    cout << a.x;
}
int main()
{
    data d;
    int data::* ptr = &data:: x;
    void (data::*ptr1)(data) = &data::print;
    d.*ptr = 10;
    print(d);
}
