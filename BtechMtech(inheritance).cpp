#include<iostream>
#include<string>
using namespace std;

class student
{
    int rollNo , age;
    string name , address;
    float cgpa;
public:
    void registration();
    void showStudent();
};
class Btech : public student
{
    string group , project;
    float marks12;
public:
    void get();
    void show();
};
class Mtech : public student
{
    string project , spec;
    float marksBtech;
public:
    void get();
    void show();
};
void student :: registration()
{
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Roll No : ";
    cin >> rollNo;
    cout << "Enter Age : ";
    cin >> age;
    cout << "Enter Address : ";
    cin >> address;
    cout << "Enter Current CGPA : ";
    cin >> cgpa;
}
void student :: showStudent()
{
    cout << "\nName : " << name ;
    cout << "\nRoll No : "<< rollNo;
    cout << "\nAge : "<< age;
    cout << "\nAddress : "<< address;
    cout << "\nCurrent CGPA : " << cgpa;
}
void Btech :: get()
{
    registration();
    cout << "Enter the marks in 12th : ";
    cin >> marks12;
    cout << "Enter the Lab Group : ";
    cin >> group;
    cout << "Enter the Project : ";
    cin >> project;
}
void Btech :: show()
{
    showStudent();
      cout << "\nMarks in 12th : " << marks12;
    cout << "\nLab Group : " << group;
    cout << "\nProject : " << project << endl;
}
void Mtech :: get()
{
    registration();
    cout << "Enter the marks in B.Tech : ";
    cin >> marksBtech;
    cout << "Enter the Project : ";
    cin >> project;
    cout << "Enter the specialization : ";
    cin >> spec;
}
void Mtech :: show()
{
      showStudent();
      cout << "\nMarks in B.Tech : " << marksBtech;
    cout << "\nSpecialization : " << spec;
    cout << "\nProject : " << project << endl;
}
int main()
{
    int choice;
       Btech b1;
        Mtech m1;
        //cout << sizeof(student) << endl <<sizeof(Btech) << endl <<sizeof(Mtech) << endl  ;
        //cout << sizeof(student) << endl <<sizeof(Btech) << endl <<sizeof(Mtech) << endl  ;
    cout << "1.B.tech\n2.M.tech\n";
    cin >> choice;
    switch(choice)
    {
        case 1:

            cout << "\t\tBachelors Of Technology\n\n";
            b1.get();
            b1.show();
            break;
        case 2:

            cout << "\n\t\tMasters Of Technology\n\n";
            m1.get();
            m1.show();
            break;
        default:
            break;
    }
}
