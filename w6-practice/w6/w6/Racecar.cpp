#include "Racecar.h"
#include<iostream>
#include<string>

namespace sdds
{
	Racecar::Racecar(std::istream& in) :Car(in)
	{
		std::string check;
		std::getline(in, check, ',');
		this->m_booster = std::stod(Car::trim(check));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << " * ";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1+this->m_booster);
	}
}