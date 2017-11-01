#include<iostream>
#include<iomanip>
using namespace std;

class matrix
{
    int a[10][10],row,col;

public:
    void get()
    {
        cout << "Enter No. of Rows and Columns : ";
        cin >> row >> col;
        cout << "Enter the elements :\n";
        for(int i = 0; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
                cin >> a[i][j];
        }
    }
    void display()
    {
        for(int i = 0; i < row ; i++)
        {
            for(int j = 0; j < col ; j++)
                cout << setw(2) << a[i][j]<<" ";
            cout << endl;
        }
    }
    friend matrix add(matrix, matrix);
};
matrix add(matrix m1,matrix m2)
{
    matrix m;
    m.row = m1.row;
    m.col = m2.col;
    for(int i = 0;i<m1.row;i++)
    {
        for(int j=0;j<m1.col;j++)
            m.a[i][j] = m1.a[i][j] + m2.a[i][j];
    }
    return m;
}
int main()
{
    matrix m1,m2,m3;
    m1.get();
    m2.get();
    m3 = add(m1,m2);
    m3.display();
    return 0;



}
