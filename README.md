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

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Remove should work correctly.
2. add should work correctly.
3. grow should only be called if it needs to be called.
4. grow should take the proper amount of time to double its size.
5. the destructor should delete the old data properly.
6. getNumItems should work correctly
7. Exceptions are caught in the code as shown in the testRemoveException code.
8. Subtracting from the array seems to be causing problems for the array

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
For a stack we would need to change the remove method to draw from the top and become LIFO instead of FIFO. everything else we would be able to keep.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
My greatest difficulty resides in fixing my remove method.
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
class ArrayQueue : Queue<T>
#### 5. What is the purpose of "templates" in C++?
the purpose of templates in C++ is to be able to use different data types to use the same methods despite having different starting data types.
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* tenInts = new in[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
the purpose of a deconstructor is to reallocate data that isnt going to be used anymore. Java doesnt need this because it has an automatic 'garbage collector' that does this job automaticly.