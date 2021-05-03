#include "LaggedFibonacci.h"


int main()
{


	for (size_t i = 0; i < 10; i++)
	{
		cout << Random() << endl;

	}

	cout <<endl<< "1 parameter " << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << Random(100) << endl;

	}

	cout <<endl<< "2 parameters " << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << Random(50,100)<< endl;

	}

}
