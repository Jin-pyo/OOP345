#include <iostream>
#include <string>
#include "Item.h"

size_t Item::m_widthField = 1;

Item::Item(const std::string record) {
	bool more = false;
	Utilities m_utility;
	char d = m_utility.getDelimiter();
	size_t start = 0;
	size_t end = record.find(d);
	m_name = record.substr(start, end);

	start = end + 1;
	end = record.find(d, start);
	m_serialNumber = std::stoi(m_utility.extractToken(record, start, more));

	start = end + 1;
	end = record.find(d, start);
	m_quantity = std::stoi(m_utility.extractToken(record, start, more));

	start = end + 1;
	end = record.find(d, start);
	m_description = m_utility.extractToken(record, start, more);
	
	if (m_widthField < m_name.length()) {
		m_widthField = m_name.length();
	}
}

const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
	m_serialNumber++;
}

void Item::updateQuantity() {
	if (m_quantity >= 0) {
		m_quantity--;
	}
}

void Item::display(std::ostream& os, bool full) const {
	os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name << " [";
	os << std::setfill('0') << std::setw(6) << std::left << m_serialNumber << "] ";
	if (full == true) {
		os << std::setfill(' ') << "Quantity: " << std::setw(m_widthField) << std::left << m_quantity;
		os << " Description: " << m_description;
	}
	os << std::endl;
}