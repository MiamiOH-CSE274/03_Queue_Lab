Author
==========
"Turner, Chace", turnerce
03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

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

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Remove should be working in O(1) time.  It goes through one iteration of operations to remove the front element, and change the variables accordingly
2. Add should be working in O(1) also.  It calls grow only if the array is full and needs more space
3. Grow appears to be called and working properly when called by add().
4. Grow iterates a for loop once for every element in the array.  Therefore it should be running in O(n).
5. Grow and the destructor delete the old array when it is replaced, respective to when it needs to be for each function.
6. getNumItems should be the most certain to operate in O(1).  It simply returns the value of one of our variables
7. Remove throws an exception if the array is empty, and add throws an exception through grow() if there is no memory space for the backing array size to be doubled.
8. The array operates in a circular fashion.  My using the modulus operator and finding the remainder of our number of items and the front element, we can find the next index to add elements to.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

If we were using a stack, we shouldn't have to keep track of the 'front' of the queue.  The array would fill from the beginning and any removed elements would be removed from the end.  This would also eliminate the need to use a circular array; we would just use grow to keep the backingArraySize large enough to keep adding items to the end.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

Make sure you know how to use your compiler well.  I am using Xcode and I think all my problems in executing the coding came from things I didn't understand about Xcode.  It makes for hard debugging as well as uncertainty about why your program isn't working.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

Here is that line from our ArrayQueue.h file "class ArrayQueue : public Queue <T>".

#### 5. What is the purpose of "templates" in C++?

Templates are used so we can use the same structure for different data types.  Without them we would have to change our implementation.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

We would type "int* array = new int[10];"

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

The class destructor deletes the instance of all data used for a class object.  We don't need them in Java because the JVM controls the data management, where in C++ we have to make sure to un-allocate data when we're done with it to prevent data leaks.