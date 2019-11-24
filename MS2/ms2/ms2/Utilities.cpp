// Name: Jinpyo Ju
// Seneca Student ID: 134444181	
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/17/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<string>
#include "Utilities.h"



char Utilities::m_delimiter = '\0';

void Utilities::setFieldWidth(size_t width)
{
	this->m_widthField = width;
}
size_t Utilities::getFieldWidth() const
{
	return this->m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	//start from "next_pos" and find "m_delimiter"
	size_t position = str.find(this->m_delimiter, next_pos);

	//cut from "next_pos" to the amount of "position-next_pos"  
	std::string token = str.substr(next_pos, position - next_pos);

	if (token != "")
	{
		more = true;
		setFieldWidth(token.size());
		return token;
	}
	else
	{
		more = false;
		throw "There are empty value";
	}
}
void Utilities::setDelimiter(const char delimiter)
{
	m_delimiter = delimiter;
}
const char Utilities::getDelimiter() const
{
	return this->m_delimiter;
}