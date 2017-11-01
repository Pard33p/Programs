#include<cstring>
#include<iostream>
using namespace std;

class String
{
    char *s;
    int len;
public:
    String()
    {
        len = 0;
        s = new char[len+1];
    }
    String(const char *p)
    {
        len = strlen(p);
        s = new char[len + 1];
        strcpy(s,p);
    }
    /*String(String & a)                       //if copy constructor is defined then there will be error in line 34
    {
        len = strlen(a.s);
        s = new char[len + 1];
        strcpy(s,a.s);
    }*/
    void show()
    {
        cout << s << endl;
    }
};
int main()
{
    String p = "hello";
    p.show();
}
