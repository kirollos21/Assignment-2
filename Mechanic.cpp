#include <iostream>
#include "Mechanic.h"
using namespace std;

mechanic::mechanic()
{
	counter = 0;
}
bool mechanic::isAvailable(Appointment app)
{
	bool an = 1;
	for(int i =0 ; i<counter; i++)
		if((app.hours == appoint[i].hours)&&(app.mins == appoint[i].mins))
			an = 0;
	return an;
}
int mechanic::get_counter()
{
	return counter;
}
Appointment mechanic::get_appointment(int index)
{
	if((index>0)&&(index<counter))
		return appoint[index];
}
void mechanic::add_appointment(Appointment app)
{
	if(isAvailable(app))
	{
		appoint.push_back(app);
		counter++;
	}
}
void mechanic::display_appointments()
{
	for(int i =0 ; i<counter; i++)
	{
		cout<<"Appointment number ("<< (i+1) <<") ->  "<<appoint[i].hours<<" : "<<appoint[i].mins<<endl;
	}
}
void mechanic::set_appointment(Appointment app, int index)
{
	if((index>0)&&(index<counter))
	{
		appoint[index].hours = app.hours;
		appoint[index].mins = app.mins;
	}
}
void mechanic::set_counter(int x)
{
	counter = x;
}
void mechanic::clear_appointments()
{
	appoint.clear();
	counter = 0;
}
