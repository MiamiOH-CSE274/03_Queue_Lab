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
	backingArray = new T[numItems];
	
}

// Destructor
template <class T>
ArrayQueue<T>::~ArrayQueue() {

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	// Increase the number of items in the array - you are adding one
	numItems++;
	
	// need to create a new array
	T* myNewArray = new T[numItems];
	
	// put in the new item: numItems-1 is the length of the new array
	myNewArray[numItems - 1] = toAdd;
	
	// Copy over all the old items
	for(unsigned int i = 0; i < numItems-1; i++){
		myNewArray[i] = backingArray[i];
	}

	// Need to make backingArray point to the new array
	// also need to delete the current array that backingArray is pointing to
	// this is delete[], not delete
	delete[] backingArray;
	// At this point backingArray still holds the address - just no longer an allocated object
	// "dangling pointer" - points to somewhere in the Heap

	// update backingArray (pointer)
	backingArray = myNewArray;
}

// Remove from front of array
template <class T>
T ArrayQueue<T>::remove(){
	// subtract one from the length
	numItems--;

	// Create a new array to store the values
	T* newArray = new T[numItems];

	// save the removed value before it disappears!
	T retVal = backingArray[0];

	for(unsigned int i = 0; i < numItems; i++){
		newArray[i] = backingArray[i+1];
	}

	// delete the old array
	delete[] backingArray;
	backingArray = newArray;

	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){

}
