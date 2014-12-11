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

1. SUCCESS
2. SUCCESS
3. TODO
4. TODO
5. TODO
6. SUCCESS
7. SUCCESS
8. TODO

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer. 
  - We would need to modify the remove() method because the way we are taking objects out is opposite what we need to do in a Stack.  We wouldn't remove the front of the array, we would remove the front+numItems of the array.  We would still use front, numItems, and backingArraySize because we are able to reach the correct elements using those, specifically front+numItems to reach the last element of the stack and the first one to be taken off.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
  - Finding out how to make my grow method work was very difficult.  There wasn't any errors besides saying I was trying to put an int* into an int.  I don't really know the difference, and I'm pretty sure that wasn't even true so I'm not sure where that error was coming from.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
  - (Copied from the code) class ArrayQueue : public Queue <T>
  Basically, the ":" operator is shorthand in c++ for extends

#### 5. What is the purpose of "templates" in C++?
  - Templates basically make the program more versatile for other programs to use and for users.  It leaves some freedom in what type of object is going to be used in the file, and is finally decided when called by another file using the class name followed by <variable type you want>.  This takes some of the responsibility off the programmer (me) and lets the user decide what they need from my program.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
  - We can dynamically allocate space in memory for an array using this line of code:
  	int* myArray = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
  - In the words of Bo, "The people who made C++ are mean."  C++ doesn't know when to clear memory and delete an object when its scope has ended, so instead we have to do it manually.  At the end of an objects scope, the destructor is called, and the destructor deletes the object and clears its space in memory so that it can be used again.  It also helps with security, making sure that the object is not referenced when we no longer want it to be.