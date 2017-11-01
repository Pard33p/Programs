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
    String(const char *p)
    {
        len = strlen(p);
        s = new char[len + 1];
        strcpy(s , p);
    }
    String(String & a)
    {
        len = strlen(a.s);
        s = new char[len + 1];
        strcpy(s , a.s);
    }
    ~String()
    {
        delete s;
    }
    friend String operator+(const String & , const String &);
    friend int operator <= (const String & , const String &);
    friend void show(const String a)
    {
        cout << a.s << endl;
    }
};
String operator+(const String & a , const String & b)
{
    String temp;
    temp.len = a.len + b.len;
    temp.s = new char[temp.len + 1];
    strcpy(temp.s ,  a.s);
    strcat(temp.s , b.s);
    return (temp);
}
int operator <= (const String & a , const String & b)
{
    int l1 = strlen(a.s) , l2 = strlen(b.s);
    if(l1 <= l2)
        return 1;
    else
        return 0;
}
int main()
{
    String a("hello");
    show(a);
    String b("kida");
    show(b);
    String c;
    c = b + a;
    show(c);
    if(a <= b)
        cout << "True\n";
    else
        cout << "False";
}
