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

		std::string line;
		char type = '\0';
		char delim = '\0';

		getline(in, line);
		std::stringstream ss(line);
		ss >> type >> delim;

		if (ss)
		{
			if (type == 'c' || type == 'C')
			{
				return new Car(ss);
			}
			else if (type == 'r' || type == 'R')
			{
				return new Racecar(ss);
			}
			else
				throw type;
		}
		return nullptr;

	}
}