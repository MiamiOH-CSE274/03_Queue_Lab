nclude <string>
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

    
    front=0;
    numItems=0;
    //was having problems getting it to compile so looked at https://github.com/stilgeki/03_Queue_Lab/blob/stilgeki/ArrayQueue.ipp
    //backingArray is already declared so i didn't need T backingArray = new T[START_SIZE]
    //which was the problem.

    backingArray = new T[START_SIZE];
    backingArraySize = START_SIZE;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
     while (numItems>0) {
remove ();
    }
    delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
    if (numItems == backingArraySize) {
        grow();
    }

   
    backingArray[(front+numItems)%backingArraySize]=toAdd;
  // toAdd= backingArray[front +numItems] % backingArraySize;
    numItems++;

}

template <class T>
T ArrayQueue<T>::remove(){
//did in class
//looked at https://github.com/MiamiOH-CSE274/03_Queue_Lab/blob/luoy6/ArrayQueue.ipp when my 
// throw string seemed to not be working, but because i wasn't done with the grow function
//it was working and the code just wasn't reaching it,
//so the code is what we did in class.

 if (numItems==0) {
    throw (std::string) "Array is empty";
    
  }

  T removedItem = backingArray[front];
  front = (front+1)%backingArraySize;
  numItems--;
  return removedItem;

}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
    return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
    //looked at https://github.com/MiamiOH-CSE274/03_Queue_Lab/blob/luoy6/ArrayQueue.ipp
    //was initializing new array with "T[] newArray"... C++ uses T* duh.

    T* newArray = new T[backingArraySize*2];
    for (int i = 0; i < numItems; i++)
    newArray[i] = backingArray[(front+i)%backingArraySize];
    delete[] backingArray;
    backingArray = newArray;
    front = 0;
    backingArraySize = backingArraySize*2;
}

