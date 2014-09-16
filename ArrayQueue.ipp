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
	backingArray = new T[START_SIZE];
	backingArraySize = START_SIZE;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	
	while(numItems > backingArraySize){
	grow();
	}

	backingArray[(front+numItems)%backingArraySize] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	numItems--;
	front++;
	return backingArray[front-1];
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
T* myNewArray = new T[2*backingArraySize];
for(unsigned int i=0;i<numItems;i++){
	myNewArray[i] = backingArray[(front+i)%backingArraySize];
}
front = 0;
}
