#include<iostream>
#include<string>
using namespace std;

class salary
{
protected:
    float basicPay;
    int HRA , PA , DA;
public:
    void getSalary()
    {
        cout << "Enter Basic Pay : ";
        cin >> basicPay;
        cout << "Enter HRA : ";
        cin >> HRA;
        cout << "Enter PA : ";
        cin >> PA;
        cout << "Enter DA : ";
        cin >> DA;
    }
};
class organization
{
    string name , address;
public:
    void getOrg()
      {
          cout << "Enter Organization Name : ";
          cin >> name;
          cout << "Enter Address of Organization : ";
          cin >> address;
      }
      void showOrg()
      {
          cout << "\nOrganization Name : " << name << endl;
          cout << "Organization Address : " << address;
      }
};
class emp
{
    string name ,  address , designation;
protected:
     bool type;
public:
    void checkType()
    {
        int check;
        cout << "Press 1 for Regular and 2 for Contract : ";
        cin >> check;
        if(check == 1)
            type = true;
        else
            type = false;
    }
    void getEmp()
    {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter Address : ";
        cin >> address;
        cout << "Enter Designation : ";
        cin >> designation;
        cout << "Employee Type :\n";
        checkType();
    }
    void showEmp()
    {
        cout << "\nName : " << name;
        cout << "\nAddress : " << address;
        cout << "\nDesignation : " << designation;
        if(type)
            cout << "\nType : Regular";
        else
            cout << "\nType : Contract";
    }
};
class employee : public salary , public emp , public organization
{
    string joindate;
    float totalSalary;
    int workingHours;
public:
    void getEmployee()
    {
        getEmp();
        getOrg();
        getSalary();
        cout << "Enter Join Date(DD-MM-YYYY) : ";
        cin >> joindate;
        cout << "Enter Working Hours : ";
        cin >> workingHours;
        if(type)
            totalSalary = basicPay + (basicPay * HRA / 100) + (basicPay * PA / 100) + (basicPay * DA / 100);
        else
            totalSalary = basicPay + (basicPay * HRA / 100) ;
    }
    void show()
    {
        showEmp();
        showOrg();
        cout << "\nJoining Date : " << joindate;
        cout << "\nWorking Hours : " << workingHours;
        cout << "\nTotal Salary : Rs." << totalSalary << endl;
    }
};

int main()
{
    employee e1;
    e1.getEmployee();
    e1.show();
}
