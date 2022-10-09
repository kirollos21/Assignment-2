#include <iostream>
#include "Customer.h"
using namespace std;

customer::customer()
{
	MechanicID=0;
	appointment.hours=0;
	appointment.mins=0;
}
int customer::get_MechanicID()
{
	return MechanicID;
}
Appointment customer::get_appointment()
{
	return appointment;
}
void customer::set_appointment(Appointment app)
{
	appointment.hours=app.hours;
	appointment.mins=app.mins;
	while((appointment.hours>24)||(appointment.hours<0)||(appointment.mins>59)||(appointment.mins<0)||((appointment.hours==24)&&(appointment.mins!=0)))
	{
		cout<<"Enter valid appointment!!"<<endl<<"Enter the hours (0-24) : ";
		cin>>appointment.hours;
		cout<<"Enter the minutes (0-60) : ";
		cin>>appointment.mins;
	}
}
void customer::set_MechanicID(int mecid)
{
	MechanicID=mecid;
}
bool customer::operator == (const customer &customer1)
{
	if((customer1.appointment.hours == appointment.hours)&&(customer1.appointment.mins == appointment.mins))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool customer::operator > (const customer &customer1)
{
	if((appointment.hours > customer1.appointment.hours)||((appointment.hours == customer1.appointment.hours)&&(appointment.mins > customer1.appointment.mins)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool customer::operator < (const customer &customer1)
{
	if((appointment.hours < customer1.appointment.hours)||((appointment.hours == customer1.appointment.hours)&&(appointment.mins < customer1.appointment.mins)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
