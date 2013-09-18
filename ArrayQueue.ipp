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
//Constructor
ArrayQueue<T>::ArrayQueue(){
	//Declare private Variables
	backingArraySize = START_SIZE;
	backingArray = new T[backingArraySize];
	numItems = 0;
	front = 0;
}

template <class T>
//Destructor
ArrayQueue<T>::~ArrayQueue() {
	//De-allocate used memory
	delete[] backingArray;
}

template <class T>
//Method to add items into queue
void ArrayQueue<T>::add(T toAdd){
	//Check if the queue is full, then resize if needed
	if(numItems == backingArraySize)
		grow();
	backingArray[((front + numItems) % backingArraySize)] = toAdd; 
	numItems++;
}

template <class T>
//Method to remove items from queue
T ArrayQueue<T>::remove(){
	T removed = backingArray[front];
	if(numItems == 0){
		throw std::string("Error");
	}

	front = (front + 1) % backingArraySize;
	numItems--;
	return removed;	
}

template <class T>
//Method to return the number of items in the queue
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
//Method to resize the queue, doubles the size every time the function is called
void ArrayQueue<T>::grow(){
	//Creating a new array double the size of the original
	T* newBackingArray = new T[backingArraySize*2];
	//Check if we are out of memory and throw and exception if so
	if(newBackingArray == NULL)
		throw std::string("Error");
	//Copy the old array's contents to the new array
	for (unsigned long i = 0; i < numItems; i++)
		newBackingArray[front + i] = backingArray[(front+i) % backingArraySize];
	//Double the array size variable
	backingArraySize = backingArraySize*2;
	//De-allocate the old array
	delete[] backingArray;
	//Set the old array's address location to the new array's location
	backingArray = newBackingArray;
}
