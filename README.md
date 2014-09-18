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

1. works, the returned element is accessed by backingArray[front]. This function always takes the same amount of time.
2. works, add is accessed by backingArray[(front + numItems)] % backingArraySize
3. works, grow() is only called if numItems == the size of the array 
4. works. grow() runs at O(n) speed where n is the size of the array because grow() goes from 0 to backingArraySize.
5. works. the old array is delete[] when creating the new array that has double the size. The destructor for the class also works when called. 
6. works. getNumItems simply returns numItems without calculation.
7. works. the remove() method checks to make sure there are elements in the array when the method is called else it throws an exception. 
8. works. the array works in a circular fashion by using % backingArraySize.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

Keep:

backingArray,
grow(),
numItems,
backingArraySize

Get rid of:

front

Stack works very similar to Queue when it comes to working with arrays. A major difference between the two is that Stack is LIFO and Queue is FIFO. This is the reason why I would remove the front variable because we would no longer need to know the front of the array because it is always at backingArray[0] and the back of the Stack is located using numItems. We would still need the grow() function, the array, and the size of the array to make sure that there is space to store a new element. 

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I was slightly confused about the requirements at the top of the assignment and how to answer them. I think we need to go through what O(n) and O(1) mean in more detail.  

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

You would use a colon (:) to replace the word ‘extends’. Ex: class ArrayQueue : public Queue <T>.

#### 5. What is the purpose of "templates" in C++?

It allows programmers to write a program/interface without specifying a data type. This way the user can fill in the blanks when using the interface/program.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

You need a class destructor because C++ does not know when you are done with a class or an instance of that class. In Java the instance of the class would be automatically deleted once your program was done using it, in C++ the instance is kept until a destructor method is called. 
