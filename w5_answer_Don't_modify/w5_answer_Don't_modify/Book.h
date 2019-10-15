
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
#include "SpellChecker.h"

namespace sdds {
	class Book {
		std::string author_;
		std::string title_;
		std::string country_;
		size_t year_ = 0;
		double price_ = 0;
		std::string desc_;
	public:
		Book() {}
		Book(const std::string& strBook);
		void trim(std::string& obj) const;
		const std::string& title() const { return title_; }
		const std::string& country() const { return country_; }
		const size_t& year() const { return year_; }
		double& price() { return price_; }

		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(desc_);
		}		

		~Book() {};
		friend std::ostream& operator<<(std::ostream&, const Book&);
	};
}

#endif