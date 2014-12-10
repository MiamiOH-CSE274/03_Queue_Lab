//DO NOT CHANGE THIS FILE
//Author: Bo Brinkman
//Date: 2013/06/26
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue < T > {
public:
	//See Queue.h for documentation of these methods

	//This class MUST use the "circular" array concept,
	// so if I do add, remove, add, remove, add, remove ...
	// even if I do it 10000000 times, your array should not grow.
	// The array should never grow unless numItems == backingArraySize
	virtual  void add(T toAdd);
	virtual T remove();
	virtual unsigned long getNumItems();

	//Initialize all private member variables.
	// You initial backing array should be length 10. Allocate it
	// using "new"
	ArrayQueue();
	//Delete any dynamically allocated memory. If you are deleting
	// an array, be sure to use "delete[]" instead of "delete"
	virtual ~ArrayQueue();

private:
	//If the backing array is too small, you may call this function.
	// It should create a new backing array twice as big as the old one,
	// and copy over the old data into the new array. It should finish
	// off by calling delete[] on the old backing array
	void grow();

	//Pointer to the array that we are using to store the queue
	T* backingArray;

	//The index in T where the front of the queue is.
	unsigned long front;
	//Number of items in the queue
	unsigned long numItems;

	//Number of spaces in the array pointed to by backingArray
	unsigned long backingArraySize;
};

/***
 *
 * Normally when we write C++, we put declarations in the .h file,
 * and code in a matching .cpp file. Unfortunately, when working with
 * templates, this doesn't work very well. If you tried to compile
 * ArrayQueue.ipp, it wouldn't know what type "T" is, and so couldn't
 * succeed. So when we use template classes, we have to include the
 * source code for the whole class.
 *
 **/


//You will need this so you can make a string to throw in
// remove
#include <string>

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
ArrayQueue<T>::ArrayQueue(){
	numItems = 0;
	front = 0;
	backingArraySize = START_SIZE;
	backingArray = new T[backingArraySize];
}


template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	//grow array if full
	if (numItems == backingArraySize)
	{
		grow();
	}

	//else add toAdd to the first available spot, modulo code from lecture
	backingArray[((front + numItems) % backingArraySize)] = toAdd;
	numItems++;
}


template <class T>
T ArrayQueue<T>::remove(){
	if (numItems < 1)
	{
		//bad news
		throw std::string("Queue is already empty, attempted to remove.");
	}

	T retVal = backingArray[front];
	front = (front + 1) % backingArraySize;
	numItems--;

	return retVal;

}


template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}


template <class T>
void ArrayQueue<T>::grow(){

	T* biggerArray = new T[backingArraySize * 2];

	//copy over old values
	for (unsigned int i = 0; i < numItems; i++){
		biggerArray[i] = backingArray[(i + front) % backingArraySize];
	}

	front = 0;
	delete[] backingArray;
	backingArray = biggerArray;
	backingArraySize = (backingArraySize * 2);


}
