Author
==========
"Blase, Douglas", blasedd
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

1. Remove() meets the requirement, because the operations do not depend on the amount of items in the queue.
2. Add() meets the requirement because the operation does not depend on the number of items in the queue, unless grow() is called.
3. Grow is only called inside an if statement to verify that the number of items will be equal to the size of the array after an item is added. Otherwise there is no way it can be called, so this meets the requirement.
4. The time requirement for grow is met because the number of operations will grow with the number of items that are in the queue.
5. Both the grow and destructor delete the backingArray with `delete[]`, so memory is not leaked.
6. getNumItems() only returns the value of getNumItems, which requires no calculations.
7. The remove method successfully throws a string exception, and the grow method should throw an exception if a new array could not be allocated in memory.
8. The array works in a circular fashion, courtesy of an if statement that moves the front variable to the first index of the backing array when it reaches the end.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

If we used a Stack instead of a Queue, the private variable `front` could be kept, but should be renamed to `end`, because the front of the array will never be needed. The `numItems` variable would not be needed because the `end` variable will keep track of this as well. `backingArraySize` would be kept so that we can track when the array would need to grow. `getNumItems()` would be more appropriately named `getEnd()`, and the `grow()` would be kept as well.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

I didn't clearly understand what it was we were exactly to be coding right away, and I had to read through the comments in the files a few times before it finally clicked. So maybe, make it a little clearer as to what we should be programming.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

To indicate that a class extends another class, you use the `:`.

#### 5. What is the purpose of "templates" in C++?

The purpose of a template is to create a class that can be of any type of data, and at compile time the class of that type is compiled.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

To dynamically allocate an array of 10 ints, you would type `int* nums = new int[10]`.

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

The purpose of a class destructor in C++ is to remove an instance of the class from memory. This isn't needed in Java because the Garbage Management will recognize that the class is no longer being referenced and free up the memory for the program to use.