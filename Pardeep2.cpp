#include<iostream>
#include<cstring>
using namespace std;

class book
{
    int lengthN , lengthA;
    char *name , *author;
public:
    book()
    {
        lengthN = 0;
        lengthA = 0;
        name = new char[lengthN + 1];
        author = new char[lengthA + 1];
    }
    book(char * n , char * a)
    {
        lengthN = strlen(n);
        lengthA = strlen(a);
        name = new char[lengthN + 1];
        author = new char[lengthA + 1];
        strcpy(name,n);
        strcpy(author , a);
    }
    book(book & b)
    {
        strcpy(name , b.name);
        strcpy(author , b.author);
    }
    ~book()
    {
      delete name;
      delete author;
    }
    void display()
    {
       cout << "Book Name : " << name << "\nAuthor Name : " << author << endl;
    }
};
int main()
{
    book b1("letUsC","Yashwant");
    book b2(b1);
    b1.display();
    b2.display();
}
