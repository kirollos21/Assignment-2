#include <iostream>
#include <fstream>
#include "Mechanic.cpp"
#include "template.cpp"
using namespace std;

main()
{
	mechanic m;
	customer c;
	string n;
	int x, num;
	Appointment appo;
	vector<mechanic> mec;
	customer *cus;
	queue<customer> custque;
	ifstream R("input.txt");
	while (! R.eof())
	{
		R>>n;
		m.set_Name(n);
		R>>x;
		m.set_Age(x);
		R>>x;
		m.set_ID(x);
		R>>x;
		for(int i=0; i<x; i++)
		{
			R>>appo.hours;
			R>>appo.mins;
			m.add_appointment(appo);
		};
		mec.push_back(m);
		m.clear_appointments();
	};
	R.close();
	/*
	//mechanics appointments before
	cout << mec[0].get_Name() << " :\n";
	mec[0].display_appointments();
	cout << mec[1].get_Name() << " :\n";
	mec[1].display_appointments();
	cout << mec[2].get_Name() << " :\n";
	mec[2].display_appointments();
	*/
	/*
	//manual customer data entering
	cout << "Enter the number of the customers : ";
	cin >> num;
	cus = new customer [num];
	for (int j=0; j<num; j++)
	{
		cout << "Enter your name : ";
		cin >> n;
		cus[j].set_Name(n);
		cout << "Enter your age : ";
		cin >> x;
		cus[j].set_Age(x);
		cout << "Enter your appointment (ex: 1 30) : ";
		cin >> appo.hours;
		cin >> appo.mins;
		cus[j].set_appointment(appo);
	};*/
	ifstream CR("cust.txt");
	CR>>num;
	cus = new customer [num];
	for(int j=0; j<num; j++)
	{
		CR>>n;
		cus[j].set_Name(n);
		CR>>x;
		cus[j].set_Age(x);
		CR>>appo.hours;
		CR>>appo.mins;
		cus[j].set_appointment(appo);
	};
	CR.close();
	x=0;
	for (int a=0; a<num; a++)
	{
		if(mec[x].isAvailable(cus[a].get_appointment()))
		{
			mec[x].add_appointment(cus[a].get_appointment());
			cus[a].set_MechanicID(mec[x].get_ID());
		}
		else
		{
			mec[++x].add_appointment(cus[a].get_appointment());
			cus[a].set_MechanicID(mec[x].get_ID());
		}
		if (x<2)
			x++;
		else
			x=0;
	}
	for (int r=0; r<num; r++)
	{
		x=0;
		for (int q=0; q<mec.size(); q++)
		{
			if (cus[r].get_MechanicID()==mec[q].get_ID())
				x=q;
		}
		cout << "Mr/s. " << cus[r].get_Name() << " should be assigned to " << mec[x].get_Name() << " at " << cus[r].get_appointment().hours << ":" << cus[r].get_appointment().mins << "." << endl;
	}
	cout << endl << endl;
	for (int k=0; k<num; k++)
	{
		for (int l=k; l<num; l++)
		{
			if (cus[k]>cus[l])
			{
				c=cus[k];
				cus[k]=cus[l];
				cus[l]=c;
			}
		}
	}
	for (int m=0; m<num; m++)
	{
		custque.push(cus[m]);
	}
	for (int n=0; n<num; n++)
	{
		x=0;
		for (int q=0; q<mec.size(); q++)
		{
			if (custque.peek().get_MechanicID()==mec[q].get_ID())
				x=q;
		}
		cout << "Mr/s. " << custque.peek().get_Name() << " has an appointment at " << custque.peek().get_appointment().hours << ":" << custque.peek().get_appointment().mins << " with " << mec[x].get_Name()  << "." << endl;
		custque.pop();
	}
	/*
	//mechanics appointments after
	cout << mec[0].get_Name() << " :\n";
	mec[0].display_appointments();
	cout << mec[1].get_Name() << " :\n";
	mec[1].display_appointments();
	cout << mec[2].get_Name() << " :\n";
	mec[2].display_appointments();
	*/
	return 0;
}
