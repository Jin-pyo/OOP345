#include "Movie.h"
#include<iostream>
#include<iomanip>
#include<string>

namespace sdds
{
	void Movie::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}
	Movie::Movie(const std::string& strMovie)
	{
		size_t start = 0;
		size_t end = strMovie.find(',');
		this->m_title = strMovie.substr(start, end);
		trim(m_title);

		start = end + 1;
		end = strMovie.find(',', start);
		this->m_year = std::stoi(strMovie.substr(start, end - start));

		start = end + 1;
		this->m_description = strMovie.substr(start);
		trim(m_description);
	}

	std::ostream& operator<<(std::ostream& out, const Movie& theMovie)
	{
		out << std::setw(40) << theMovie.m_title << " | "
			<< std::setw(4) << theMovie.m_year << " | "
			<< theMovie.m_description << "\n";
		return out;
	}
}