#ifndef MECHANIC_H
#define MECHANIC_H
#include "Customer.cpp"
#include <vector>

class mechanic : public Person
{
	private:
		int counter;
		vector <Appointment> appoint;
	public:
		mechanic();
		bool isAvailable(Appointment);
		void set_counter(int);
		void set_appointment(Appointment, int);
		void add_appointment(Appointment);
		int get_counter();
		Appointment get_appointment(int);
		void display_appointments();
		void clear_appointments();
};
#endif
