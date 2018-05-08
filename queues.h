// QUEUES
// This program contains several implementations of queues:
// 1) Linked List
// 2) Vector
// 3) Array
// 
// NEW PATTERNS/TECHNIQUES IMPLEMENTED
// 1) Memory is managed manually rather than by smart ptr
// 2) Delete[] is used for allocated arrays
// 3) Dangling pointers are made null after deletion
// 
// Author: Chris Lee
// Date: May 8th, 2018
// Last Edited: May 8th, 2018

#ifndef __MY_QUEUE__
#define __MY_QUEUE__

#include <stdexcept>
#include <vector> 

template<typename T>
class LinkedListQueue
{
private:
	class Node
	{
		Node(const T& value): m_data(value), m_next(nullptr), m_previous(nullptr)
		{
		}
		T m_data;
		Node* m_next;
		Node* m_previous;
		friend LinkedListQueue;
	};
public:
	LinkedListQueue(): m_front(nullptr)
	{
	}
	~LinkedListQueue()
	{
		if (!m_front)
		{
			return;
		}
		else
		{
			Node* toDelete = getBackPtr();
			while (toDelete)
			{
				delete toDelete;
				toDelete = getBackPtr();
			}
		}
	}

	T& front() const
	{
		if (m_front)
		{
			return m_front->m_data;
		}
		else
		{
			throw std::invalid_argument( "Empty queue" );
		}
	}

	T& back() const
	{
		if (m_front)
		{
			Node* current = m_front;
			while (current->m_next)
			{
				current = current->m_next;
			}
			return current->m_data;
		}
		else
		{
			throw std::invalid_argument( "Empty queue" );
		}
	}

	bool push(const T& value)
	{
		if (!m_front)
		{
			m_front = new Node(value);
			return true;
		}
		else
		{
			Node* current = m_front;
			while (current->m_next)
			{
				current = current->m_next;
			}
			current->m_next = new Node(value);
			return true;
		}
	}

	bool pop()
	{
		if (!m_front)
		{
			return false;
		}
		if (!m_front->m_next)
		{
			delete m_front;
			m_front = nullptr;
		}
		else
		{
			Node* temp = m_front;
			m_front = m_front->m_next;
			delete temp;
		}

		return true;
	}

private:
	Node* m_front;
	Node* getBackPtr()
	{
		if (!m_front)
		{
			return nullptr;
		}
		if (!m_front->m_next)
		{
			Node* backPtr = m_front;
			m_front = nullptr;
			return backPtr;
		}

		Node* backPtr = m_front;
		Node* secondToLast = backPtr;
		while (backPtr->m_next)
		{
			secondToLast = backPtr;
			backPtr = backPtr->m_next;
		}
		secondToLast->m_next = nullptr; // this will be a dangling pointer after deletion so it needs to be reset
		return backPtr;
	}
};

// A better version would be to implement the array strategy (redirecting if we overflow) and only reallocating
// if we push more elements than we can handle
template<typename T>
class VectorQueue
{
public:
	VectorQueue(): m_front(0), m_back(0)
	{
	}
	~VectorQueue()
	{
		// memory handled by std::vector
	}

	const T& back() const
	{
		if (m_front == m_back)
		{
			throw std::invalid_argument( "Empty queue" );
		}
		else
		{
			return (m_data[m_back-1]);
		}
	}

	const T& front() const
	{
		if (m_front == m_back)
		{
			throw std::invalid_argument( "Empty queue" );
		}
		else
		{
			return (m_data[m_front]);
		}
	}

	bool push(const T& value)
	{
		m_data.push_back(value);
		++m_back;
		return true; 
	}

	bool pop()
	{
		if (m_front == m_back)
		{
			return false;
		}
		else
		{
			++m_front;
			return true;
		}
		return false; 
	}

private:
	std::vector<T> m_data;
	int m_front;
	int m_back;
};

template<typename T>
class ArrayQueue
{
public:
	ArrayQueue(): m_data(new T[5]), m_size(5), m_front(0), m_back(0), m_numVals(0)
	{
	}
	~ArrayQueue()
	{
		delete[] m_data;
	}

	T& back() const
	{
		if (m_numVals == 0)
		{
			throw std::invalid_argument( "Empty queue" );
		}
		else
		{
			return m_data[m_back - 1];
		}
	}

	T& front() const
	{
		if (m_numVals == 0)
		{
			throw std::invalid_argument( "Empty queue" );
		}
		else
		{
			return m_data[m_front];
		}
	}

	bool push(const T& value)
	{
		if (m_size == m_numVals)
		{
			return false;
		}
		else
		{
			m_data[m_back] = value;
			++m_back;
			++m_numVals;
			handleOverflow(m_back);
			return true;
		}
	}

	bool pop()
	{
		if (m_numVals == 0)
		{
			return false; 
		}
		else
		{
			++m_front;
			--m_numVals;
			handleOverflow(m_front);
			return true;
		}
		return false; 
	}

private:
	T* m_data;
	int m_size;
	int m_front;
	int m_back;
	int m_numVals;

	// bring us back to the beginning of the array if we go past m_data.length()
	void handleOverflow(int& ind)
	{
		if (ind >= m_size)
		{
			ind = ind % m_size;
		}
	}
};
#endif