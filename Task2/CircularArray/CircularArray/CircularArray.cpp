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

///Removes the item at the given index according to current rotation
/*template<class T>
bool CircularArray<T>::RemoveAt(int index)
{
}*/




///Functions retuns the index of the first occurence of the searched item, otherwise returns 0
/*template<class T>
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
}*/

///Function returns count of non-null items within the circular array 
/*template<class T>
int CircularArray<T>::Count() const
{
	return count;
}*/

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
