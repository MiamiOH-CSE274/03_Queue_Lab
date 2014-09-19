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
ArrayQueue<T>::~ArrayQueue() { // clean up after yourself
	delete[] backingArray;
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (numItems > backingArray.backingArraySize) grow();
	backingArray[(front+numItems)%backingArray.backingArraySize] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	T outcast = backingArray[front];
	front = (front+1)%backingArray.backingArraySize;
	numItems--;
	if(backingArray.backingArraySize >= 3*numItems) grow();
	return outcast;
}
	

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
 return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	biggerArray = new T[2*numItems];
	for (int i = 0; i < numItems; i++)
		biggerArray[i] = backingArray[(front+i)%backingArray.backingArraySize];
	backingArray = biggerArray;
	front = 0;
}
