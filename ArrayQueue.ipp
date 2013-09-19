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
	backingArraySize = START_SIZE;
	front = 0;
	backingArray = new T[backingArraySize];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	backingArray[(front+numItems)%backingArraySize] = toAdd;
	numItems++;

	if(numItems >= backingArraySize) ArrayQueue<T>::grow();
}

template <class T>
T ArrayQueue<T>::remove(){
  if(numItems <= 0) throw (std::string)"You have no items to remove!";

  numItems--;
  int tempInteger = front;
  front = (++front)%backingArraySize;

  return backingArray[tempInteger];
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	int i = 0;
	T* tempArray = new T[backingArraySize*2];
	if(tempArray == NULL) throw (std::string)"Not enough Memory for your array";
	while(i < numItems){
		tempArray[front + i] = backingArray[(front+ i) % backingArraySize];
		i++;
	}
	backingArraySize*=2;
	delete backingArray;
	backingArray = tempArray;
}
