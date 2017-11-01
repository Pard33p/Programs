#include<iostream>
#include<stdlib.h>
using namespace std;

class Account
{
protected:
    char accNo[20] , name[20] , address[20] ;
    long int amount;
    int month , year ;
public:
    void getAccount()
    {
        cout << "Enter Account No. : " ; cin >> accNo;
        cout << "Enter Name : " ; cin >> name;
        cout << "Enter Address : " ; cin >> address;
        cout << "Enter Amount : " ; cin >> amount;
        cout << "Enter Last Transaction Date (M/Y) : " ; cin >> month >> year;
    }
};
class Saving : public Account
{
protected:
    float interest;
};
class Fixed : public Saving
{
    int rate;
    int time;
public:
    void atm(int m , int y , bool credit ,long int am)
    {
        time = y - year;
        if(month > m)
            time--;
        if(time <= 1)
            rate = 6;
        else if(time > 1 && time <= 3)
            rate = 7;
        else
            rate =  8;
        interest = (amount * rate * time) / 100;
        amount += interest;
        if(credit)
            amount += am;
        else
            amount -= am;
        month = m;
        year = y;
        cout << "Transaction Successful\n";
        cout << "Balance Amount : Rs." << amount << "\n" ;
    }
    void display()
    {
        cout << "Name : " << name << "\nAccount No. : " << accNo << "\nAddress : " << address << "\nLast Transaction Date : " << month << "-" << year ;
        cout << "\nBalance : Rs." << amount << endl;
    }
};
int main()
{
    int choice , m , y , c;
    long int am;
    Fixed a;
    while(1)
    {
        cout << "\n1.Create Account\n2.Display\n3.Transaction\n";
        cin >> choice;
        switch(choice)
        {
        case 1:
            a.getAccount();
            break;
        case 2:
            a.display();
            break;
        case 3:
            cout << "Enter the date (M/Y) : " ; cin >> m >> y;
            cout << "1.Credit\n0.Debit\n";
            cin >> c;
            cout << "Amount to Credit/Debit : "; cin >> am;
            a.atm(m , y , c , am);
            break;
        default:
            exit(0);
        }
    }

}
