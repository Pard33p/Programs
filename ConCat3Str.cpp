#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char *s;
    int len;
public:
    String()
    {
        len = 0;
        s = new char[len + 1];

    }
    String(char *p)
    {
        len = strlen(p);
        s = new char[len + 1];
        strcpy(s , p);
    }
    void display() { cout << s << endl; }
    friend String operator + (String a , String b);
};
String operator + (String a , String b)
{
    String temp;
    temp.len = a.len + b.len;
    temp.s = new char[temp.len + 1];
    strcpy(temp.s , a.s);
    strcat(temp.s , b.s);
    return temp;
}
int main()
{
    String a = "Martin " , b = "Luther " , c = "King";
    String d;
    d = a + b + c;
    d.display();
}
