//You will need this so you can make a string to throw in
// remove
#include <string>
#include <iostream>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue()
{
	backingArraySize = START_SIZE;
	front = 0;
	numItems = 0;
	backingArray = new T[backingArraySize];
}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd)
{
	if (numItems >= backingArraySize) {
		grow();
	}

	backingArray[(front + numItems) % backingArraySize] = toAdd;

	numItems++;
}

template <class T>
T ArrayQueue<T>::remove()
{
	if (numItems == 0) {
		throw std::string("error: no more items to remove");
	}

	T ret = backingArray[front];
	front = (front + 1) % backingArraySize;
	numItems--;

	return ret;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems()
{
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow()
{
	unsigned int new_size = backingArraySize * 2;

	if (new_size < backingArraySize) {
		// we are storing too many elements in our array and cant store the size
		// with an unsigned int.  will most likely not happen, but its safe to check

		throw std::string("error: out of memory, no new items can be added.");
	}

	T *temp_array = new T[new_size];

	for (unsigned int i = 0; i < backingArraySize; i++) {
		temp_array[i] = backingArray[(front + i) % backingArraySize];
	}

	delete[] backingArray;
	backingArray = temp_array;
	backingArraySize = new_size;
	front = 0;
}
