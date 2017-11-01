#include<iostream>
using namespace std;

class employee
{
    class date
    {
        int month,day,year;
    public:
        void getDate()
        {
            cout << "Enter the date (MM/DD/YY) : ";
            cin >> month >> day >> year;
        }
        void showDate()
        {
            cout << month << "/" << day << "/" << year << endl;
        }
    };
    enum etype {laborer , secretary , manager , accountant , executive , researcher};
    int eNo,emptype;
    float compensation;
    date d;
    public:
        void getemp();
        void putemp();

};
void employee :: getemp()
{
    char c;
     cout << "Enter the employee no. : ";
     cin >> eNo;
     cout << "Enter the compensation : ";
     cin >> compensation;
     cout << "Enter the date of joining : ";
     d.getDate();
     cout << "Enter type of employee(l,s,m,a,e,r) ";
     cin >>c;
     switch(c)
     {
     case 'l':
        emptype = laborer;
        break;
      case 's':
        emptype = secretary;
        break;
      case 'm':
        emptype = manager;
        break;
      case 'a':
        emptype = accountant;
        break;
       case 'e':
        emptype = executive;
        break;
       case 'r':
        emptype = researcher;
        break;
     }

}
void employee :: putemp()
{
    cout << "\nEmployee No. : " << eNo << endl;
    cout << "Compensation : Rs. " << compensation << endl;
    cout << "Date of Joining : " ; d.showDate();
    cout << "Employee type : ";
    switch(emptype)
    {
    case laborer:
        cout << "Laborer\n";
        break;
    case secretary:
        cout << "Secretary\n";
        break;
     case manager:
        cout << "Manager\n";
        break;
     case accountant:
        cout << "Accountant\n";
        break;
     case executive:
        cout << "Executive\n";
        break;
     case researcher:
        cout << "Researcher\n";
        break;
    }
}
int main()
{
    employee a;
    a.getemp();
    a.putemp();
}
