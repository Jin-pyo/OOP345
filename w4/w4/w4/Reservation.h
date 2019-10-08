#ifndef RESERVATION_H
#define RESERVATION_H

#include<iostream>
#include<string>
namespace sdds
{

	class Reservation
	{

		std::string m_reservation_id;
		std::string m_reservation_name;
		std::string m_email;
		int m_numOfPeople;
		int m_day;
		int m_hour;
		void check(std::string& str)const;

	public:
		Reservation() {
			this->m_reservation_id = '\0';
			this->m_reservation_name = '\0';
			this->m_email = '\0';
			this->m_numOfPeople = 0;
			this->m_day = 0;
			this->m_hour = 0;
		}
		Reservation(const std::string& m_res);
		~Reservation() {}
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);

	};


}


#endif // !RESERVATION_H