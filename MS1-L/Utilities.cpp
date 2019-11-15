#include <iostream>
#include <string>
#include "Utilities.h"

char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t width) {
	m_widthField = width;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	size_t pos = str.find(m_delimiter, next_pos);
	size_t length = (pos - next_pos);
	std::string token = str.substr(next_pos, length);
	if (token != "") {
		setFieldWidth(token.length());
		more = true;
		return token;
	}
	else {
		throw "Error";
	}
}

void Utilities::setDelimiter(const char delimiter) {
	m_delimiter = delimiter;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}
