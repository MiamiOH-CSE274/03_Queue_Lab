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
ArrayQueue<T>::~ArrayQueue(){
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	numItems ++;
	// Make a new aray, put in the new item
	T* myNewArray = new T[numItems];
	myNewArray[numItems - 1] = toAdd;

	//Copy over all the old items
	for(unsigned int i = 0; i < numItems - 1; i++){
		myNewArray[i] = backingArray[i];
	}

	delete[] backingArray;

	backingArray = myNewArray;
}

template <class T>
T ArrayQueue<T>::remove(){

	if(numItems == 0){
		throw std::string("error: there are no more items to remove");
	}

	numItems --;

	T* myNewArray = new T[numItems];

	T retVal = backingArray[0];

	for(unsigned int i = 0; i < numItems; i++){
		myNewArray[i] = backingArray[i + 1];
	}

	delete[] backingArray;
	backingArray = myNewArray;

	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	unigned int grow_size = backingArraySize * 2;

	T *new_array = new T[grow_size];

	for(unsigned int i = 0; i < backingArraySize; i++){
		new_array[i] = backingArray[(i + front) % backingArraySize];
	}

	delete[] backingArray;
	backingArray = new_array;
	backingArraySize = grow_size;
	front = 0;
}
