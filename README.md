Author
==========
"Mullins, Harrison", mullingh
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

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Working, was originally returning the new front variable but eventually understood to return the removed variable.
2. Working, my biggest issue was correctly initializing the array in the constructor to get this to work.
3. Working, if statements control the calling of the method and in grow I double both the new array's size and the backingArraySize variable.
4. Working, I'm unsure of how to calculate this exactly but I believe based on the example from the book it is  O(n) time.
5. Working, both the grow method and destructor call the delete[] operator.
6. Working, easiest method in the homework. (Which Dr. Brinkman was kind enough to give us)
7. I believe both are working. Remove definitely works, but for the add method I was unsure of what exactly to throw and when, and what exceptions to look for. But I believe both are technically working.
8. Working, based on the logic from the book and the fact that I had all successful tests I'm fairly certain this is correct.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
We could get rid of the front variable and backingArraySize variable, we would only need a variable to hold the number of items in the stack.  We need to keep the methods add, remove, and grow because we still need to be able to push to the stack, pop the stack, and resize the stack as needed. 
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
Most of my confusion from this exercise did not stem from the logic or difficulty of the problems; I spent most of my time figuring out C++ syntax and correcting syntactic issues.  The exceptions were a bit confusing and the grow() method was the most difficult.  As always the best advice is to start the homework early.
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
//#include "Queue.h"
//class ArrayQueue : public Queue <T> // These lines would be included in the ArrayQueue header file
#### 5. What is the purpose of "templates" in C++?
The purpose of templates in C++ is that we can use them to define a class without specifying the actual data type being used until later.  This allows us to use many different data types for the same class.
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* example = new int[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The purpose of a class destructor in C++ is to ensure that any dynamically allocated memory is de-allocated when it falls out of scope.  Meaning that if we have allocated memory during our programs, we need to be sure to free up that memory again after we are done using it or this could cause memory leak issues.  Java does not require destructors because the object data is allocated on the heap(Most the time I believe) and has its own "garbage collector" that cleans up any allocated memory.   
