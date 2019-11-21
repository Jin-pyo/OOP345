#include"Utilities.h"
#include<iostream>
#include<string>
#include<sstream>
#include"Car.h"
#include"Vehicle.h"
#include"Racecar.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		std::string check;

		std::getline(in, check);
		std::stringstream tmp(check);

		char type = '\0';
		char delim = '\0';

		tmp >> type >> delim;

		if (tmp)
		{
			if (type == 'c' || type == 'C')
			{
				return new Car(tmp);
			}
			else if (type == 'r' || type == 'R')
			{
				return new Racecar(tmp);
			}
			else
			{
				throw type;
			}
		}

		return nullptr;
	}
}