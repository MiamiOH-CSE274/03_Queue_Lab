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

1. remove() passes the tests but I am unsure about the O(1) operation time.
2. add() passes the tests but I am unsure about the O(1) operation time.

3. grow works because it passed the tests and is only called when numItems = backingArraySize because I coded it that way;

4. grow takes O(n) time because its operation time depends on the size of the set.

5. Any array I created with new was either erased with delete[] or was erased after the scope of its operation ended

6. getNumItems works and is a single operation that returns an integer.

7. When numItems = backingArraySize, add() calls the function grow(). When numItems < 1, remove() throws an exception

8. I am still unsure of the concept of circular fashion because I don't yet understand how it is condusive to an O(1)operation time. I tried to revise my add() and remove() functions
into a way that was "circular", or at least what I grasped of "circular" in class. However in each function I was unable to keep it circular without shifting the elements
in the array which requires a "for" loop, which to me, contradicts the idea of having an operation that stays consistent in timing regardless of the set size.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

	If we were to Implement a stack instead of a queue we would replace add() & remove() with push() and pop(). We would still need grow() and getNumItems() in addition to 
	the variables numItems and backingArraySize.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
	 I read on Stack Overflow that O(1) essentially means that an operation takes a consistent amount of time to complete, whereas O(n) means that the operation takes
	up time relative to the size of the set. If operations are happening in nano seconds, how to we determine if things are happening consistenly or relative to the size
	their set? I would assume you could determine it based on how you wrote the code. I'm pretty sure my add and remove functions take O(1) time but I am unsure about the functions in my code.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

		class ArrayQueue : public Queue <T> 

#### 5. What is the purpose of "templates" in C++?

	"Templates allow classes to have members that use template parameters as types."(cplusplus.com) From what I've gathered templates are used in C++ to organize objects.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

		backingArray = new T[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

	Class destructors are used to prevent memory leaks which are when the code can no longer access to a piece of allocated memory. Java doesn't use destructors because the JVM 
	is able to detect in the compiler when an object is no longer used.