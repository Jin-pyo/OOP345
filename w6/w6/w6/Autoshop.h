// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef AUTOSHOP_H
#define AUTOSHOP_H

#include<vector>
#include<list>

#include"Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop() = default;
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out)const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++)
			{
				if (test(*it))
				{
					vehicles.push_back(*it);
				}
			}
		}
	};
}
#endif // !AUTOSHOP_H



