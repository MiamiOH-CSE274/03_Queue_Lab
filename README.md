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

1. Works! Remove() changes the front value to front+1 thereby removing the front value from the array.
2. Works! Add() adds the toAdd value to the end of the queue which is only one operation, thereby taking O(1) time.
3. Works! grow() is called when the numItems equals the size of the backingArray.
4. Grow() takes O(n) time because it must copy each element from the old array to the bigger array.
5. Works! The destructor uses delete[] to deallocate the memory used by the array and grow correctly deletes backingArray before becoming equal to the newly grown array.
6. Works! getNumItems() only has to return the value of a variable thereby taking O(1) time.
7. Works! 
8. Works! Makes proper use of the front variable and modulizes (is that a word?) with the backingArraySize.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

				We would want to keep the backingArraySize variable because we still need a way to keep track of the length of the array. The numItems variable is also still needed because we will need a way to record how many items are in the array. We will no longer need the front variable because the Stack data structure will always use Last-In-First-Out. We have no need of knowing where the front of the stack is because we will always remove the last item added. The grow() method is still needed because we will need to be able to change the size of the array if the number of items goes beyond the size of the array. And finally the backingArray is still needed to store our items in.
				
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

				Not a question but my biggest problem is knowing how to do something if we were working with Java but having no idea how to do the same thing in C++.
				
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

				To write class SOMETHING extends SOMETHING ELSE you use a ":". The colon does the same thing as the keyword "extends" does in Java in C++. So the above example would look like "class ArrayQueue : public Queue<T>".
				
#### 5. What is the purpose of "templates" in C++?

				Templates allow the programmer to make a data structure of an unspecified type. You can declare a variable that takes the place of the data type so that the type can be defined later during implementation of the template. You place the variable in any spot that normally would be used for declaration of a data type. When a data type is declared the compiler will replace the variable that was defined with the appropriate data type that you have chosen in every spot that the variable is in.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

				int* pointer = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

				The purpose of a class destructor is to free up resources (aka memory) that the object was using during its existence. This is not needed in Java because Java does not allow the programmer to fiddle with the memory directly like C++ does and more importantly Java has automatic garbage collection. 
