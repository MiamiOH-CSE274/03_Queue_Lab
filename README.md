Author
==========
"Harvey, Steven", harveysd
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

1. Works
2. Works
3. Works
4. Grow takes O(n) time because it doubles based on the numItems variable.
5. Works
6. Works
7. Works
8. This is a circular array, as the 'front' just circles from the back to the front of the array.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The only thing that really confused me about this exercise was the .ipp file. I think that the difference between .ipp and .h should be gone over before this assignment, and the reasoning behind using it should also be explained.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

#### 5. What is the purpose of "templates" in C++?

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

Class destructors clean up any memory space that we used for that object. We need them in c++ because the compiler doesn't keep track of what is and isn't being used any more. Java has built in garbage collecting that will clean objects up if they aren't used any more.
