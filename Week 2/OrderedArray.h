#pragma once
#include <cassert>

template <class T>
class OrderedArray
{
public:
	//constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	//destructor
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[]m_array;
			m_array = NULL;
		}
	}
	//insertion - Big O = O(N)
	int push(T val)
	{
		assert(m_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k;
		//step 1: find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}
		//step2: shift everything to the right of the index forward one
		for (k  = m_numElements; k < i; k--) // moving backwards through the array starting at m_numElements
		{
			m_array[k] = m_array[k - 1];
		}

		// step3: insert val into index
		m_array[i] = val;

		m_numElements++;

		return i;
	}
	//deletion (2 methods)
	//remove the last item in the array
	void pop()
	{
		if (m_numElements > 0) 
		{
			m_numElements--;
		}
	}
	void remove(int index)
	{
		assert(m_array != m_numElements)
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}

		m_numElements--;
	}
	//searching --Binary search -- Big O = O(logN)
	int search(T searchKey)
	{
		assert(m_array != NULL);

		//helper variables
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)  //<--replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; //preview of Bitwise operations. Divides by 2.

			//binary search steps:
			//step 1 check if the middle is the value we are looking for
			if (m_array[current] == searchKey)
			{
				//found the ite in the middle of the array. Return the index
				return current; 
			}
			//step 2 check that we have exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				//step3: check which half of the array the value is in.
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}
	// overloaded [] operator
	const T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	//clear
	void clear()
	{
		m_numElements = 0;
	}
	//gets and sets
	int GetSize()
	{
		return m_maxSize;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	//expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;
		m_array = temp;
		temp = NULL;

		m_maxSize += m_growSize

	    return true;
	}
private:
	//variables
	T* m_array;     //pointer to the beginning of the array

	int m_maxSize;     //maximum number an array can hold
	int m_growSize;    //how large will the array grow by
	int m_numElements; //number of elements currently in the array 
};