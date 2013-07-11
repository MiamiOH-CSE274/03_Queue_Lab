Author
==========
Andy Shear, shearar
03_Queue_Lab
============

Implement an array-based queue in C++

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Remove works; creates a temporary object of type T that holds the item to be removed, incriments the front placeholder, reduces numitems by 1, then returns the value.  Each of these operations is done in constant time.
2. Add works; calculates where the back of the queue is, assigns the new value, then incriments numItems by 1.  These two operations take constant time.  If grow is called, all of its operations take constant time, besides the for loop, which is O(n) time as it loops through every item in the queue to copy it.
3. Grow works; it is called from the add method if numItems == backingArraySize, and creates a temporary array with size backingArraySize*2, copies over all the values, deletes the origional array, then re-assigns the origional pointer to the temp array.
4. Grow's operations all take constant time, besides the for loop, which is O(n) time as it loops through every item in the queue to copy it.
5. Grow and the destructor both delete[] backingArray, and grow reassigns the newly created tmp array back to backingArray after its been deleted.
6. getNumItems just returns numItems, which is constant time.
7. Add throws an out of memory exception if grow() is called and cannot create a new array. Remove throws the proper exception if it is called on an empty queue.
8. Array is circular.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

You could get rid of the front variable, just add items to the stack starting at the back.  All items will start at backingArraySize-1, and the index of the top of the stack will be kept by backingArraySize-1-numItems.  Items pushed or popped will be from this index, there is no use to create a circular stack, since it adds and removes from the same end.  Grow can simply be called once the backingArraySize-1-numItems = 0.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I found it hard to conceptualize how the circular queue should work, especially when removing or growing.  I suggest drawing all of the operations out first, step by step, so you can see how each performs with example data.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

class ArrayQueue : public Queue <T> {...}

#### 5. What is the purpose of "templates" in C++?

Allows for input data to be decided at runtime, its an open object container.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* arr = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

Java manages its own memory, so it does its own destructor behind the scenes.  In C++, the destructor is necessary to de-allocate memory when the object is destroyed or falls out of scope. You have to manage your own memory, the destrctor is there to delete anything the object dynamically created.