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
// Constructor
template <class T>
ArrayQueue<T>::ArrayQueue(){
	numItems = 0;
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
	front = 0;
	
}

// Destructor
template <class T>
ArrayQueue<T>::~ArrayQueue() {
	// Cleanup after yourself
	delete[] backingArray;
	// Reset pointer so it no longer points to anything
	// NULL is defined as zero
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	// Check to see if the array is full
	if(numItems == backingArraySize){
		grow();
	}
	
	// The front plus the number of items in the array 
	// modulo the total array size gives
	// the index of the next available location
	backingArray[(front + numItems)%backingArraySize] = toAdd;
	
	// Increase the number of items in the array - you are adding one
	numItems++;	
}

// Remove from front of array
template <class T>
T ArrayQueue<T>::remove(){
	if(numItems < 1){
		throw std::string("Queue is already empty, attempted to remove.");
	}

	// Record the element that is being removed so it can be returned later
	T removedValue = backingArray[front];

	// Increment the front, making sure it wraps around to the correct location
	// as needed my using modulo
	front = (front + 1)%backingArraySize;

	// subtract one from the length
	numItems--;
	
	// return the value
	return removedValue;
	
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	
}
