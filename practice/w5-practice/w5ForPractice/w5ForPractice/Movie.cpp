#include "Movie.h"
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>

namespace sdds
{
	void Movie::check(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Movie::Movie(const std::string& strMovie)
	{
		size_t posS = 0;
		size_t posE = strMovie.find(",");
		this->m_Mtitle = strMovie.substr(posS, posE);

		posS = posE + 1;
		posE = strMovie.find(",", posS);
		this->m_Myear = std::stoi(strMovie.substr(posS, posE - posS));

		posS = posE + 1;
		this->check(m_Mdescription = strMovie.substr(posS));

		
	}


	std::ostream& operator<<(std::ostream& os, const Movie obj)
	{
		os << std::setw(40) << obj.m_Mtitle << " | "
			<< std::setw(4) << obj.m_Myear << " | "
			<< obj.m_Mdescription;
	}




}

