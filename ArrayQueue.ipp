/**Partially authored by: Chris Dieter
* As I am still a little fuzzy on circular arrays, many
* parts of my add and remove functions depend heavily on
* the algorithms in our class book, Open Data Structures, 
* in the part of ArrayQueues. Help for the writing the exception
* is credited to Dr. Brinkman, as well as the modulo equations used
* for the for loops.
*/


//You will need this so you can make a string to throw in
// remove
#include <string>
#include <array>

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
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
	front = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	//clean up the memory
	delete[] backingArray;
	backingArray = 0;
	front = 0;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){

	if(numItems+1 > backingArraySize){
		grow();
	}
	
	backingArray[(front+numItems) % backingArraySize] = toAdd;
	numItems++;	
}

template <class T>
T ArrayQueue<T>::remove(){
	
	if(numItems < 1){
		throw std::string("Queue is already empty, cannot remove from zero");
	}
	T retVal = backingArray[front];
	front = (front + 1) % backingArraySize;
	numItems--;
	if(backingArraySize >= 3 * numItems){
		grow();
	}
	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	
	if(numItems==backingArraySize){
		int doubleSize = 2 * backingArraySize;
		T* myNewArray = new T[doubleSize];

		for(unsigned int i = 0; i < numItems; i++){
			myNewArray[i] = backingArray[(front + i) % backingArraySize];
		}
		backingArraySize = doubleSize;
		front = 0;
		delete[] backingArray;
		backingArray = myNewArray;
		
	}
}
