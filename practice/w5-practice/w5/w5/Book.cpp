#include "Book.h"
#include<iostream>
#include<iomanip>

namespace sdds
{
	void Book::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}
	Book::Book(const std::string& strBook)
	{
		size_t start = 0;
		size_t end = strBook.find(',', start);
		m_author = strBook.substr(start, end);
		trim(m_author);

		start = end + 1;
		end = strBook.find(',', start);
		m_title = strBook.substr(start, end - start);
		trim(m_title);

		start = end + 1;
		end = strBook.find(',', start);
		m_country = strBook.substr(start, end - start);
		trim(m_country);

		start = end + 1;
		end = strBook.find(',', start);
		m_price = std::stod(strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		m_year = std::stoi(strBook.substr(start, end - start));

		start = end + 1;
		m_description = strBook.substr(start);
		trim(m_description);

	}
	Book::Book()
	{

	}
	const std::string& Book::title() const
	{
		return this->m_title;
	}
	const std::string& Book::country() const
	{
		return this->m_country;
	}
	const size_t& Book::year() const
	{
		return this->m_year;
	}
	double& Book::price()
	{
		return this->m_price;
	}

	std::ostream& operator<<(std::ostream& os, const Book& theBook)
	{
		os << std::setw(20) << theBook.m_author << " | "
			<< std::setw(22) << theBook.m_title << " | "
			<< std::setw(5) << theBook.m_country << " | "
			<< std::setw(4) << theBook.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << theBook.m_price << " | "
			<< theBook.m_description << "\n";
		return os;
	}
	
}