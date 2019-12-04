#include "SpellChecker.h"
#include<iostream>
#include<fstream>

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		else
		{
			for (int i= 0; i < 5; i++)
			{
				file >> m_badWords[i];
				file >> m_goodWords[i];
			}
		}
	}
	void SpellChecker::operator()(std::string& text) const
	{
		for (auto i=0u;i<sizeof(m_badWords)/sizeof(m_badWords[0]);i++)
		{
			size_t find = text.find(m_badWords[i]);
			while (find != std::string::npos)
			{
				text.replace(find, m_badWords[i].size(), m_goodWords[i]);
				find = text.find(m_badWords[i]);
			}
		}
	}
}