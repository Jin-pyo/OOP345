#ifndef STRING_H
#define STRING_H


#include<iostream>
namespace sdds
{
	extern unsigned int g_maxSize;
	class String
	{
		char* name;
	public:
		String(const char*);
		void display(std::ostream&) const;

		
	};

	std::ostream& operator<<(std::ostream& os, const String& a);
}

#endif

