// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Autoshop.h"
#include<iostream>


namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out)const
	{
		
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!|" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}
}