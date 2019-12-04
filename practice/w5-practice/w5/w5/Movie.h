#pragma once

#include<iostream>


namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
		void trim(std::string& str) const;

	public:
		Movie() {}
		const std::string& title()const { return m_title; }
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};

}
