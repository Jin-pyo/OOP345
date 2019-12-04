#ifndef DEBUG_H
#define DEBUG_H
#include<vector>
#include"Vehicle.h"
#include<list>

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		~Autoshop();
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
			{
				if (test(*i))
				{
					vehicles.push_back(*i);
				}
			}
		}
	};
}


#endif // DEBUG_H



