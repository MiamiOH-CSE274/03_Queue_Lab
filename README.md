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

1. This function takes O(1) time because the operation works on the head of the list, which is directly proportional to the number of elements in the queue, n.
2. The add function also takes O(1) time (without a call to grow) because it works on the back of the list where adding an element to a space is proportional to the number of elements in the array, only this time it adds an element in the back instead of taking it off upfront.
3. I have programmed the grow function to first check if numItems equals backingArraySize, and then the backing Array is double by assigning it to an array twice its size. 
4. Grow takes O(n) time because it depends on how many elements are in the array. The more elements need to copy over, the run time will proportionally grow as well.
5. All destructors have been called at the end of each function so that the previous memory allocated to backingArray has been freed up and an assignment has it pointed to the copy array that was created in each function.
6. getNumItems takes O(1) time because it is directly proportional to the number of elements in the array.
7. Exceptions are thrown when remove is called on an empty array.
8. The array works in a circular fashion (due to reading the Open Data Structures book). I tried to do this on my own and ran into a quite a few problems, so I used parts in the book for help. After reading through the section, the loops of the circular array make sense to me now.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
	When implementing a stack instead of a queue, we could use most of the private methods and variables that we first declared because the only difference between the two structures is that
	the stack is LIFO and the queue is FIFO. The only variable I think we could safley get rid of would be the varibale "long front" because the stack operates in the back of the array and 
	does not need to know where the front is (the front stays constant).

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
	One question I have about this exercise is how to keep track of the size of the array (not the number of elements inside the array, but the actual array size itself). For one method, I 
	used b.size(), though when using that same array function inside of a different function, an error was thrown. I am sure that there is a technical explanation for this, but it also might be
	the case that I just have to hard code a new method for getting the size of the array.
	EDIT: Found out that one cannot use normal api methods on pointers, so I utilized the backingArraySize variable like we were originally supposed to.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
	To write this, you just have to code 
	class ArrayQueue : public Queue <T> {...}

#### 5. What is the purpose of "templates" in C++?
	The purpose of using template classes originates in that c++ does not support interfaces, so a data structure is made in a .h file. To use that data structure, one can build a header file
	for a matching c++ class that uses the data structure, but the .cpp file will not know what type <T> is. Therefore, the source code must be compiled in the header file so that an actual
	.cpp file can use the template class with a valid variable type. 

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
	int* myArray = new int[10];
	
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
	The purpose of a class destructor is to free up dynamically allocated memory that had previously been assigned to a different variable. For example, after a variable has lasted its use, the
	delete keyword can be used to free up the memory for different usage. We do not need this in Java because the Java Virtual Machine automatically detects when a variable has no more use and 
	runs garbage collection to clean it up.
