#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.cpp"

class customer : public Person
{
	private:
		int MechanicID;
		Appointment appointment;
	public:
		customer();
		void set_MechanicID(int);
		void set_appointment(Appointment);
		int get_MechanicID();
		Appointment get_appointment();
		bool operator == (const customer &);
		bool operator > (const customer &);
		bool operator < (const customer &);
};
#endif
