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
#include"Vehicle.h"

namespace sdds
{
	class Autoshop :public Vehicle
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out)const;



	};
}
#endif // !AUTOSHOP_H



