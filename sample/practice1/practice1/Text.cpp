#include<iostream>
#include<cstring>
#include"dd.h"

#define _CRT_SECURE_NO_WARNINGS

namespace sdds
{
	int g_maxSize = 3;

	String::String(const char* cst)
	{
		if (cst != nullptr)
		{
			int len = g_maxSize;

			if (len < g_maxSize)
			{
				len = strlen(cst);
			}
			this->name = new char[len+1];
			strncpy(this->name, cst, len);
			name[len] = '\0';
		}
		else
		{
			name = nullptr;
		}
	}

	void String::display(std::ostream& os) const
	{
		os << this->name;
	}

	String::String(const String& src)
	{
		*this = src;
	}
	String& String::operator=(const String& src)
	{
		if (this != &src)
		{
			delete[]this->name;
			int len = g_maxSize;
			if (strlen(src.name) < g_maxSize)
			{
				len = strlen(src.name);
			}
			name = new char[len + 1];
			strncpy(name, src.name, len);
			name[len] = '\0';
			
		}

		return *this;
	}



	std::ostream& operator<<(std::ostream &os, const String& src)
	{

		static int num = 1;
		os << num++ << ":";
		src.display(os);
		return os;
	}

}