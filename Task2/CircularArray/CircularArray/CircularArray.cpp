#include "CircularArray.h"
#include <iostream> 
#include <iomanip>


/*template<class T>
CircularArray<T>::CircularArray(int size)
{
	capacity = 10;
	items = new T[capacity];
	head = 0;
	tail = capacity - 1;
	count = 0;
	for (int i = 0; i < capacity; i++)
	{
		items[i] = NULL;
	}

}*/

/*template<class T>
CircularArray<T>::~CircularArray()
{
	delete items;
	//clean();
}*/

template<class T>
void CircularArray<T>::Add(T item)
{
	if (count < capacity)
	{
		count++;
	}
}

///Removes the item at the given index according to current rotation
template<class T>
void CircularArray<T>::RemoveAt(int index)
{
	//TODO: Remove item-> NULL
}

/// Rotates the circular array by the specified value
/*template<class T>
void CircularArray<T>::Rotate(int numRotaion)
{
	int moveHeadBy = numRotaion % capacity;
	if (head - moveHeadBy <= 0)
	{ 
		head -= moveHeadBy;
	}
	else
	{
		head = head + (capacity - moveHeadBy);
	}

	if (head == 0)
	{
		tail = capacity - 1;
	}
	else
	{
		tail = head - 1;
	}
}*/

///Functions retuns the index of the first occurence of the searched item, otherwise returns 0
template<class T>
int CircularArray<T>::Contains(T item) const
{
	for (int i = 0; i < capacity; i++)
	{
		if (items[i] == item)
		{
			return i;
		}
	}
	return -1;
}

///Function returns count of non-null items within the circular array 
template<class T>
int CircularArray<T>::Count() const
{
	return count;
}

/// Returns how many items the circular array can contain 
/*template<class T>
int CircularArray<T>::GetSize() const
{
	return capacity;
}*/

/// returns the value of the indexed item according to current rotation 
/*template<class T>
T & CircularArray<T>::operator[](int index)
{
	int rotatedIndex = (index + head) % capacity;
	return items[rotatedIndex];
}*/
