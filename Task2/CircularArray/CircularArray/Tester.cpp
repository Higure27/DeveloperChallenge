#include "CircularArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	CircularArray<int> myTestIntCA(5);
	CircularArray<char> myTestCharCA(6);
	int size = myTestIntCA.GetSize();

	myTestIntCA[0] = 1;
	myTestIntCA[1] = 2;
	myTestCharCA[0] = 'a';
	myTestCharCA[1] = 'b';
	cout << "Int CA count:" <<myTestIntCA.Count() << endl; 
	cout << "Char CA count:" << myTestCharCA.Count() << endl;
	myTestIntCA[2] = 3;
	myTestIntCA[3] = 4;
	myTestIntCA[4] = 5;
	

	myTestCharCA[2] = 'c';
	myTestCharCA[3] = 'd';
	myTestCharCA[4] = 'e';
	myTestCharCA[5] = 'f';

	cout << "Int CA count:" << myTestIntCA.Count() << endl;
	cout << "Char CA count:" << myTestCharCA.Count() << endl;

	cout << "Int CA contains: ";
	int i = 0;
	while (i < myTestIntCA.GetSize())
	{
		cout << myTestIntCA[i] << ", ";
		i++;
	}
	cout << endl;

	cout << "Char CA contains: ";
	i = 0;
	while (i < myTestCharCA.GetSize())
	{
		cout << myTestCharCA[i] << ", ";
		i++;
	}

	cout << endl<< endl;

//---------------Test Rotation--------
	

	cout << "Rotation of 1:"<< endl;
	myTestIntCA.Rotate(1);
	myTestCharCA.Rotate(1);

	cout << "Int CA contains: ";
	i = 0;
	while (i < myTestIntCA.GetSize())
	{
		cout << myTestIntCA[i]<< ", ";
		i++;
	}

	cout << endl;

	cout << "Char CA contains: ";
	i = 0;
	while (i < myTestCharCA.GetSize())
	{
		cout << myTestCharCA[i] << ", ";
		i++;
	}

	cout << endl;

	cout << "Rotation of 4:" << endl;
	myTestIntCA.Rotate(4);
	myTestCharCA.Rotate(4);

	cout << "Int CA contains: ";
	i = 0;
	while (i < myTestIntCA.GetSize())
	{
		cout << myTestIntCA[i] << ", ";
		i++;
	}

	cout << endl;

	cout << "Char CA contains: ";
	i = 0;
	while (i < myTestCharCA.GetSize())
	{
		cout << myTestCharCA[i] << ", ";
		i++;
	}

	cout << endl;


	cout << "Full Rotation :" << endl;
	myTestIntCA.Rotate(5);
	myTestCharCA.Rotate(6);

	cout << "Int CA contains: ";
	i = 0;
	while (i < myTestIntCA.GetSize())
	{
		cout << myTestIntCA[i] << ", ";
		i++;
	}

	cout << endl;

	cout << "Char CA contains: ";
	i = 0;
	while (i < myTestCharCA.GetSize())
	{
		cout << myTestCharCA[i] << ", ";
		i++;
	}

	cout << endl;

	cout << "Testing range-based for loop :" << endl;
	cout << "Int CA: ";
	for (auto x : myTestIntCA)
	{
		cout << x << ", ";
	}
	
	cout << endl;

	cout << "Char CA: ";
	for (auto x : myTestCharCA)
	{
		cout << x << ", ";
	}

	cout << endl;

	cout << "Testing Contains and removal :" << endl;

	cout << "Char CA contains 'd' at index:" << myTestCharCA.Contains('d') << endl; 
	
	cout << "removing d(1 true/0 false):" << myTestCharCA.RemoveAt(myTestCharCA.Contains('d'))<< endl;

	cout << "Char CA: ";
	for (auto x : myTestCharCA)
	{
		cout << x << ", ";
	}


	cout << "Char CA contains 'g' at index(- 1 means item was not found):" << myTestCharCA.Contains('g') << endl;

	cout << "removing d(1 true/0 false):" << myTestCharCA.RemoveAt(myTestCharCA.Contains('g')) << endl;

	cout << "Char CA: ";
	for (auto x : myTestCharCA)
	{
		cout << x << ", ";
	}

	

	return 0;
}
