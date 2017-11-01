#include<iostream>
using namespace std;

class matrix
{
    int row,col,**a;
public:
    matrix(int x,int y);
    void getElement(int i,int j,int value)
    {
        a[i][j] = value;
    }
    int putElement(int i,int j)
    {
        return a[i][j];
    }

};
matrix :: matrix(int x,int y)
{
    row = x;
    col = y;
    a = new int *[row];
    for(int i = 0;i < row;i++)
        a[i] = new int [col];
}
int main()
{
    int m,n;

    cout << "Enter no. of rows and columns : ";
    cin >> m >> n;
    matrix A(m,n);
    cout << "Enter the matrix elements :\n";
    int i,j,value;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> value;
            A.getElement(i,j,value);

        }
    }
    for(i = 0;i<m;i++)
    {
        for(j=0;j<n;j++)
             cout << A.putElement(i,j)<< " ";
        cout << endl;
    }

    return 0;
}
