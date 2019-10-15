
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {
	void Book::trim(std::string& obj) const {
		size_t i = 0u;
		for (i = 0u; i < obj.length() && obj[i] == ' '; ++i);
		obj = obj.substr(i);

		for (i = obj.length(); i > 0 && obj[i - 1] == ' '; --i);
		obj = obj.substr(0, i);
	}

	Book::Book(const std::string& strBook) { // AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		size_t start = 0;
		size_t end = strBook.find(',');
		this->trim(author_ = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		this->trim(title_ = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		this->trim(country_ = strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		price_ = std::stod(strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.find(',', start);
		year_ = std::stoi(strBook.substr(start, end - start));

		start = end + 1;
		end = strBook.length();
		this->trim(desc_ = strBook.substr(start, end - start));
	}

	std::ostream& operator<<(std::ostream& os, const Book& obj) {
		os << std::left << std::setw(20) << obj.author_ << " | ";
		os << std::right << std::setw(22) << obj.title_ << " | " << std::setw(5) << obj.country_ << " | " << std::setw(4) << obj.year_ << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << obj.price_ << " | " << obj.desc_ << std::endl; 
		return os;
	}
}
