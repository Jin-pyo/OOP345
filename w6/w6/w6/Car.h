// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef CAR_H
#define CAR_H

#include<iostream>
#include"Vehicle.h"

namespace sdds
{
	class Car:public Vehicle
	{
		std::string m_model;
		std::string m_condition;
		int m_topSpeed;
	public:
		Car(std::istream&);
		std::string condition()const;
		double topSpeed()const;
		void display(std::ostream& os)const;
		std::string& trim(std::string&);

	};
}
#endif // !CAR_H



