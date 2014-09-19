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

1. Working - Removes 1 off queue.
2. Working - Adds 1 and only calls grow if no room.
3. Working - Array is doubled during grow.
4. Working - 
5. Working - 
6. Working - Returns number of items.
7. Working - Remove throws exception if removing from empty queue.
8. Working - Array continues over to first spot if it hits the end of the array.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

We would need to keep push and pop. We only need those two because everything else a stack does like size and empty can be accomplished without using those functions. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

When debugging the grow method, don't be afraid to use print statements to help see what you are copying from one array to another.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

You create a class "Queue" that declares the methods to use and then define those methods in another class "ArrayQueue".

#### 5. What is the purpose of "templates" in C++?

They allow the user of the program to define something that the programmer has intentionally left ambiguous. 

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* intArray = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

In java, once something has gone out of scope and can no longer be reached, the object is destroyed and memory can be used for something else.  In C++, when something goes out of scope, it can still be reached because you can access memory directly.  In order to free up memory to be used by something else, you must delete objects you create.
