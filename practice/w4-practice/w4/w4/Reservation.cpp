#include "Reservation.h"
#include<iomanip>

namespace sdds
{
	void Reservation::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}
	Reservation::Reservation(const std::string& m_res)
	{
		size_t start=0;
		size_t end;

		end = m_res.find(':');
		this->m_id = m_res.substr(start, end);
		trim(m_id);
		
		start = end + 1;
		end = m_res.find(',',start);
		this->m_name = m_res.substr(start, end - start);
		trim(m_name);

		start = end + 1;
		end = m_res.find(',',start);
		this->m_email = m_res.substr(start, end - start);
		trim(m_email);

		start = end + 1;
		end = m_res.find(',',start);
		this->m_partysize = std::stoi(m_res.substr(start, end - start));

		start = end + 1;
		end = m_res.find(',',start);
		this->m_day = std::stoi(m_res.substr(start, end - start));
		
		start = end + 1;
		end = m_res.find(',', start);
		this->m_time = std::stoi(m_res.substr(start,end-start));	
	}
	std::ostream& operator<<(std::ostream& out, const Reservation& res)
	{
		std::string email = "<" + res.m_email + ">";
		out << "Reservation " << res.m_id << ": " << std::setw(11) << std::right << res.m_name << " "
			<< std::setw(23) << std::left << email<<std::right;

		if (6 <= res.m_time && res.m_time <= 9)
			out << "    Breakfast ";
		else if (11 <= res.m_time && res.m_time <= 15)
			out << "    Lunch ";
		else if (17 <= res.m_time && res.m_time <= 21)
			out << "    Dinner ";
		else
			out << "    Drinks ";
		out << "on day " << res.m_day << " @ " << res.m_time
			<< ":00 for " << res.m_partysize << " people.\n";

		return out;
	}
}