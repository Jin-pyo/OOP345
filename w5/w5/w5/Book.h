#ifndef BOOK_H
#define BOOK_H

#include<iostream>

namespace sdds
{
	class Book
	{


		std::string m_author;
		std::string m_title;
		std::string m_country;
		double m_price;
		size_t m_year;
		std::string m_description;
		void check(const std::string& str);

	public:

		Book() {};
		const std::string& title() const { return this->title; };
		const std::string& country() const { return this->country; };
		const size_t& year() const { return this->m_year; };
		double& price() { return m_price; };
		Book(const std::string& strBook);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};

}

#endif