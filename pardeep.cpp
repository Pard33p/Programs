#include<iostream>
using namespace std;

class Complex
{
    int real;
    int imag;
public:
    Complex(): real(0) , imag(0) { }                  //default constructor with no arguments

    Complex(int r , int i): real(r) , imag(i) { }    //default constructor with arguments

    Complex(Complex & x)                              //copy constructor
    {
       real = x.real;
       imag = x.imag;
    }
    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};
int main( )
{
    Complex x1;
    int r,i;
    cout << "x1 is : ";  x1.display();
    cout << "Enter the real and imaginary part : ";
    cin >> r >> i;
    Complex x2(r,i);
    cout << "x2 is : ";  x2.display();

    Complex x3(x2);
    cout << "x3 is : ";  x3.display();
}
