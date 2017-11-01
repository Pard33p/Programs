#include<iostream>
#include<cstdlib>
using namespace std;
class bank
{
    char name[20];
    int accNo;
    float balance;
public:
    void create()
    {
        cout << "Enter Name : ";
        cin >> name;
        cout << "\nEnter Acc. No. : ";
        cin >> accNo;
        balance = 0;
    }
    void deposit()
    {
        float amount;
        cout << "Enter the amount : ";
        cin >> amount;
        balance += amount;
    }
    void withdraw()
    {
        float amount;
        cout<< "Current Balance : Rs." << balance<<endl;
        cout << "Enter Amount to Withdraw : ";
        cin >> amount;
        balance -=amount;
        cout << "Withdraw Successful!!"<<endl;
        cout << "Balance : Rs." << balance<<endl;
    }
    void display()
    {
        cout << "Name : "<< name << endl;
        cout << "Account No. : "<< accNo<<endl;
        cout << "Balance : Rs."<< balance << endl;

    }
};


int main()
{
    bank a1;
    int choice;
    while(1)
    {
        cout << "\n1.Create Account\n2.Deposit\n3.Withdraw\n4.Display\n\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            a1.create();
            break;
        case 2:
            a1.deposit();
            break;
        case 3:
            a1.withdraw();
            break;
        case 4:
            a1.display();
            break;
        default:
            exit(0);
        }



    }
    return 0;
}
