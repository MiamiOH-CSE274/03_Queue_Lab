Author
==========
"Monnin, Sebastian", monninse
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

1. Remove() works successfully.
2. add() works successfully.
3. grow() works successfully.
4. grow() works successfully.
5. works successfully.
6. getNumItems() works successfully.
7. add and remove throw exceptions appropriately
8. works successfully.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
      Because stacks add and remove from the back we could get rid of the front variable.
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
        I felt like the actual directions of what to do was confusing. I would have mostly just liked to have gone over exactly what was expected of us in 
        this assignment
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
        class ArrayQueue:Queue , you use a : symbol
#### 5. What is the purpose of "templates" in C++?
        The purpose of templates in C++ is so that code is more generic. When you use templates you can come back through and use
        the code for many different objects
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
        int *aRay= new int[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
      a class destructor makes cleans up memory space by destroying unused items in memory. Java doesn't need them because they have
      the built in garbage collection
