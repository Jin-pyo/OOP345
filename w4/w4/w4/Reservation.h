#ifndef RESERVATION_H
#define RESERVATION_H

#include<string>

namespace sdds
{
	class Reservation
	{
		std::string m_id;
		std::string m_name;
		std::string m_email;
		int m_numOfPeople;
		unsigned m_day;
		unsigned m_hour;

	public:
		Reservation();
		Reservation(const std::string& m_res);

	};
}

#endif