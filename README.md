Author
==========
"Proctor, Patrick", proctopj
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

1. remove is functioning correctly in constant time.
2. add is functioning correctly in constant time.
3. grow is functioning as directed
4. grow takes linear time as directed
5. I'm 99% sure I am leaking no memory.
6. getNumItems is functioning correctly in constant time.
7. all thrown exceptions in add and remove occur as necessary.
8. I believe we have achieved circularity.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
We can keep all the methods, but the function of remove would have to now model the LIFO paradigm. All circular structure could otherwise remain.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
Be ready to wean yourself off of if-statements for mathematical navigation of your data structures. Also,

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
declare all portions of Queue to be virtual and then add #include <Queue.h>; to your ArrayQueue.h file, decalre all the variables from Queue.h, add unique elements, and implement 
those elements in ArrayQueue.ipp or ArrayQueue.cpp depending on your usage.

#### 5. What is the purpose of "templates" in C++?
They are like abstract classes or interfaces in Java. They provide the skeleton and/or meaning to a data structure as a parent or origin structure. They do not, however, 
show implementation.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
myArray = new int[10] or, for more specific multi-scope purposes, int* myArray = new int[] to be able to have an int (address of array) be passed from one method to another.

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The class destructor is necessary for manual garbage collection to prevent memory leakage. Java collects and deletes garbage on its own whereas C++ does not.