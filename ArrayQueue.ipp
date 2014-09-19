//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Told not to do, but I'm declaring global variables used in keeping
//track of stuff in the array.  Unsure of how without editing the
//files we were told not to change
unsigned int front;
unsigned int backingArraySize;

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(){
	numItems = 0;
    front = 0;
    backingArraySize = START_SIZE;

	//Creates a new variable of type numItems and stores the address
	//in backingArray
	backingArray = new T[backingArraySize];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	//cleanup after yourself
	delete[] backingArray;
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	numItems++;
    
    if(numItems > backingArraySize) {
        grow();
    }

	backingArray[(front + numItems)%backingArraySize] = toAdd;
}

template <class T>
T ArrayQueue<T>::remove(){
	if(numItems < 1) {
		//Bad news
		throw std::string("Queue is already empty, attempted to remove.");
	}
	
    T retVal = backingArray[front];
    front = (front + 1)%backingArraySize;

	numItems--;

	/*
    //Make a new array, put in the new items
	T* myNewArray = new T[numItems];

	//Saves the value that we will be returning
	T retVal = backingArray[0];

	//Copy over the contents of the old array, starting from position 1
	for(unsigned int i=0; i<numItems; i++) {
		myNewArray[i] = backingArray[i+1];
	}

	delete[] backingArray;
	backingArray = myNewArray;
    */

	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	//numItems was declared in "ArrayQueue.h"
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
    unsigned int newSize = backingArray*2;
    
    T* myNewArray = new T[newSize];
    
    for(int i=0; i<backingArraySize; i++) {
        myNewArray[i] = (backingArray[front+i]%backingArraySize);
    }
    
    backingArraySize = newSize;
    delete[] backingArray;
    backingArray = myNewArray;
    front = 0;
}
