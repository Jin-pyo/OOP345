#include<iostream>
#include<vector>
#include<string>


int sum(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multiple(int a, int b)
{
	return a * b;
}

int main()
{
	int a=2, b=6;
	int(*fncptr[3])(int, int) = { sum,sub,multiple };
	
	for (int i = 0; i < sizeof(fncptr) / sizeof(fncptr[0]); i++)
	{
		std::cout << fncptr[i](a, b) << std::endl;
	}
	return 0;
}