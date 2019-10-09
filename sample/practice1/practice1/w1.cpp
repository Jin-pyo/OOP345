// Function Objects
 // function_object.cpp

#include <iostream>

int main()
{
	int a = 5;
	int b = 2;
	
	int result = [&]()->int
	{
		return [&]()->int {return a+b; }();
	}();

	std::cout << result << std::endl;

	return 0;
}