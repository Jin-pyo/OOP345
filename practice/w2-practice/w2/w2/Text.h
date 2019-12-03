// Workshop 2 - Copy and Move Semantics
// Text.h
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <string>

namespace sdds
{
	class Text
	{
		std::string* line{ nullptr };
		int n{ 0 };
	public:
		Text();
		Text(const std::string&);
		Text(const Text&);
		Text(Text&&);
		Text& operator=(const Text&);
		Text& operator=(Text&&);
		~Text();

		size_t size() const { return n; }
	};
}
#endif