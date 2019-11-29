#include "Racecar.h"
#include<iostream>
#include<string>

namespace sdds
{
	Racecar::Racecar(std::istream& in):Car(in)
	{
		std::string tmp;
		std::getline(in, tmp,',');
		this->m_booster = std::stod(tmp);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (this->m_booster +1);
	}
}