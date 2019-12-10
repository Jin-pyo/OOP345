#include "Car.h"
//#include<iostream>
#include<string>
#include<iomanip>

namespace sdds
{
	std::string& Car::trim(std::string& token)
	{
		while (token.length() > 0 && token[0] == ' ')
			token.erase(0, 1);
		while (token.length() > 0 && token[token.length() - 1] == ' ')
			token.erase(token.length() - 1, 1);
		return token;
	}
	Car::Car(std::istream& in)
	{
		std::string tmp;
		std::getline(in, tmp, ',');

		trim(this->m_model = tmp);

		std::getline(in, tmp, ',');
		trim(this->m_condition = tmp);

		if (m_condition == "n"||m_condition=="")
		{
			m_condition = "new";
		}
		else if (m_condition == "u")
		{
			m_condition = "used";
		}
		else if (m_condition == "b")
		{
			m_condition = "broken";
		}
		else
		{
			throw "Invalid data";
		}

		std::getline(in, tmp, ',');
		try{
		m_topSpeed = std::stod(trim(tmp));
		}
		catch (...)
		{
			throw "invalid data";
		}

	}

	std::string Car::condition() const
	{
		return this->m_condition;
	}
	double Car::topSpeed() const
	{
		return this->m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << " | " << std::setw(10) << this->m_model
			<< " | " << std::setw(6)<<std::left << this->condition()
			<< " | " << std::setw(6) << std::fixed << std::setprecision(2) <<std::right<< topSpeed()<<" |";

	}
	
}