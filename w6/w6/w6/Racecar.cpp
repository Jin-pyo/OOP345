// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include"Car.h"
#include"Racecar.h"
#include<iostream>

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string check;
		std::getline(in, check, ',');
		this->m_booster = std::stod(trim(check));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed()*(1+this->m_booster);
	}
}