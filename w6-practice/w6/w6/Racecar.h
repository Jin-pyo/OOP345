#ifndef RACECAR
#define RACECAR

#include"Car.h"

namespace sdds
{
	class Racecar :public Car
	{
		double m_booster;

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;


	};

}
#endif // !RACECAR


