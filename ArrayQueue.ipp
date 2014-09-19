//Kyle Busdieker
//Prof. Brinkman
//CSE 274
//Date: September 18, 2014
//This code was created Bo Brinkman and modified by Kyle Busdieker

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
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
	front = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	numItems++;

	if(numItems == backingArraySize){
		ArrayQueue<T>().grow();
	}

	backingArray[(front+numItems)%backingArraySize] = toAdd;

	//the old slow way
	//Make a new array, put in the new item
	//T* myNewArray = new T[numItems];
	//myNewArray[numItems-1] = toAdd;

	//Copy over the old items
	//for(unsigned int i=0; i<numItems-1; i++){
	//	myNewArray[i] = backingArray[i];
	//}
	//
	//This is delete[], not delete
	//delete[] backingArray;
	//backingArray = myNewArray;

}

template <class T>
T ArrayQueue<T>::remove(){
	
	if(numItems < 1){
		//bad stuff!
		throw std::string("Queue is already empty!");
	}
	front = (front+1)%backingArraySize;
	numItems--;
	if(numItems == 0)
		front = 0;



		/*Old Way
		//Make a new array, put in the new item
		T* myNewArray = new T[numItems];

		T retVal = backingArray[0];

		Copy over the old items
		for(unsigned int i=0; i<numItems; i++){
			myNewArray[i] = backingArray[i+1];
		}

		delete[] backingArray;
		backingArray = myNewArray;

		return retVal;*/
	
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
//Tip: double the array length when growing
void ArrayQueue<T>::grow(){
	T* grownArray = new T[(backingArraySize * 2)];
	backingArraySize = (backingArraySize * 2);

	for(unsigned int i=0; i<numItems; i++)
		grownArray[i] = backingArray[(front+i)%backingArraySize];

	delete[] backingArray;
	backingArray = grownArray;
	front = 0;

}
