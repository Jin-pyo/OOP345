#include<iostream>
using namespace std;

int main()
{
	int i = 0;

	for (i; i < 5; i++)
	{
		cout << i << endl;
	}

	cout << "-------------" << endl;
	cout << i << endl;
	cout << "-------------" << endl;
	i = 0;

	for (i; i < 5; ++i)
	{
		cout << i << endl;
	}

	cout << "-------------" << endl;
	cout << i;
}