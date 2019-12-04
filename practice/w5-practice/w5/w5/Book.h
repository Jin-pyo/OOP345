#pragma once

#include<iostream>
#include<string>

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		double      m_price = 0;
		size_t      m_year = 0;
		void trim(std::string& str) const;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& os, const Book& theBook);

		template<typename T>
		void fixSpelling(T SpellChecker)
		{
			SpellChecker(m_description);
		}
	};

}
