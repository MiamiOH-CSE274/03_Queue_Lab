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
	backingArray = new T[START_SIZE];
	front = backingArray[0];
	numItems = 0;
	backingArraySize = START_SIZE;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
	delete front;
	delete numItems;
	delete backingArraySize;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (numItems == backingArraySize) {
		grow();
	}
	backingArray[(front + numItems) % backingArraySize] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	if (numItems == 0) {
		throw (std::string) "Error: Queue is empty, nothing to remove!";
	}
	T removedValue = backingArray[front];
	front = (front + 1) % backingArraySize;
	numItems--;
	return removedValue;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* newBackingArray = new T[2 * backingArraySize];
	if (newBackingArray == NULL) {
		throw (std::string) "Error: Cannot complete add operation.";
	}
	for (int i = 0; i < numItems; i++) {
		newBackingArray[i] = backingArray[(front + i) % backingArraySize];
	}
	backingArray = newBackingArray;
	front = 0;
	backingArraySize = backingArraySize * 2;
	delete[] backingArray;
}
