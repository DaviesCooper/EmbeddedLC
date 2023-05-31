#ifndef STACK_H
#define STACK_H

struct AbstractState;

template <typename T>
class Stack
{
public:
	/**
	 * @brief The current pointer to the array of pointers containing the
	 * references to the items.
	 */
	T *storage_;

	/**
	 * @brief Construct a new Stack object
	 */
	Stack();

	/**
	 * @brief Destroy the Stack object, and the memory allocation of the storage.
	 */
	~Stack();

	/**
	 * @brief Pushes an item to the stack.
	 *
	 * @param item The item to push to the stack.
	 */
	void push(T item);

	/**
	 * @brief Pops the top-most item from the stack;
	 *
	 * @return T The top-most item returned from the stack.
	 */
	T pop();

	/**
	 * @brief Peeks at the top of the stack;
	 *
	 * @return T The top-most item of the stack.
	 */
	T peek();

	/**
	 * @brief The current number if items in the stack.
	 *
	 * @return int
	 */
	int size();

private:
	/**
	 * @brief Resize the array of pointers to allocate more space for the new memory.
	 *
	 * @param capacity The new capacity of items to store.
	 */
	void resize(int capacity);

	/**
	 * @brief The current capacity of the stack
	 */
	int capacity_;

	/**
	 * @brief The current size of the stack.
	 */
	int count;
};

#endif