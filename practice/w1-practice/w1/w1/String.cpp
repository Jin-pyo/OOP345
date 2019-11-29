#include "String.h"
#include<iostream>
#include<cstring>

namespace sdds
{
	unsigned int g_maxSize = 3;

	String::String(const char* name)
	{
		this->name = new char[g_maxSize+1];
		strncpy(this->name, name, g_maxSize);
		this->name[g_maxSize] = '\0';
	}

	void String::display(std::ostream& os) const
	{
		os << this->name;
	}


	std::ostream& operator<<(std::ostream& os, const String& a)
	{
		static int n = 0;
		os << ++n << ": ";
		a.display(os);
		return os;
	}
}