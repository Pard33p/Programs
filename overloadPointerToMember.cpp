#include<iostream>
using namespace std;

class test
{
public:
    int num;
    test(int j): num(j) {}
    test * operator -> ()
    {
        return this;
    }
};

int main()
{
    test a(5);
    test *ptr = &a;
    cout << a.num << endl;
    cout << ptr->num << endl;
    cout << a->num << endl;
    return 0;
}
