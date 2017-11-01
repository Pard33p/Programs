#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char s[20];
public:
    void get();
    void display();
};
void String :: get()
{
    cout << "Enter the string : ";
    cin >> s;
}
void String :: display()
{
    int flag;
    for(int i = 0; i < strlen(s) ;i++)
    {
        flag = 0;
        for(int j = i+1; j < strlen(s); j++)
        {
            if(s[i] == '#')
                flag = 1;
            if( s[i] == s[j] )
            {
                s[j] = '#';
                flag = 1;
            }
        }
        if(flag == 0)
        {
            cout << s[i];
            break;
        }
    }
}

int main()
{
    String a;
    a.get();
    a.display();
}
