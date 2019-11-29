#include "Car.h"
//#include<iostream>
#include<string>
#include<iomanip>

namespace sdds
{

	std::string& Car::trim(std::string& line)
	{
		while (line.length() > 0 && line[0] == ' ')
			line.erase(0, 1);
		while (line.length() > 0 && line[line.length() - 1] == ' ')
			line.erase(line.length() - 1, 1);

		return line;
	}
	Car::Car(std::istream& file)
	{
		std::string check;

		std::getline(file, check, ',');

		this->m_maker = trim(check);

		std::string tmp;
		std::getline(file, check, ',');
		tmp = trim(check);

		if (tmp == "" || tmp == "n")
		{
			this->m_condition = "new";
		}
		else if (tmp == "u")
		{
			this->m_condition = "used";
		}
		else if (tmp == "b")
		{
			this->m_condition = "broken";
		}
		else
		{
			throw "invalid data0000";
		}



		std::getline(file, check, ',');
		try {
			this->m_topSpeed = std::stoi(check);
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
	double Car::topSpeed()const
	{
		return this->m_topSpeed;
	}
	void Car::display(std::ostream& out)const
	{
		out << "| " << std::setw(10) << std::right << this->m_maker
			<< " | " << std::setw(6) << std::left << this->m_condition
			<< " | " << std::setw(6) << std::setprecision(2) << std::fixed << topSpeed() << " | ";
	}
}