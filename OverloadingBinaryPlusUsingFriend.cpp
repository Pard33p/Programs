#include<iostream>
#include<iomanip>
using namespace std;

class Complex
{
    int real , imag;
public:
    Complex() {}
    Complex(int r , int i): real(r) , imag(i) {}
    void display()
    {
        cout << real << " + i" << imag << '\n';
    }
    friend Complex operator + (Complex , Complex);
};
Complex operator + (Complex a , Complex b)
{
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}
int main()
{
    Complex A(2,3) , B(5,6);
    cout << setw(8) <<"A = "; A.display();
    cout << setw(8) << "B = "; B.display();
    Complex C;
    C = A + B;
    cout << "A + B = "; C.display();
}
