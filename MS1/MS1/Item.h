// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/17/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

#include<string>
#include<iostream>
#include<iomanip>
#include"Utilities.h"

class Item
{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity=0;
	static size_t m_widthField;

public:
	Item(std::string line);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;



};

#endif