#ifndef CAR_H
#define	CAR_H

#include"Vehicle.h"
#include<string>
namespace sdds
{
	class Car :public Vehicle
	{
		std::string m_model;
		std::string m_condition;
		int m_topSpeed;
	protected:
		std::string& trim(std::string& token);
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		
	};
	

}

#endif
