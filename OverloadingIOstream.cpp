#include<iostream>
using namespace std;
const int Size = 3;

class Vector
{
    int v[Size];
public:
    Vector();
    Vector(int *x);
    friend Vector operator * (int a , Vector b);
    friend Vector operator * (Vector b , int a);
    friend istream & operator >> (istream & , Vector &);
    friend ostream & operator << (ostream & , Vector &);
};
Vector :: Vector()
{
    for(int i = 0; i < Size ; i++)
        v[i] = 0;
}
Vector :: Vector(int *x)
{
    for(int i = 0; i < Size ; i++)
        v[i] = x[i];
}
Vector operator * (int a, Vector b)
{
    Vector c;
    for(int i = 0; i < Size ; i++)
      c.v[i] = b.v[i] * a;
    return c;
}
Vector  operator * (Vector b , int a)
{
    Vector c;
    for(int i = 0; i < Size ; i++)
      c.v[i] = b.v[i] * a;
    return c;
}
istream & operator >> (istream & din , Vector &b)
{
    for(int i = 0; i < Size ; i++)
       din >> b.v[i];
    return din;
}
ostream & operator << (ostream &dout , Vector &b)
{
    for(int i = 0; i < Size ; i++)
        dout << " " << b.v[i];
    return dout;
}
int x[Size] = {2 , 3, 4};

int main()
{
    Vector m;
    Vector n = x;

    cout << "Enter the elements of vector m : \n";
    cin >> m;
    cout << "\n m = " << m << '\n';

    Vector p , q;
    p = 2 * m;
    q = n * 2;
    cout << "\n p = " << p << '\n';
    cout << "\n q = " << q << '\n';

  return 0;
}
