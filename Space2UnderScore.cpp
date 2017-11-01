#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    getline(cin , a);
    for(int i = 0; i < a.length(); i++)
    {
        if(a.at(i) == ' ')
            a[i] = '_';
    }
    int x = a.find('_');
    cout << x << endl;
    cout << a << endl;
}

