#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    int real , imag;
public:
    Complex(): real(0) , imag(0) {}
    Complex(int r , int i) : real(r) , imag(i) {}
    void display() { cout << real << " + i"<<imag << '\n'; }
    friend Complex operator + (Complex , Complex);
    friend Complex operator + (Complex , int);
    friend Complex operator + (int , Complex);
    friend bool operator == (Complex , Complex);
    friend bool operator <= (Complex , Complex);
    friend istream & operator >> (istream & , Complex &);
    friend ostream & operator << (ostream & , Complex &);
};
Complex operator + (Complex a , Complex b)
{
    return Complex(a.real + b.real , a.imag + b.imag);
}
Complex operator + (Complex a, int x)
{
    return Complex(a.real + x , a.imag + x);
}
Complex operator + (int x , Complex a)
{
    return Complex(a.real + x , a.imag + x);
}
bool operator == (Complex a , Complex b)
{
    if((a.real == b.real) && (a.imag == b.imag) )
        return true;
    else
        return false;
}
bool operator <= (Complex a , Complex b)
{
    double x , y;
    x = sqrt((a.real * a.real) + (a.imag * a.imag) );
    y = sqrt((b.real * b.real) + (b.imag * b.imag) );
    if(x <= y)
        return true;
    else
        return false;
}
istream & operator >> (istream & din , Complex & a)
{
    din >> a.real;
    din >> a.imag;
    return din;
}
ostream & operator << (ostream & dout , Complex & a)
{
    dout << a.real << " + i" << a.imag ;
    return dout;
}

int main()
{
    Complex a , b;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << endl;
    Complex c = a + b;
    cout <<"("<<a <<")"<<" + " <<"("<< b<<")" << " = "<< c <<endl;
    c = a + 3;
    cout <<"("<< a <<")"<< " + " << "3" << " = "<< c << endl;
    c = 2 + b;
    cout << 2<<" + ("<<b<<") = "<< c << endl;
    if(a  <= b)
        cout << a << " is less \than or equal to "<< b << endl;
    else
        cout << a<< " is greater than "<< b << endl;
     if( a == b )
            cout << a << " is equal to " << b << endl ;
      else
             cout << a << " is not equal to " << b << endl ;
}
