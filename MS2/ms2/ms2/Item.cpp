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
	Utilities utility;
	char delimiter=utility.getDelimiter();
	bool check = false;

	size_t start = 0;
	size_t end = line.find(delimiter);
	this->m_name = line.substr(start, end);

	start = end + 1;
	end = line.find(delimiter, start);
	this->m_serialNumber = std::stoi(utility.extractToken(line, start, check));
	

	start = end + 1;
	end = line.find(delimiter, start);
	this->m_quantity = std::stoi(utility.extractToken(line, start, check));

	start = end + 1;
	this->m_description = utility.extractToken(line, start, check);

	if (m_widthField < m_name.length())
	{
		m_widthField = m_name.length();
	}
	


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
