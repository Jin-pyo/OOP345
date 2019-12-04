#include "Racecar.h"
#include<iostream>
#include<string>

namespace sdds
{
	Racecar::Racecar(std::istream& in):Car(in)
	{
		std::string line;
		std::getline(in, line, ',');
		m_booster=std::stod(Car::trim(line));
	
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + this->m_booster);
	}
}