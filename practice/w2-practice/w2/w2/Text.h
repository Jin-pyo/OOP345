#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<string>
namespace sdds
{
	class Text
	{
		std::string* line;
		size_t n;

	public:
		Text();
		Text(const std::string& name);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;


	};
}



#endif // !TEXT_H


