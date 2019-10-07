#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include "Book.h"

namespace sdds
{
	void Book::check(const std::string& str)
	{
		unsigned i;
		for (i = 0u; i < str.length() && str[i] == ' '; i++);
		str.substr(i);

		for (i = str.length(); i > 0 && str[i] == ' '; i--);
		str.substr(0, i);
	}
	Book::Book(const std::string& strBook)
	{
		size_t posS = 0;
		size_t posE = strBook.find(',');
		this->m_author = strBook.substr(posS, posE);
		check(m_author);

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->m_title = strBook.substr(posS, posE);
		check(m_title);

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->m_country = strBook.substr(posS, posE);
		check(m_country);

		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_price = std::stod(strBook.substr(posS, posE - posS));
		
		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_year = std::stoi(strBook.substr(posS, posE - posS));

		posS = posE + 1;
		this->check(m_description = strBook.substr(posS));
	}

	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os<<std::setw(20)<<book.m_author<<" | "
			<<std::setw(22)<<
	}

}