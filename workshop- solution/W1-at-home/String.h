// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// String.h
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

#ifndef SDDS_STRING_H
#define SDDS_STRING_H

#include <iostream>

namespace sdds
{
	extern unsigned int g_maxSize;

	class String
	{
		char* m_str;
	  public:
		String(const char*);
		String(const String&);
		String& operator=(const String&);
		~String();
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const String&);
}

#endif

