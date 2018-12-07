#pragma once
#include <cstddef>

template <class T>
class CircularArray
{
private:

	T *items;
	T* rotatedItems; 
	int capacity;
	int count;
	int head;
	int tail;

public:
	
	//To handle generics function written in .h file 
	CircularArray(int size)
	{
		capacity = size;
		items = new T[capacity];
		rotatedItems = new T[capacity];
		head = 0;
		tail = capacity - 1;
		count = 0;
		for (int i = 0; i < capacity; i++)
		{
			items[i] = NULL;
			rotatedItems[i] = NULL;
		}
	}

	~CircularArray()
	{
		delete items;
		delete rotatedItems;
	}

	///used for itereting 
	T*  begin() {
		int rotatedIndex = 0;
		for (int i = 0; i < capacity; i++)
		{
			rotatedIndex = (i + head) % capacity;
			rotatedItems[i] = items[rotatedIndex];
		}
		return &rotatedItems[0];
	}
	T*  end() const noexcept { return &rotatedItems[capacity]; }//end_ }


	//returns false if specified spot contains a NULL
	bool RemoveAt(int index)
	{
		
		int rotatedIndex = (index + head) % capacity;
		if (items[rotatedIndex] != NULL)
		{
			items[rotatedIndex] = NULL;
			return true;
		}
		return false;
	}

	/// Rotates the circular array by the specified value
	void Rotate(int numRotaion)
	{
		int moveHeadBy = numRotaion % capacity;
		if (head - moveHeadBy >= 0)
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
	}
	// Return first occurence of an item, if item not found returns -1
	int Contains(T item) const
	{
		int rotatedIndex = 0;
		for (int i = 0; i < capacity; i++)
		{
			rotatedIndex = (i + head) % capacity;
			if (items[rotatedIndex] == item)
			{
				return rotatedIndex;
			}
		}
		return -1;
	}


	///Function returns count of non-null items within the circular array 
	int Count() 
	{
		count = 0;
		int rotatedIndex = 0;
		for (int i = 0; i < capacity; i++)
		{
			rotatedIndex = (i + head) % capacity;
			if (items[rotatedIndex] != NULL)
			{
				count++;
			}
		}

		return count; 
	}
	
	/// Returns how many items the circular array can contain 
	int GetSize() const
	{
		return capacity;
	}
	
	/// returns the value of the indexed item according to current rotation
	T& operator[](int index)
	{
		int rotatedIndex = (index + head) % capacity;
		return items[rotatedIndex];
	}

};

