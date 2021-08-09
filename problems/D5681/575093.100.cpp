#include <iostream>
#include <string.h>
using namespace std;
class Person
{
	char *Name;
public:
	Person(){};
	Person( char *name );
	void PrintName();
};
Person::Person( char *name )
{
	Name = name;
}
void Person::PrintName()
{
	cout << Name;
}
class Student : public Person
{
public:
	Student( char *name, long number );
	void PrintInfo();
private:
	long Number;
};
Student::Student(char* name, long number):
Person(name), Number(number){}
void Student::PrintInfo()
{
	cout << "Name of Student: ";
	PrintName();
	cout << endl;
	cout << "Number of Student: ";
	cout << Number << endl;
}
int main()
{
	Student b("ssh", 100);
	b.PrintInfo();
	return 0;
}
