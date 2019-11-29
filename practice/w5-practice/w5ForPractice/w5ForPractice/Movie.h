#ifndef MOVIE_H
#define MOVIE_H

#include<iostream>

namespace sdds
{

	class Movie
	{
		std::string m_Mtitle;
		size_t m_Myear;
		std::string m_Mdescription;
		void check(std::string&) const;
	public:
		Movie() {};
		const std::string& title()const { return this->m_Mtitle; };
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie obj);

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_Mdescription);
		}
	};


}

#endif // !MOVIE_H
