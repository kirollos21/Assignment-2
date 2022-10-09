#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

struct Appointment
{
	int hours;
	int mins;	
};

class Person
{
	protected:
		string Name;
		int ID;
		int Age;
	public:
		Person();
		void print();
		void set_Name(string);
		void set_ID(int);
		void set_Age(int);
		string get_Name();
		int get_ID();
		int get_Age();
};
#endif
