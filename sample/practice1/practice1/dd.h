#ifndef DD_H
#define DD_H

#include<cstring>
#include"process.h"
#include<iostream>

namespace sdds
{
	extern int g_maxSize;
	class String
	{
		char* name;
	public:
		String(const char* n);
		String(const String&);
		String& operator=(const String& src);
		void display(std::ostream& os) const;


	};

	std::ostream& operator<<(std::ostream& os, const String& src);


}

#endif