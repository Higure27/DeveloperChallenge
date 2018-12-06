#pragma once
#include <cstddef>

template <class T>
class CircularArray
{
private:

	T *items;
	int capacity;
	int count;
	int head;
	int tail;
	T *begin_;
	T *end_;

public:
	

	CircularArray(int size)
	{
		capacity = size;
		items = new T[capacity];
		head = 0;
		tail = capacity - 1;
		count = 0;
		for (int i = 0; i < capacity; i++)
		{
			items[i] = NULL;
		}
		begin_ = &items[head];
		end_ = &items[tail];

	}
	~CircularArray()
	{
		delete items;
	}

	
	T*  begin() const noexcept { return &items[head]; }//begin_}
	T*  end() const noexcept { return &items[tail]; }//end_ }

	void Add(T item);//if full rotate and overwrite value at spot [0]
	void RemoveAt(int location);
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
	int Contains(T item) const;
	int Count() const;
	
	int GetSize() const
	{
		return capacity;
	}
	
	T& operator[](int index)
	{
		int rotatedIndex = (index + head) % capacity;
		return items[rotatedIndex];
	}



};

