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
	//THIS IS WHAT I NEEDED TO INITIALIZE!
	numItems = 0;

	//Creates a new variable of type numItems and stores the address
	//in backingArray
	backingArray = new T[numItems];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	numItems++;

	//Make a new array, put in the new items
	T* myNewArray = new T[numItems];
	myNewArray[numItems-1] = toAdd;

	//Copy over all the old items
	for(unsigned int i=0; i<numItems-1; i++) {
		myNewArray[i] = backingArray[i];
	}

	//This is delete[], not delete
	//is a dangling pointer, points to same stuff, but it isn't allocated anymore
	delete[] backingArray;

	//Assign backingArray the new array
	backingArray = myNewArray;
}	

template <class T>
T ArrayQueue<T>::remove(){
	T aFakeItem;
	return aFakeItem;  
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	//numItems was declared in "ArrayQueue.h"
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){

}
