
// Sam Hausfeld 9.18.2014
// CSE274 Data Structures and Abstraction
// Lab 03 : QueueArray

// Managed to get the greater majority of the code by myself after thoroughly reading the chapter, but I'm afraid the book did a little bit too much
// of the thinking for me.  When I did run into roadblocks, I eventually got through them through trial/error/perseverance.  One thing in particular
// that I had trouble with in the add() function was the call to grow().  To me, it makes sense to call grow() when numItems > backing ArraySize, but
// the code will only run when I use == or >=.  I learned this by looking at some code from my peers, namely Kyle Richardson's. 
// One thing's for sure, the reading really really helped with this assignment.

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
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (numItems >= backingArraySize) grow();		// Thanks Kyle!
	backingArray[(front+numItems)%backingArraySize] = toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	if (numItems == 0) throw std::string("Removing from an empty queue? Impossible.");
	T outcast = backingArray[front%backingArraySize];
	front++;
	numItems--;
	// if(backingArraySize >= 3*numItems) grow();
	return outcast;
}
	

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
 return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* biggerArray = new T[2*backingArraySize];
	for (unsigned int i = 0; i < numItems; i++)
		biggerArray[i] = backingArray[(front+i)%backingArraySize];
	backingArraySize *= 2;
	front = 0;
	delete[] backingArray;
	backingArray = biggerArray;
}
