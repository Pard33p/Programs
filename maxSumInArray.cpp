#include<iostream>
using namespace std;

int main()
{
    int arr[50],sum = 0,n,large = 0,low = 0,high = 0;
    cout << "Enter the no. of elements : ";
    cin >> n;
    cout << "Enter the elements :\n";
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            sum = 0;
            for(int k = i;k<=j;k++)
                sum = sum + arr[k];
            if(sum > large)
            {
                large = sum;
                low = i;
                high = j;
            }
        }
    }
    cout << "Largest Sum Possible is "<< large << "\nLower index = " << low << "\nHigher index = " << high << endl;
    return 0;
}
