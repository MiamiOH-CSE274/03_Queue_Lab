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
7. add and remove throw exceptions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. The remove function works and returns the value that is no longer wanted in the ArrayQueue.
2. Adds a number to the ArrayQueue successfully and if needed will increase the size of the ArrayQueue.
3. The grow function doubles the ArrayQueue size and is only called in the add function if the number of items becomes too large.
4. Grow can be called by the add function or by itself to increase he Array Queue's size.
5. The destructor runs correctly and avoids memory leak and having a floating pointer after using the Array Queue.
6. getNumItems works to get the number of items being used in the Array Queue.
7. Remove throws an exception when trying to break program and add calls grow if the numItems gets too large.
8. The end of the array wraps around and the front variable manages the start of the array within a circular space.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

For a stack, we could keep the add, remove, grow, and destructor but would need to adjust for the way a stack manages data in a first in last out fashion.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

My advice would be to start the homeworks early so that you can edit code rather than starting from scratch and to use the reference very often so that you can easily learn syntax and how each object works in C++ as opposed to using knowledge from Java.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

In C++ you would use a colon to represent the statement "extends" in the declaration of your class ArrayQueue.

#### 5. What is the purpose of "templates" in C++?

Templates allow a single function to be used for different data types without rewriting the methods for each separate type.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* myNewArray = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

The class destructor will delete the object in a space in memory so that when a pointer is no longer used and deleted, there is not an object without a pointer in memory that is unaccessible.