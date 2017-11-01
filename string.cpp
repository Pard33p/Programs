#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1("qwerty");
    string s2("asdfg");

    cout<<"\nOriginal Strings are \n"<<"s1:"<<s1<<"\n"<<"s2:"<<s2;

    cout<<"\nplace s2 inside s1\n";
    s1.insert(3,s2);
    cout<<"So new S1="<<s1;

     cout<<"\nErasing the charachters from s1\n";
    s1.erase(3,5);
    cout<<s1;


    cout<<"\nreplacing the middle three alphabets of s2 with s1";
    s2.replace(1,3,s1);
    cout<<"\nSo s2:"<<s2;

    cout<<"\nreplacing both s2 and s1 to original\n";
    s2="asdfg";

    cout<<"the third alphabet at s2= "<<s2.at(2);

    cout<<"\nadding u at last of s1";
    s1.append(1,'u');
    cout<<"\n"<<s1;

    cout<<"\nNow comparing the length of s1 with respect to s2:";
    int x=s1.compare(s2);
    cout<<x;
    cout<<"\nNow comparing the length of s2 with respect to s1:";
    x=s2.compare(s1);
    cout<<x;

    cout<<"\n\nassigning new strings\ns1 = road\ns2 = read\ns3 = red\n";
    s1="Road";
    s2="read";
    string s3("red");

    x=s1.compare(s2);
    if(x==0)
        cout<<"s1==s2\n";
    else if(x>0)
        cout<<"s1 > s2\n";
    else
        cout<<"s1 > s2\n";
    int a=s1.compare(0,2,s2,0,2);
    int b=s2.compare(0,2,s1,0,2);
    int c=s1.compare(0,2,s3,0,2);
    int d=s2.compare(s2.size()-1,1,s3,s3.size()-1,1);

    cout<<"a= "<<a<<"\nb= "<<b<<"\nc= "<<c<<"\nd= "<<d;

    cout<<"\nBefore swap: \n";
    cout<<"s1 = "<<s1<<"\ns2 = "<<s2;
    s1.swap(s2);
     cout<<"\nAfter swap: \n";
    cout<<"s1 = "<<s1<<"\ns2 = "<<s2;

    cout<<"\nlength of s1 = "<<s1.length();
    cout<<"\nSize of s2 = "<<s2.size();
    cout<<"\nCapacity of s1 = "<<s1.capacity();

    cout<<"\n\nnew strings assigned";
    string s("ONE TWO THREE FOUR");

    cout<<"\nthe string contains: \n";
    for(int i=0;i<s.length();i++)
        cout<<s.at(i);
    cout<<"\nstrings is shown again: \n";
    for(int j=0;j<s.length();j++)
        cout << s[j];

    int x1=s.find("TWO");
    cout<<"\nTWO is found at: "<<x1;

    x=s.find_first_of('T');
    cout<<"\nT is found first at: "<<x;

    x=s.find_last_of('R');
    cout<<"\nR is last found at: "<<x;

    cout<<"\nretrieve and print substring TWO\n";
    cout<<s.substr(x1,3);

}
