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

1. Remove takes O(1) time
2. Add is O(1) unless grow is called
3. Grow works as described and doubles array size.
4. Grow takes O(n) time.
5. Destructor code is from lecture so I it should work
6. getNumItems is O(1) time
7. Exceptions are thrown
8. Array is circular 

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
Everything but front should be kept. Stacks add to the front so having a variable for front is not needed. 

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
The whole idea of circular arrays was confusing at first. I think it should be covered in the beggining as it seems like the key to the whole lab.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
: is used in C++ to mean the same thing as extends. ArrayQueue : Queue would be the way to write it in C++.

#### 5. What is the purpose of "templates" in C++?
Templates don't require you to specify the variable type. So the user can use any variable and the program finds and replaces all generic variables with the type specified by the user.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
In C++ , int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The destructor is used to fix memory leaks and destroy objects in memory that are no longer in use. Java automatically frees up memory so delete and destructors aren't needed in Java.
