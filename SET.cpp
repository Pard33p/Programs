#include<iostream>
#include<stdlib.h>
using namespace std;

class SET
{
    int *arr , len;
public:
    SET()
    {
        len = 1;
        arr = new int[1];
        arr[0] = 0;
    }
    SET(int *a , int n)
    {
        len = n;
        arr = new int[len];
        for(int i = 0 ; i < len ; i++)
            arr[i] = a[i];
    }
    void display()
    {
        cout << "{ ";
        for(int i = 0; i < len ; i++)
            cout << arr[i] << " , " ;
         cout << "\b\b\b }\n\n";
    }
    SET operator * (SET a)
    {
        SET temp;
        temp.len = len < a.len ? len : a.len;
        temp.arr = new int[temp.len];
        int p = 0;
        for(int i = 0 ; i < len; i++)
        {
            for(int j = 0; j < a.len ; j++)
            {
                if(arr[i] == a.arr[j])
                    temp.arr[p++] = arr[i];
            }
        }
        temp.len = p;
        return temp;
    }
    SET operator - (SET a)
    {
        SET temp;
        temp.len = len < a.len ? len : a.len;
        temp.arr = new int[temp.len];
        int p = 0 , flag;
        for(int i = 0 ; i < len; i++)
        {
            flag = 0;
            for(int j = 0; j < a.len ; j++)
            {
                if(arr[i] == a.arr[j])
                    flag = 1;
            }
            if(!flag)
               temp.arr[p++] = arr[i];
        }
        temp.len = p;
        return temp;
    }
    SET operator + (SET a)
    {
        SET temp;
        temp.len = len + a.len ;
        temp.arr = new int[temp.len];
        int p = 0 , flag = 0;
        for(int i = 0 ; i < len; i++)
        {
              temp.arr[p++] = arr[i];
        }
        for(int j = 0 ; j < a.len; j++)
        {
            flag = 0;
            for(int i = 0; i < len ; i++)
            {
                if(arr[i] == a.arr[j])
                    flag = 1;
            }
            if(!flag)
               temp.arr[p++] = a.arr[j];
        }
        temp.len = p;
        return temp;
    }
};
int main()
{
    int a[20] , b[20] , a1[20] , a2[20]  ,p1 = 0 , p2 = 0 , n1 , n2;
    cout << "Enter Set 1 :\nn = ";
    cin >> n1;
    cout << "Enter elements :\n";
    for(int i = 0 ; i < n1 ; i++)
        cin >> a[i];
    for(int i = 0; i < n1; i++)
    {
        if(a[i] != -1)
            a1[p1++] = a[i];
        for(int j = i+1; j < n1; j++)
        {
            if(a[i] == a[j])
                a[j]  = -1;
        }
    }
    cout << "Enter Set 2 :\nn = ";
    cin >> n2;
    cout << "Enter elements :\n";
    for(int i = 0 ; i < n2 ; i++)
        cin >> b[i];
    for(int i = 0; i < n2 ; i++)
    {
          if(b[i] != -1)
            a2[p2++] = b[i];
        for(int j = i+1; j < n2; j++)
        {
            if(b[i] == b[j])
                b[j]  = -1;
        }
    }
    SET s1(a1 , p1);
    SET s2(a2 , p2);
    cout << "S1 = "; s1.display();
    cout << "S2 = "; s2.display();
    cout << endl;
    SET temp;
    int choice;
    while(1)
    {
       cout << "1.Union \n2.Intersection\n3.Subtraction\n";
    cin >> choice;
    switch(choice)
    {
    case 1:
        temp = s1 + s2;
        temp.display();
        break;
    case 2:
        temp = s1 * s2;
        temp.display();
        break;
    case 3:
        temp = s1 - s2;
        temp.display();
        break;
    default:
        exit(0);
    }
    }
}
