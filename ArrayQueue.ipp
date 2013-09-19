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
    front = 0;
    numItems = 0;
    backingArraySize = START_SIZE;
    backingArray = new T[backingArraySize];
    
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
    //if the backing array is full, create a larger one and copy in the elements
    
    if(numItems == backingArraySize){
        grow();
        }

        backingArray[((front + numItems) % backingArraySize)] = toAdd;  //add toAdd at the next
        //available index
        
        numItems++;  //record that we have one more item in the array

}

template <class T>
T ArrayQueue<T>::remove(){

    if (numItems == 0) {
        throw std::string ("Cannot remove from an empty queue");
    }
                             
    T remove = backingArray[front];  //store value to return
    front = (front + 1) % backingArraySize;  //moves front up one index, or returns it to index 0 if
        //we have reached the end
    numItems--;  //record that we have one less item in the array

    return remove;
  
    }

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){

    return numItems;

}

template <class T>
void ArrayQueue<T>::grow(){
    
    T* backingArrayTemp = new T[2 * backingArraySize];
    if (backingArrayTemp == NULL)
        throw std::string("No more memory for queue");
    
    for (unsigned long i = 0; i < backingArraySize; i++) {
        backingArrayTemp[i+front] = backingArray[(i + front) % backingArraySize];
    }
    
    backingArraySize = backingArraySize * 2;
    
    delete[] backingArray;
    backingArray = backingArrayTemp;
    

}
