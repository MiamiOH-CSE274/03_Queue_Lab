//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constahttps://github.com/LakersAllTheWay/03_Queue_Lab.gitnstead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(){
	backingArraySize = START_SIZE;
	backingArray = new T [backingArraySize];
	numItems = 0;
	front = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete [] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (numItems == backingArraySize) {
			grow();
	}
		backingArray[(front + numItems)%backingArraySize] = toAdd;
		numItems++;	 
}

template <class T>
T ArrayQueue<T>::remove(){
	T temp = backingArray[front];
	if (numItems == 0) {
		throw std::string("No items in queue to remove!"); 
	}
  
  front = (front + 1) % backingArraySize;
  numItems--;
  return temp;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* newBackingArray = new T[backingArraySize*2];
	if(newBackingArray == NULL) {
		throw std::string("There was an error in execution");
	}
	for (unsigned long i = 0; i < backingArraySize; i++) {
		newBackingArray[front + i] = backingArray[(front + i)%backingArraySize];
	}
	backingArraySize = backingArraySize * 2;
	delete [] backingArray;
	backingArray = newBackingArray;
}
