// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Nov 4,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef UTILITY_H
#define UTILITY_H

namespace sdds
{
	class Utilities:public Vehicle
	{
	public:
		Vehicle* createInstance(std::istream& in);

	};
}

#endif // !UTILITY_H



