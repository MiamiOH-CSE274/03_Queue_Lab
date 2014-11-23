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
	numItems =0;
	front=0;
	backingArray=new T[START_SIZE];
	backingArraySize= START_SIZE;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	//clean up
	delete[] backingArray;
	backingArray= NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	//check to see if need more space
	if(backingArraySize<=numItems)
	{ grow(); }
	backingArray[(front+numItems)%backingArraySize]=toAdd;
	numItems++;
}

template <class T>
T ArrayQueue<T>::remove(){
	
	if(numItems<1 || backingArraySize==0)
	{
		throw std::string("Queue is already empty, attempted to remove.");
	 }

	T retVal = backingArray[front];
	front = (front+1)%backingArraySize;
	numItems--;

	 return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	//call this when you need more space (double size of array)
	//front + numItems is first available space

	//making array twice as long
	unsigned int doubleSize = backingArraySize*2;
	T* myNewArray = new T[doubleSize];	

	//putting old elements into new array
	for(unsigned int i=0; i<backingArraySize; i++)
	{
		myNewArray[i]= backingArray[(front+i)%backingArraySize];
	}
	backingArraySize=doubleSize;
	front=0;
	delete[] backingArray;
	backingArray=myNewArray;
}
