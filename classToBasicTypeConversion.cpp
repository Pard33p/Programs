#include<cmath>
#include<iostream>
using namespace std;

class Complex
{
    int real , imag;
public:
    Complex(int r , int i): real(r) , imag(i) {}
    void display() { cout << real << " + i" << imag << endl;}
    operator double()                       //casting operator function with no arguments and return type. It must be member function.
    {
        double result;
        result = sqrt(  (real * real) + (imag * imag)  );
        return result;                            //but it do return a value
    }
};

int main()
{
   Complex x(3,4);
   x.display();
   double result = x;
   cout << result << endl;
}
