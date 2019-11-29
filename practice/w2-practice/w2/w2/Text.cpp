#include<fstream>
#include<utility>
#include "Text.h"

namespace sdds
{
	Text::Text()
	{
		this->line = nullptr;
		this->n = 0;
	}
	Text::Text(const std::string& name)
	{
		std::ifstream f(name.c_str());
		if (!f)
			return;

		line = nullptr;
		n = 0;
		do
		{
			char c = f.get();
			if (c == ' ')
				n++;
		} while (f.eof());

		f.seekg(std::ios::beg);
		line = new std::string[n];
		for (int i= 0; i < n; i++)
			std::getline(f, line[i], ' ');
	}
	Text::Text(const Text& obj)
	{
		*this = obj;
	}
	Text& Text::operator=(const Text& obj)
	{
		if (this != &obj)
		{
			delete[]line;
			line = nullptr;
			n = 0;
			n = obj.n;
			if (n != 0)
			{
				for (int i = 0; i < n; i++)
				{
					line[i] = obj.line[i];
				}
			}
		}
		return *this;
	}
	Text::Text(Text&& obj)
	{
		*this = std::move(obj);
	}
	Text& Text::operator=(Text&& obj)
	{
		if (this != &obj)
		{
			delete[]line;
			line = obj.line;
			n = obj.n;
			obj.line = nullptr;
			obj.n = 0;
		}
	}

	Text::~Text()
	{
		delete[]line;
	}
	size_t Text::size() const
	{
		return this->n;
	}
}