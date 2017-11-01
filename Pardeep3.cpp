#include<iostream>
#include<iomanip>
using namespace std;

class matrix
{
    int **a , m , n;
public:
    matrix(int , int);           //constructor
    void display();
    ~matrix()                    //destructor
    {
        for(int i = 0; i < m ; i++)
            delete a[i];
        delete a;
    }
};
matrix :: matrix(int i , int j)
{
    m = i;
    n = j;
    a = new int*[m];                     //allocating memory dynamically for each row
    for(int k = 0; k < m ;k++)
        a[k] = new int[n];              //allocating memory dynamically for each column

     for(int i = 0 ; i < m ; i++)
   {
       for(int j = 0 ; j < n ; j++)
           cin >> a[i][j];
   }
}
void matrix :: display()
{
    for(int i = 0 ; i < m ; i++)
   {
       for(int j = 0 ; j < n ; j++)
           cout << setw(2) << a[i][j] << " ";
        cout << endl;
   }
}
int main()
{
    int p,q;
    cout << "Enter the no. of rows and columns : "; cin >> p >> q;
    cout << "Enter the elements of matrix :\n";
    matrix m(p,q);
    m.display();
    return 0;
}
