// Workshop 2 - Copy and Move Semantics
// Text.cpp
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel

#include <fstream>
#include <utility>
#include "Text.h"

namespace sdds {
	// default constructor
	//
	Text::Text() : line(nullptr), n(0) {}

	// constructor
	//
	Text::Text(const std::string& filename)
	{
		std::ifstream f(filename.c_str());
		n = 0;
		line = nullptr;
		if (!f)
			return;

		do
		{
			char c = f.get();
			if (c == ' ')
				n++;
		} while (!f.eof());

		f.seekg(std::ios::beg);
		line = new std::string[n];
		for (int i = 0; i < n; i++)
			std::getline(f, line[i], ' ');
	}

	// Copy Constructor
	//
	Text::Text(const Text& src)
	{
		*this = src;
	}

	// Move Constructor
	//
	Text::Text(Text&& src)
	{
		*this = std::move(src);
		//*this = src;
	}

	// Copy Assignment Operator
	//
	Text& Text::operator=(const Text& src)
	{
		if (this != &src)
		{
			n = src.n;

			delete[] line;
			line = nullptr;
			if (n != 0)
			{
				line = new std::string[n];
				for (int i = 0; i < n; i++)
					line[i] = src.line[i];
			}
		}
		return *this;
	}

	// Move Assignment Operator
	//
	Text& Text::operator=(Text&& src)
	{
		if (this != &src)
		{
			n = src.n;

			delete[] line;
			line = src.line;
			src.n = 0;
			src.line = nullptr;
		}
		return *this;
	}

	// Destructor
	//
	Text::~Text()
	{
		delete[] line;
	}
}