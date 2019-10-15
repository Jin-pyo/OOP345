
#include <string>
#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	void Movie::trim(std::string& obj) const {
		size_t i = 0u;
		for (i = 0u; i < obj.length() && obj[i] == ' '; ++i);
		obj = obj.substr(i);

		for (i = obj.length(); i > 0 && obj[i - 1] == ' '; --i);
		obj = obj.substr(0, i);
	}

	Movie::Movie(const std::string& strMovie) {
		size_t start = 0;
		size_t end = strMovie.find(',');
		this->trim(title_ = strMovie.substr(start, end - start));

		start = end + 1;
		end = strMovie.find(',', start);
		releaseYear_ = std::stoi(strMovie.substr(start, end - start));

		start = end + 1;
		end = strMovie.length();
		this->trim(desc_ = strMovie.substr(start, end - start));
	}

	std::ostream& operator<<(std::ostream& os, const Movie& obj) {
		os << std::right << std::setw(40) << obj.title_ << " | ";
		os << std::setw(4) << obj.releaseYear_ << " | ";
		os << std::left << obj.desc_ << std::endl;
		return os;
	}
}
