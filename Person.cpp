#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
	Name="";
	ID=0;
	Age=0;
}
int Person::get_Age()
{
	return Age;
}
int Person::get_ID()
{
	return ID;
}
string Person::get_Name()
{
	return Name;
}
void Person::set_Age(int a)
{
	Age=a;
}
void Person::set_ID(int id)
{
	ID=id;
}
void Person::set_Name(string n)
{
	Name=n;
}
void Person::print()
{
	cout<<"The name is "<< Name << endl;
	cout<<"The age is "<< Age << endl;
	cout<<"The ID is "<< ID << endl;
}
