#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"

class Item {
	std::string m_name;
	std::string m_description;
	size_t m_serialNumber;
	int m_quantity = 0;
	static size_t m_widthField;
public:
	Item(const std::string record);
	const std::string& getName() const {
		return m_name;
	}
	const unsigned int getSerialNumber();
	const unsigned int getQuantity() {
		return m_quantity;
	}
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif