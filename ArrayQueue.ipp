//You will need this so you can make a string to throw in
// remove
#include <string>
#include <iostream>

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
  backingArray = new int[START_SIZE];
  front = 0;
  numItems = 0;
  backingArraySize = START_SIZE;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
  delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd) {
  if (numItems == backingArraySize) {
    grow();
  }
  backingArray[(numItems+front)%backingArraySize]  = toAdd;
  numItems++;
  
  
}

template <class T>
T ArrayQueue<T>::remove(){
	if (numItems == 0 )
		throw std::string("There is not anything in the Queue, please add something to the Queue before you remove anything.");
	else {
		numItems--;
		front++;
		if (front == backingArraySize) {
			front = 0;
			return backingArray[backingArraySize-1];
		} else {
			front = front%backingArraySize;
			return backingArray[front-1];
			}
		}  
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
  return numItems;

}

template <class T>
void ArrayQueue<T>::grow(){
	T* secondArray = new T[backingArraySize*2];
	if (secondArray == NULL) {
	  throw std::string("There is no more room left for the Queue to expand.");
	}
	for (int i = 0; i < (int)numItems; i++) {
	  secondArray[i]=backingArray[(i+front)%backingArraySize];
	}
	front = 0;
	delete[] backingArray;
	backingArray = secondArray;
	backingArraySize = backingArraySize*2;
}
