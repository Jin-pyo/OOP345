
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>

namespace sdds {
	class Movie {
		std::string title_;
		size_t releaseYear_ = 0;
		std::string desc_;
	public:
		Movie() {};
		const std::string& title() const { return title_; };
		Movie(const std::string&);
		void trim(std::string& obj) const;

		template <typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(title_);
			spellChecker(desc_);
		}

		~Movie() {};
		friend std::ostream& operator<<(std::ostream&, const Movie&);
	};
}

#endif
