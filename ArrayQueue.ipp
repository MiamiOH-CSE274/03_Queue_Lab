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
	//check to see if need more spice
	if(backingArraySize<=numItems)
	{ grow(); }
	else
	{
		backingArray[(front+numItems)%backingArraySize]=toAdd;
		numItems++;

		/*T* myNewArray = new T[numItems];	
		myNewArray[numItems-1]=toAdd;
		//made a new array and put in a new item
		//copy over old items
		for(unsigned int i=0; i<numItems-1; i++)
		{
			myNewArray[i]= backingArray[i];
		}
		//this is delete[], not delete
		delete[] backingArray;
		backingArray=myNewArray;*/ 
		}
}

template <class T>
T ArrayQueue<T>::remove(){
	if(numItems<1)
	{ //bad news!
	throw std::string("Queue is already empty, attempted to remove.");
	 }

	//make a new array, put in the new item
	T* myNewArray = new T[numItems];

	T retVal = backingArray[front];
	front = backingArray[(front+numItems)%backingArraySize];
	 for(unsigned int i=0; i<numItems; i++)
		{
			myNewArray[i] = backingArray[i+1];
		 }

	 delete[] backingArray;
	 backingArray = myNewArray;

  return retVal;

}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	//call this when you need more space (double size of array)
	//will make the array bigger
	//front + numItems is first available space
	//when near end of array (front+numItems)%backingArraySize

	//making array twice as long
	T* myNewArray = new T[START_SIZE*2];	

	//putting old elements into new array
	for(unsigned int i=0; i<numItems; i++)
	{
		myNewArray[i]= backingArray[i];
	}
	backingArraySize=START_SIZE*2;
	delete[] backingArray;
	backingArray=myNewArray;
}
