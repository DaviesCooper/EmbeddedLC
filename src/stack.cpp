#include "stack.h"

template <typename T>
Stack<T>::Stack()
{
	capacity_ = 1;
	storage_ = new T[capacity_];
	count = 0;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] storage_;
}

template <typename T>
void Stack<T>::push(T item)
{

	// Check if we have exceeded our stack size
	if (count == capacity_)
	{
		// If we have, double our capacity
		resize(capacity_ * 2);
	}
	// Add the item to the end of the array
	storage_[count++] = item;
}

template <typename T>
T Stack<T>::pop()
{
	T item = storage_[--count];
	if (count > 0 && count == capacity_ / 4)
	{
		resize(capacity_ / 2);
	}
	return item;
}

template <typename T>
T Stack<T>::peek()
{
	return storage_[count - 1];
}

template <typename T>
int Stack<T>::size()
{
	return count;
}

template <typename T>
void Stack<T>::resize(int capacity)
{
	// Create a new array
	T *temp = new T[capacity];
	// Copy over the items
	for (int i = 0; i < count; ++i)
	{
		temp[i] = storage_[i];
	}
	// Delete the old allocation
	delete[] storage_;
	// Set the reference to the newly created and copied array
	storage_ = temp;
	// Set the capacity to the currently passed in
	capacity_ = capacity;
}