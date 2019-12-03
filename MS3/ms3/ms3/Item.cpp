// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/17/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Item.h"
#include<iostream>
#include <iomanip>

size_t Item::m_widthField = 1;

Item::Item(std::string line)
{
	Utilities utilities;
	bool more = true;
	size_t next_pos = 0u;


	m_name = utilities.extractToken(line, next_pos, more);
	m_serialNumber = std::stoi(utilities.extractToken(line, next_pos, more));
	m_quantity = std::stoi(utilities.extractToken(line, next_pos, more));
	m_widthField = utilities.getFieldWidth();
	m_description = utilities.extractToken(line, next_pos, more);

	


}
const std::string& Item::getName() const
{
	return this->m_name;
}
const unsigned int Item::getSerialNumber()
{
	return this->m_serialNumber++;
	
}
const unsigned int Item::getQuantity()
{
	return this->m_quantity;
}
void Item::updateQuantity()
{
	this->m_quantity--;
	if (m_quantity < 0)
	{
		throw "error";
	}
}
void Item::display(std::ostream& os, bool full) const
{
	if (full == false)
	{
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name 
		 << " [" << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << "] ";
	}
	else{
	os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_name 
		<< " [" << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << "] "
		<< std::setfill(' ') << "Quantity: " << std::setw(m_widthField) << std::left << m_quantity
		<< " Description: " << m_description;
	}
	os << std::endl;
}
