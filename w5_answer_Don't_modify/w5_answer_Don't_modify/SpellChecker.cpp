
#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <string>

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file.is_open())
			throw "Bad file name!";
		else {
			size_t i = 0;
			while (file) {
				file >> m_badWords[i];
				file >> m_goodWords[i];
				i++;
			}
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		for (size_t i = 0; i < (sizeof(m_badWords)/sizeof(m_badWords[0])); i++) {
			size_t found = text.find(m_badWords[i]);
 			while (found != std::string::npos) {
				text.replace(found, m_badWords[i].size(), m_goodWords[i]);
				found = text.find(m_badWords[i], found + m_goodWords[i].size());
			}
		}		
	}
}