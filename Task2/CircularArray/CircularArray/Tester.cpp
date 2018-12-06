#include "CircularArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	CircularArray<int> myTestCA1(5);
	int size = myTestCA1.GetSize();

	myTestCA1[0] = 1;
	myTestCA1[1] = 2;
	myTestCA1[2] = 3;
	myTestCA1[3] = 4;
	myTestCA1[4] = 5;

	cout << myTestCA1[0] << endl;
	cout << myTestCA1[1] << endl;
	cout << myTestCA1[2] << endl;
	cout << myTestCA1[3] << endl;
	cout << myTestCA1[4] << endl;

	int i = 0;
	while (i < myTestCA1.GetSize())
	{
		cout << myTestCA1[i] << ", ";
		i++;
	}
	cout << endl;


	myTestCA1.Rotate(1);

	i = 0;
	while (i < myTestCA1.GetSize())
	{
		cout << myTestCA1[i]<< ", ";
		i++;
	}

	cout << endl;

	myTestCA1.Rotate(1);

	i = 0;
	while (i < myTestCA1.GetSize())
	{
		cout << myTestCA1[i] << ", ";
		i++;
	}
	cout << endl;

	myTestCA1.Rotate(5);

	i = 0;
	while (i < myTestCA1.GetSize())
	{
		cout << myTestCA1[i] << ", ";
		i++;
	}

	cout << endl;

	for (auto x : myTestCA1)
	{
		cout << x << ", ";
		x++;
	}


	return 0;
}
