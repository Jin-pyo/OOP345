// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "String.h"

namespace sdds
{
	unsigned int g_maxSize = 3;

	String::String(const char* s)
	{
		if (s != nullptr)
		{
			int size = g_maxSize > std::strlen(s) ? std::strlen(s) : g_maxSize;
			m_str = new char[size + 1];
			std::strncpy(m_str, s, size);
			this->m_str[size] = '\0';
		}
		else
			m_str = nullptr;
	}

	String::String(const String& src)
	{
		m_str = nullptr;
		*this = src;
	}

	String& String::operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] this->m_str;
			if (other.m_str != nullptr)
			{
				int size = g_maxSize > std::strlen(other.m_str) ? std::strlen(other.m_str) : g_maxSize;
				this->m_str = new char[size + 1];
				std::strncpy(this->m_str, other.m_str, size);
				this->m_str[size] = '\0';
			}
			else
			{
				m_str = nullptr;
			}
		}
		return *this;
	}

	String::~String()
	{
		delete [] m_str;
	}

	// display inserts str into os
	//
	void String::display(std::ostream& os) const
	{
		os << m_str;
	}

	// operator inserts a into os with an accumulating prefix
	//
	std::ostream& operator<<(std::ostream& os, const String& a)
	{
		static int n = 0;
		os << ++n << ": ";
		a.display(os);
		return os;
	}
}
