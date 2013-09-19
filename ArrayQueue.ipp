//You will need this so you can make a string to throw in
// remove
#include <string>

int n;
int numItems;

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
	front = 0;
	n=0;
	numItems=0;
	backingArraySize=START_SIZE;
	backingArray = new T[START_SIZE];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if(getNumItems() == backingArraySize)
		grow();
	backingArray[n]=toAdd;
	numItems++;
	n=(n+1)%backingArraySize;
}

template <class T>
T ArrayQueue<T>::remove(){
	if(numItems == 0)
		throw (std::string)"There are no elements to remove";
	else{
		T result = backingArray[front];
		front=(front+1)%backingArraySize;
		numItems--;
		return result;
	}
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* newArray = new T[backingArraySize*2];
	for(unsigned int i = 0; i<backingArraySize; i++){
		newArray[i]=backingArray[(front+i)%backingArraySize];
	}
	n=backingArraySize;
	front = 0;
	delete[] backingArray;
	backingArray = newArray;
	backingArraySize=backingArraySize*2;
}
