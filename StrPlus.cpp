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
        strcpy(s, p);
    }
    void display()
    {
        cout << s << endl;
    }
    void operator = (String a)
    {
        len = a.len;
        s = new char[len + 1];
        strcpy(s , a.s);
    }
    String operator += (String a)
    {
        String temp;
        temp.len = len + a.len;
        temp.s = new char[temp.len + 1];
        strcpy(temp.s , s);
        strcat(temp.s , a.s);
        len = temp.len;
        s = new char[len + 1];
        strcpy(s , temp.s);
        return temp;
    }
};
int main()
{
    String a("New ");
    String b;
    b = a;
    String c = "Delhi";
    b += c;
    b.display();
    a = b += c;
    a.display();
    return 0;
}
