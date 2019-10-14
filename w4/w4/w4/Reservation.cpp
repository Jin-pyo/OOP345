// Name:Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: Oct 8,2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Reservation.h"

namespace sdds
{
	void Reservation::check(std::string& str)const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Reservation::Reservation(const std::string& m_res)
	{
		size_t posS = 0;
		size_t posE = m_res.find(':');

		this->check(m_reservation_id = m_res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = m_res.find(',', posS);
		this->check(m_reservation_name = m_res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = m_res.find(',', posS);
		this->check(m_email = m_res.substr(posS, posE - posS));
		this->m_email.push_back('>');
		this->m_email.insert(0, "<");


		posS = posE + 1;
		posE = m_res.find(',', posS);
		m_numOfPeople = std::stoi(m_res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = m_res.find(',', posS);
		m_day = std::stoi(m_res.substr(posS, posE - posS));

		posS = posE + 1;
		posE = m_res.find(',', posS);
		m_hour = std::stoi(m_res.substr(posS, posE - posS));

	}


	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		
		os << "Reservation " << res.m_reservation_id << " : " << std::setw(10) << std::right << res.m_reservation_name
			<< "  " << std::left << std::setw(20) << res.m_email << "    ";
		if (res.m_hour >= 6 && res.m_hour <= 9) {
			os << "Breakfast on day ";
		}
		else if (res.m_hour >= 11 && res.m_hour <= 15) {
			os << "Lunch on day ";
		}
		else if (res.m_hour >= 17 && res.m_hour <= 21) {
			os << "Dinner on day ";
		}
		else {
			os << "Drinks on day ";
		}
		os << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_numOfPeople << " people." << std::endl;
		return os;
	}



}