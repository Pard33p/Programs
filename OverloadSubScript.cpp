#include<iostream>
using namespace std;

class Array
{
    int arr[5];
public:
    Array(int *a)
    {
        for(int i = 0; i < 5 ; i++)
            arr[i] = a[i];
    }
    int operator [] (int n)
     {
         return  arr[n - 97];
     }
};
int main()
{
    int a[5] = {1,2,3,4,5};
    Array A(a);
    for(char c = 'a'; c <= 'e' ; c++)
        cout << A[c] << " ";
}
