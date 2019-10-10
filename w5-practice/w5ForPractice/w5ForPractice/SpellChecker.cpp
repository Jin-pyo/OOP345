#include "SpellChecker.h"
#include<iostream>
#include<fstream>
#include<string>

namespace sdds
{

	SpellChecker::SpellChecker(const char* filename)
	{
		int start = 0;
		if (filename == '\0')
		{
			throw "Bad file name!";
		}
		else
		{
			std::ifstream file(filename);
			int i = 0;
			while (file)
			{
				file >> this->m_badWords[i];
				file >> this->m_goodWords[i];
				i++;
			}
		}
	}
	void SpellChecker::operator()(std::string& text)const
	{
		for (int i = 0; i < 5; i++)
		{
			if (text.find(this->m_badWords[i]) != std::string::npos)
			{
				size_t pos = text.find(m_badWords[i]);
				size_t size = m_badWords[i].length();
				text.replace(pos, size, m_goodWords[i]);
			}
		}
	}

}