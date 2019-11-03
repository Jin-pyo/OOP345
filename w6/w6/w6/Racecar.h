// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef RACECAR_H
#define RACECAR_H

#include<iostream>
#include"Car.h"

namespace sdds
{

	class Racecar :public Car
	{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpped() const;

	};
}

#endif // !RACECAR_H


