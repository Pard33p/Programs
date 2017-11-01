#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a , b;
    cout << "Enter the string : ";
    getline(cin , a);
    int Count = 0;
    cout << "Enter the sub-string : ";
    cin >> b;
    int x = 0;

    int i = 0;
    while((x = a.find(" s" , x+ 1 )) != -1)
    {
        Count++;
    }
    cout << Count << endl;
    return 0;

}
