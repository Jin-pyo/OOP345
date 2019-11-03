// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Car.h"
#include<iostream>
#include<string>
#include <iomanip>

namespace sdds
{
	std::string& Car::trim(std::string& check)
	{
		while (check.length() > 0 && check[0] == ' ')
			check.erase(0, 1);
		while (check.length() > 0 && check[check.length() - 1] == ' ')
			check.erase(check.length() - 1, 1);
		return check;
	}

	Car::Car(std::istream& info)
	{
		std::string check;

		std::getline(info, check, ',');

		m_model = trim(check);

		std::getline(info, check, ',');
		trim(check);
		if (check == "" || check == "n")
			m_condition = "new";
		else if (check == "b")
			m_condition = "broken";
		else if (check == "u")
			m_condition = "used";
		else
			throw "Invalid record!";

		std::getline(info, check, ',');
		try
		{
			m_topSpeed = std::stoi(trim(check));
		}
		catch (...)
		{
			throw "Invalid record!";
		}

	}
	std::string Car::condition()const
	{
		return m_condition;
	}
	double Car::topSpeed()const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& os)const
	{
		os << "|" << std::setw(10) << this->m_model
			<< "|" << std::setw(6) << std::left << this->m_condition
			<< "|" << std::setw(6) << std::setprecision(2) << std::fixed << this->m_topSpeed;

	}
}
