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

1. Remove works correctly, returning the value that is specified.
2. Add works the right way, adding to the array.
3. TODO
4. TODO
5. TODO
6. TODO
7. TODO
8. TODO

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

	I would suggest to take some time to understand how to make the conversion between the Java syntax, which we already know, to C++. It can be confusing, but all the same general logic is there. It's just different typing.

4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

	If you wanted to do this in C++, you would put a ":" when you declare the ArrayQueue class.

5. What is the purpose of "templates" in C++?

	A template allows you to use the same functions with different types of data.

6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
	int* anArrayOfAwesomeness = new int [10];

7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

	The purpose of the destructor is to free up the memory that has been allocated for the object. Java doesn't need this because you do not allocate memory, and thus are not required to free any up.
